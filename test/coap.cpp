#include "coap.hpp"

#include "catch2/catch.hpp"

namespace coap::test {

std::string const kTestGroup("CoAP ");
std::string const kTags("[coap]");

// DUT (device under test).
using Coap = coap::Coap;

TEST_CASE(kTestGroup + "correctly parses code", kTags) {
  Coap coap(20);
  coap.option().payload().token();

  Coap coap2(20, coap::Header(coap::Type::Value::kConfirmable,
                              coap::Code::Value::kPost, 123));
  coap2.option().payload().token();
}

}  // namespace coap::test
