#include "token.hpp"

#include <algorithm>
#include <cstdio>

namespace coap {

bool Token::Value::operator==(Value const& other) const {
  return size == other.size && data == other.data;
}

Token::Token(Value value) noexcept : _value({{}, 0}) {
  _value.size = value.size;
  std::copy(value.data.begin(), value.data.begin() + value.size,
            _value.data.begin());
}

Token::Token(VectorValue value) noexcept : _value({{}, 0}) {
  _value.size =
      std::min(value.size(), static_cast<std::size_t>(Length::kMaximum));
  std::copy(value.begin(), value.begin() + _value.size, _value.data.begin());
}

}  // namespace coap
