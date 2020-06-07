#include "token.hpp"

#include <string>
#include <vector>

#include "catch2/catch.hpp"
#include "test/helpers/catch_matchers.hpp"

namespace sdk::test::models::coap::message {

std::string const kTestGroup("CoAP message type ");
std::string const kTags("[models][coap][message]");

// DUT (device under test).
using Token = sdk::models::coap::message::Token;

using DefaultTestValue = Token::Value;

std::vector<DefaultTestValue> const kDefaultTestValues = {
    {},
    {0x00},
    {0x01},
    {0x7f},
    {0xfe},
    {0xff},
    {0x00, 0x00},
    {0x01, 0x01},
    {0x7f, 0x7f},
    {0xfe, 0xfe},
    {0xff, 0xff},
    {0x00, 0x00, 0x00},
    {0x01, 0x01, 0x01},
    {0x7f, 0x7f, 0x7f},
    {0xfe, 0xfe, 0xfe},
    {0xff, 0xff, 0xff},
    {0x00, 0x00, 0x00, 0x00},
    {0x01, 0x01, 0x01, 0x01},
    {0x7f, 0x7f, 0x7f, 0x7f},
    {0xfe, 0xfe, 0xfe, 0xfe},
    {0xff, 0xff, 0xff, 0xff},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x01, 0x01, 0x01, 0x01, 0x01},
    {0x7f, 0x7f, 0x7f, 0x7f, 0x7f},
    {0xfe, 0xfe, 0xfe, 0xfe, 0xfe},
    {0xff, 0xff, 0xff, 0xff, 0xff},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
    {0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f},
    {0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe},
    {0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
    {0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f},
    {0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe},
    {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
};

TEST_CASE(kTestGroup + "correctly parses tokens", kTags) {
  for (auto const& e : kDefaultTestValues) {
    auto test_value = e;
    auto const kToken = Token(test_value);
    REQUIRE(static_cast<Token::Value>(kToken) == e);
  }
}

TEST_CASE(kTestGroup + "correctly sets tokens", kTags) {
  for (auto const& e : kDefaultTestValues) {
    auto data = Token::Value(e.size(), 0);
    Token(data, e);
    REQUIRE(data == e);
  }
}

TEST_CASE(kTestGroup + "constructor throws for invalid length", kTags) {
  auto const kMessage = "Section length is invalid";
  using Exception = std::invalid_argument;

  SECTION("section length too long") {
    auto const kLength = Token::kMaximumLength + 1;
    auto data = Token::Value(kLength, 0);
    auto const kToken = Token::Value(kLength, 0);

    REQUIRE_THROWS_MATCHES(
        Token(data), Exception,
        sdk::test::helpers::MatcherStartsWith<Exception>(kMessage));
    REQUIRE_THROWS_MATCHES(
        Token(data, kToken), Exception,
        sdk::test::helpers::MatcherStartsWith<Exception>(kMessage));
  }

  SECTION("section length not matching token length") {
    auto const kLength = Token::kMaximumLength;
    auto data = Token::Value(kLength, 0);
    auto const kToken = Token::Value(kLength - 1, 0);

    REQUIRE_THROWS_MATCHES(
        Token(data, kToken), Exception,
        sdk::test::helpers::MatcherStartsWith<Exception>(kMessage));
  }
}

}  // namespace sdk::test::models::coap::message
