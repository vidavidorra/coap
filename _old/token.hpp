#pragma once

#include "section.hpp"

namespace sdk::models::coap::message {

/**
 * Implements CoAP message token as described in RFC 7252 §3.
 * https://tools.ietf.org/html/rfc7252#section-3
 */
class Token : public sdk::models::coap::message::Section {
 public:
  using Value = sdk::models::coap::message::Section::Data;

  static sdk::models::coap::message::Section::LengthType const kMaximumLength =
      8;

  Token(sdk::models::coap::message::Section const& section);

  Token(sdk::models::coap::message::Section const& section, Value const& token);

  operator Value() const;

 private:
  void ValidateLength() const final;
};

}  // namespace sdk::models::coap::message
