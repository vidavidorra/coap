#include "header.hpp"

#include "catch2/catch.hpp"
#include "code.hpp"
#include "test/header/test_vector.hpp"
#include "test/helpers/catch_matchers.hpp"
#include "type.hpp"

namespace sdk::test::models::coap::message::header {

std::string const kTestGroup("CoAP message header ");
std::string const kTags("[models][coap][message]");

// DUT (device under test).
using Header = sdk::models::coap::message::Header;

TEST_CASE(kTestGroup + "correctly parses header", kTags) {
  for (auto const& e : sdk::test::models::coap::message::header::kTestValues) {
    auto test_value = e;
    auto const kHeader = Header(test_value.header);
    REQUIRE(kHeader.Version() == 1);
    REQUIRE(kHeader.Type() ==
            static_cast<sdk::models::coap::message::Type::Types>(e.value.type));
    REQUIRE(kHeader.TokenLength() == e.value.token_length);
    REQUIRE(kHeader.Code() ==
            static_cast<sdk::models::coap::message::Code::Codes>(e.value.code));
    REQUIRE(kHeader.MessageId() == e.value.message_id);
  }
}

TEST_CASE(kTestGroup + "correctly creates header", kTags) {
  for (auto const& e : sdk::test::models::coap::message::header::kTestValues) {
    sdk::models::coap::message::Section::Data data(Header::kLength);
    Header(data, e.value);

    REQUIRE(data == e.header);
  }
}

TEST_CASE(kTestGroup + "constructor throws for invalid length", kTags) {
  auto const kMessage = "Section length is invalid";
  using Exception = std::invalid_argument;

  SECTION("section length too short") {
    sdk::models::coap::message::Section::Data data(Header::kLength - 1, 0);
    REQUIRE_THROWS_MATCHES(
        Header(data), Exception,
        sdk::test::helpers::MatcherStartsWith<Exception>(kMessage));
  }

  SECTION("section length too long") {
    sdk::models::coap::message::Section::Data data(Header::kLength + 1, 0);
    REQUIRE_THROWS_MATCHES(
        Header(data), Exception,
        sdk::test::helpers::MatcherStartsWith<Exception>(kMessage));
  }
}

}  // namespace sdk::test::models::coap::message::header
