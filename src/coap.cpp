#include "coap.hpp"

namespace coap {

Coap::Coap(std::uint8_t data) {}

Coap::Coap(std::uint8_t data, Type type, Code code, std::uint8_t message_id) {}

Coap& Coap::token() { return *this; }
Coap& Coap::option() { return *this; }
Coap& Coap::payload() { return *this; }

}  // namespace coap
