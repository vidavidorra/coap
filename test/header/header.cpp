#include "header.hpp"

#include <string>

#include "catch2/catch.hpp"

namespace coap::test {

std::string const kTestGroup("Header ");
std::string const kTags("[header]");

// DUT (device under test).
using Header = coap::Header;

TEST_CASE(kTestGroup + "correctly parses code", kTags) {
  Header header(coap::Type::Value::kConfirmable, coap::Code::Value::kEmpty,
                123);
}

}  // namespace coap::test
