#include "coap.hpp"

namespace coap {

Coap::Coap(std::uint8_t data) {}

Coap::Coap(std::uint8_t data, Header header) {}

Coap& Coap::token(Token value) {
  /**
   * - Write length to header.
   * - Write token to data.
   */
  return *this;
}

Coap& Coap::option() { return *this; }
Coap& Coap::payload() { return *this; }

}  // namespace coap
