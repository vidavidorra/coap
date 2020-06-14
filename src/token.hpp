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
  enum {
    kMinimumLength = 0,  // Zero length is effectively the same as no token.
    kMaximumLength = 8,
  };

  using Length = std::uint8_t;

  using Data =
      std::array<coap::Element, static_cast<std::size_t>(kMaximumLength)>;

  struct Value {
    std::array<coap::Element, static_cast<std::size_t>(kMaximumLength)> data;
    Length length;

    bool operator==(Value const& other) const;
  };

  using Vector = std::vector<coap::Element>;

  Token(Value value) noexcept;

  Token(Vector value) noexcept;

  operator Value() const noexcept;

  operator Vector() const noexcept;

 private:
  Value _value;
};

}  // namespace coap
