#include "header.hpp"

#include <algorithm>

namespace coap {

/**
 * As described in RFC 7252 §3, the token length is represented by four bits and
 * has a maximum value of eight.
 * - https://tools.ietf.org/html/rfc7252#section-3
 */
Header::Header(Type value) noexcept
    : _kTokenLengthBitMask(0x0f), _kTokenLengthMax(8) {
  _value.fields = value;
  std::reverse(_value.fields.begin(), _value.fields.end());
}

Header::Header(coap::Type::Value type, coap::Code::Value code,
               MessageIdType message_id) noexcept
    : _kTokenLengthBitMask(0x0f), _kTokenLengthMax(8) {
  SetDefaults();

  _value.value.type = type;
  _value.value.code = code;
  _value.value.message_id = message_id;
}

Header::operator Type() const noexcept {
  auto value = _value.fields;
  std::reverse(value.begin(), value.end());
  return value;
}

Header::operator Value() const noexcept { return _value.value; }

bool Header::TokenLength(TokenLengthType token_length) noexcept {
  if (token_length <= _kTokenLengthMax) {
    _value.value.token_length = token_length & _kTokenLengthBitMask;
  }

  return false;
}

bool Header::VersionIsValid() const noexcept {
  return _value.value.version == 1;
}

bool Header::ContainsFormatError() const noexcept {
  return _value.value.token_length > _kTokenLengthMax;
}

bool Header::IsValid() const noexcept {
  return VersionIsValid() && !ContainsFormatError();
}

void Header::SetDefaults() noexcept {
  /**
   * RFC 7252 §3: Implementations of this specification MUST set this field to 1
   * (01 binary). Other values are reserved for future versions.
   * - https://tools.ietf.org/html/rfc7252#section-3
   */
  _value.value.version = 1;
  _value.value.type = coap::Type::Value::kConfirmable;
  _value.value.token_length = 0;
  _value.value.code = coap::Code::Value::kEmpty;
  _value.value.message_id = 0;
}

}  // namespace coap
