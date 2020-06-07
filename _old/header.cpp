#include "header.hpp"

#include <stdexcept>
#include <string>

namespace sdk::models::coap::message {

Header::Header(sdk::models::coap::message::Section const& section)
    : sdk::models::coap::message::Section(section) {
  ValidateLength();

  Read();
}

Header::Header(sdk::models::coap::message::Section const& section, Value header)
    : sdk::models::coap::message::Section(section) {
  ValidateLength();

  SetDefaults();
  _header.type = header.type;
  _header.token_length = header.token_length;
  _header.code = header.code;
  _header.message_id = header.message_id;
  Write();
}

Header::VersionType Header::Version() const { return _header.version; }

sdk::models::coap::message::Type Header::Type() const {
  return sdk::models::coap::message::Type(_header.type);
}

Header::TokenLengthType Header::TokenLength() const {
  return _header.token_length;
}

sdk::models::coap::message::Code Header::Code() const {
  return sdk::models::coap::message::Code(_header.code);
}

Header::MessageIdType Header::MessageId() const { return _header.message_id; }

void Header::ValidateLength() const {
  if (!LengthEquals(kLength)) {
    throw std::invalid_argument("Section length is invalid - " +
                                std::to_string(SectionLength()));
  }
}

void Header::SetDefaults() {
  /**
   * RFC 7252 §3: Implementations of this specification MUST set this field to 1
   * (01 binary).
   */
  _header.version = 1;
  _header.type = 0;
  _header.token_length = 0;
  _header.code = 0;
  _header.message_id = 0;
}

void Header::Read() {
  for (auto it = Begin(); it != End(); ++it) {
    _header.fields.at(End() - it - 1) = *it;
  }
}

void Header::Write() {
  for (auto it = Begin(); it != End(); ++it) {
    *it = _header.fields.at(End() - it - 1);
  }
}

}  // namespace sdk::models::coap::message
