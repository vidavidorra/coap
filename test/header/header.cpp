#include "header.hpp"

#include <string>

#include "catch2/catch.hpp"
#include "test-data.hpp"

namespace coap::test {

std::string const kTestGroup("Header ");
std::string const kTags("[header]");

// DUT (device under test).
using Header = coap::Header;

TEST_CASE(kTestGroup + "correctly parses header", kTags) {
  SECTION("from Type") {
    for (auto const& e : kTestValues) {
      const Header kHeader(e.header.type);

      REQUIRE(static_cast<Header::Type>(kHeader) == e.header.type);
    }
  }

  SECTION("from Value") {
    for (auto const& e : kTestValues) {
      const Header kHeader(e.header.value.type, e.header.value.code,
                           e.header.value.message_id);
      REQUIRE(static_cast<Header::Type>(kHeader) == e.header.type);
    }
  }
}

}  // namespace coap::test
