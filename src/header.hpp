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
   *
   * This structure can be represented by 32-bits, where the rightmost byte
   * represents a part of the message ID and the leftmost byte represents o.a.
   * the version. The fields, and which bits they're represented by, are shown
   * in the table below.
   *
   * | bits  | 32:30   | 30:28 | 28:24        | 24:16 | 16:0       |
   * | ----- | ------- | ----- | ------------ | ----- | ---------- |
   * | field | version | type  | token length | code  | message ID |
   */
  using Value = struct {
    MessageIdType message_id;
    coap::Code::Value code;
    TokenLengthType token_length : 4;
    coap::Type::Value type : 2;
    VersionType version : 2;
  };

  const TokenLengthType kMaximumTokenLength;

  Header(Type value) noexcept;

  Header(coap::Type::Value type, coap::Code::Value code,
         MessageIdType message_id) noexcept;

  operator Type() const noexcept;

  operator Value() const noexcept;

  /**
   * The token length is represented by four bits. Therefore, values of nine or
   * larger are ignored and are marked as an invalid input.
   *
   * @return true if the token length was valid, false otherwise.
   */
  bool TokenLength(TokenLengthType token_length) noexcept;

  bool VersionIsValid() const noexcept;

  bool ContainsFormatError() const noexcept;

  bool IsValid() const noexcept;

 private:
  /**
   * In this representation of the values, the first field of the array needs to
   * be the leftmost byte. The first field of an array becomes the rightmost
   * byte, so the order needs to be reversed in order to represent the value.
   */
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
