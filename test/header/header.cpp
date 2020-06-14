#include "header.hpp"

#include <cstdio>
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
      Header header(e.header.value.type, e.header.value.code,
                    e.header.value.message_id);
      /**
       * To be able to compare the header to the expected value, the token
       * length needs to be configured as it's part of the header. This
       * unfortunately means that this function is also included in this tests.
       */
      if (e.header.value.token_length != 0) {
        header.TokenLength(e.header.value.token_length);
      }

      REQUIRE(static_cast<Header::Type>(header) == e.header.type);
    }
  }
}

TEST_CASE(kTestGroup + "operator Type() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    const Header kHeader(e.header.type);

    REQUIRE(static_cast<Header::Type>(kHeader) == e.header.type);
  }
}

TEST_CASE(kTestGroup + "operator Value() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    const Header kHeader(e.header.type);

    const Header::Value kValue = kHeader;
    REQUIRE(kValue.message_id == e.header.value.message_id);
    REQUIRE(kValue.code == e.header.value.code);
    REQUIRE(kValue.token_length == e.header.value.token_length);
    REQUIRE(kValue.type == e.header.value.type);
    REQUIRE(kValue.version == e.header.value.version);
  }
}

TEST_CASE(kTestGroup + "TokenLength() correctly sets the token length", kTags) {
  Header header(Type::Value::kConfirmable, Code::Value::k000, 0x55aa);

  for (coap::Token::Length length = 0; length <= coap::Token::kMaximumLength;
       length++) {
    REQUIRE(header.TokenLength(length) == true);
    REQUIRE(static_cast<Header::Value>(header).token_length == length);
  }
}

TEST_CASE(kTestGroup + "TokenLength() ignores values larger than its maximum",
          kTags) {
  Header header(Type::Value::kConfirmable, Code::Value::k000, 0x5555);

  for (auto type = coap::Token::kMaximumLength + 1;
       type <= std::numeric_limits<coap::Token::Length>::max(); type++) {
    REQUIRE(header.TokenLength(type) == false);
    REQUIRE(static_cast<Header::Value>(header).token_length == 0);
  }
}

TEST_CASE(kTestGroup + "VersionIsValid() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    REQUIRE(Header(e.header.type).VersionIsValid() ==
            e.properties.version_is_valid);
  }
}

TEST_CASE(kTestGroup + "ContainsFormatError() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    REQUIRE(Header(e.header.type).ContainsFormatError() ==
            e.properties.contains_format_error);
  }
}

TEST_CASE(kTestGroup + "IsValid() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    REQUIRE(Header(e.header.type).IsValid() == e.properties.is_valid);
  }
}

}  // namespace coap::test
