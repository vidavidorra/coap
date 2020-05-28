#pragma once

#include <array>
#include <cstdint>

#include "section.hpp"

namespace sdk::models::coap::message::option {

/**
 * Implements CoAP message option format as described in RFC 7252 §3.1.
 * https://tools.ietf.org/html/rfc7252#section-3.1
 */
class Format : public sdk::models::coap::message::Section {
 public:
  using ValueElement = std::uint16_t;

  using Value = struct Value {
    ValueElement delta;
    ValueElement length;

    bool operator==(Value const& other) const {
      return other.delta == delta && other.length == length;
    }
  };

  static sdk::models::coap::message::Section::LengthType const kLength = 5;

  Format(sdk::models::coap::message::Section const& section);

  Format(sdk::models::coap::message::Section const& section, Value format);

  operator Value() const;

  sdk::models::coap::message::Section::LengthType SectionLength() const;

 private:
  using Element = sdk::models::coap::message::Section::Element;

  using HeaderFields = union HeaderFields {
    Element value;

    struct {
      Element length : 4;
      Element delta : 4;
    };
  };

  using ValueFieldss = union ValueFieldss {
    ValueElement value;
    std::array<Element, 2> bytes;
  };

  using Extension = struct Extension {
    Element header_value;
    ValueElement maximum_value;
    Element bytes;
    ValueElement offset;
  };

  void ValidateLength() const final;

  void Read();

  void Write();

  ValueElement ReadValue(Element header);

  Element WriteValue(ValueElement value);

  std::array<Extension, 2> const _kExtensions;
  sdk::models::coap::message::Section::Iterator _it;
  Value _format;
};

}  // namespace sdk::models::coap::message::option
