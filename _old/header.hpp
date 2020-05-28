#pragma once

#include <array>
#include <cstdint>

#include "code.hpp"
#include "section.hpp"
#include "type.hpp"

namespace sdk::models::coap::message {

/**
 * Implements CoAP message codes as described in RFC 7252 §3.
 * https://tools.ietf.org/html/rfc7252#section-3
 */
class Header : public sdk::models::coap::message::Section {
 public:
  using VersionType = std::uint8_t;

  using TokenLengthType = std::uint8_t;

  using MessageIdType = std::uint16_t;

  using Value = struct Value {
    sdk::models::coap::message::Type type;
    TokenLengthType token_length;
    sdk::models::coap::message::Code code;
    MessageIdType message_id;
  };

  static sdk::models::coap::message::Section::LengthType const kLength = 4;

  Header(sdk::models::coap::message::Section const& section);

  Header(sdk::models::coap::message::Section const& section, Value header);

  VersionType Version() const;

  sdk::models::coap::message::Type Type() const;

  TokenLengthType TokenLength() const;

  sdk::models::coap::message::Code Code() const;

  MessageIdType MessageId() const;

 private:
  // RFC 7252 §3, Figure 7.
  union ValueFields {
    std::array<sdk::models::coap::message::Section::Element, 4> fields;

    struct {
      MessageIdType message_id : 16;
      sdk::models::coap::message::Code::Value code : 8;
      TokenLengthType token_length : 4;
      sdk::models::coap::message::Type::Value type : 2;
      VersionType version : 2;
    };
  };

  void ValidateLength() const final;

  void SetDefaults();

  void Read();

  void Write();

  ValueFields _header;
};

}  // namespace sdk::models::coap::message
