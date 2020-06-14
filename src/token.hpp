#pragma once

#include <array>
#include <cstdint>
#include <vector>

#include "section.hpp"

namespace coap {

/**
 * Implements CoAP message token as described in RFC 7252 §3.
 * - https://tools.ietf.org/html/rfc7252#section-3
 */
class Token {
 public:
  using Size = std::uint8_t;

  enum class Length : Size {
    kMinimum = 0,  // Zero length is effectively the same as no token.
    kMaximum = 8,
  };

  using Data =
      std::array<coap::Element, static_cast<std::size_t>(Length::kMaximum)>;

  struct Value {
    std::array<coap::Element, static_cast<std::size_t>(Length::kMaximum)> data;
    Size size;

    bool operator==(Value const& other) const;
  };

  using VectorValue = std::vector<coap::Element>;

  Token(Value value) noexcept;

  Token(VectorValue value) noexcept;

  Size length() const noexcept { return _value.size; }

  operator Value() const noexcept { return _value; }

  operator VectorValue() const noexcept {
    return {_value.data.begin(), _value.data.begin() + _value.size};
  }

 private:
  Value _value;
};

}  // namespace coap
