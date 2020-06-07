#include "option/format.hpp"

namespace sdk::models::coap::message::option {

Format::Format(sdk::models::coap::message::Section const& section)
    : sdk::models::coap::message::Section(section),
      _kExtensions({Extension{13, 268, 1, 13}, Extension{14, 65535, 2, 269}}),
      _it(Begin()),
      _format({0}) {
  ValidateLength();
  Read();
}

Format::Format(sdk::models::coap::message::Section const& section, Value format)
    : sdk::models::coap::message::Section(section),
      _kExtensions({Extension{13, 268, 1, 13}, Extension{14, 65535, 2, 269}}),
      _it(Begin()),
      _format(format) {
  ValidateLength();

  Write();
}

Format::operator Value() const { return _format; }

sdk::models::coap::message::Section::LengthType Format::SectionLength() const {
  return _it - Begin();
}

void Format::ValidateLength() const {
  if (!LengthEquals(kLength)) {
    throw std::invalid_argument("Section length is invalid - " +
                                std::to_string(SectionLength()));
  }
}

void Format::Read() {
  HeaderFields header{0};
  header.value = *_it++;

  // @todo If `_format.header.value == kPayloadMarker` we need to stop.

  _format.delta = ReadValue(header.delta);
  _format.length = ReadValue(header.length);
}

void Format::Write() {
  /**
   * Increment for the 'header' byte as that will be written after writing the
   * formats. This increment is required because writing of the format may need
   * to write the following bytes as extended format bytes.
   */
  _it++;

  HeaderFields header{0};
  header.delta = WriteValue(_format.delta);
  header.length = WriteValue(_format.length);

  *Begin() = header.value;
}

Format::ValueElement Format::ReadValue(Element header) {
  ValueFieldss fields{0};
  fields.value = header;

  for (auto const& extension : _kExtensions) {
    if (fields.value == extension.header_value) {
      for (auto i = extension.bytes; i > 0; i--) {
        fields.bytes.at(i - 1) = *_it++;
      }

      fields.value += extension.offset;

      break;
    }
  }

  return fields.value;
}

Format::Element Format::WriteValue(ValueElement value) {
  ValueFieldss fields{0};
  fields.value = value;

  Element header = 0;

  if (value < _kExtensions.at(0).offset) {
    header = fields.value;
  } else {
    for (auto const& extension : _kExtensions) {
      if (fields.value <= extension.maximum_value) {
        header = extension.header_value;
        fields.value -= extension.offset;

        for (auto i = extension.bytes; i > 0; i--) {
          *_it++ = fields.bytes.at(i - 1);
        }

        break;
      }
    }
  }

  return header;
}

}  // namespace sdk::models::coap::message::option
