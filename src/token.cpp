#include "token.hpp"

#include <algorithm>

namespace coap {

bool Token::Value::operator==(Value const& other) const {
  return length == other.length && data == other.data;
}

Token::Token(Value value) noexcept : _value({{}, 0}) {
  _value.length = value.length;
  std::copy(value.data.begin(), value.data.begin() + value.length,
            _value.data.begin());
}

Token::Token(Vector value) noexcept : _value({{}, 0}) {
  _value.length =
      std::min(value.size(), static_cast<std::size_t>(kMaximumLength));
  std::copy(value.begin(), value.begin() + _value.length, _value.data.begin());
}

Token::operator Value() const noexcept { return _value; }

Token::operator Vector() const noexcept {
  return {_value.data.begin(), _value.data.begin() + _value.length};
}

}  // namespace coap
