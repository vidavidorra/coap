#include "coap.hpp"

namespace coap {

Coap::Coap() {}

Coap::Coap& Coap::token() { return *this; }
Coap::Coap& Coap::option() { return *this; }
Coap::Coap& Coap::payload() { return *this; }

}  // namespace coap
