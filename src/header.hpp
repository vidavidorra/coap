#pragma once

#include <array>
#include <cstdint>

#include "code.hpp"
#include "type.hpp"

namespace coap {

/**
 * Implements CoAP message header as described in RFC 7252 §3.
 * - https://tools.ietf.org/html/rfc7252#section-3
 */
class Header {
 public:
  using Type = std::array<std::uint8_t, 4>;

  using VersionType = std::uint8_t;

  using TokenLengthType = std::uint8_t;

  using MessageIdType = std::uint16_t;

  /**
   * Header construction as described in RFC 7252 §3, Figure 7.
   * - https://tools.ietf.org/html/rfc7252#section-3
   */
  using Value = struct {
    MessageIdType message_id;
    coap::Code::Value code;
    TokenLengthType token_length : 4;
    coap::Type::Value type : 2;
    VersionType version : 2;
  };

  Header(Type value) noexcept;

  Header(coap::Type::Value type, coap::Code::Value code,
         MessageIdType message_id) noexcept;

  operator Type() const noexcept;

  operator Value() const noexcept;

  /**
   * The token length is represented by four bits. For values larger than those
   * that can be represented by four bits, so zero up to and including fifteen,
   * the other bits are ignored.
   *
   * @return true if the token length was valid, false otherwise.
   */
  bool TokenLength(TokenLengthType token_length) noexcept;

  bool VersionIsValid() const noexcept;

  bool ContainsFormatError() const noexcept;

  bool IsValid() const noexcept;

 private:
  union ValueFields {
    Type fields;
    Value value;
  };

  void SetDefaults() noexcept;

  TokenLengthType const _kTokenLengthBitMask;
  TokenLengthType const _kTokenLengthMax;
  ValueFields _value;
};

}  // namespace coap
