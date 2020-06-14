#include "token.hpp"

#include <cstdint>
#include <iostream>
#include <vector>

#include "catch2/catch.hpp"
#include "test-data.hpp"

namespace coap::test {

std::string const kTestGroup("Token ");
std::string const kTags("[token]");

// DUT (device under test).
using Token = coap::Token;

TEST_CASE(kTestGroup + "correctly constructs token", kTags) {
  SECTION("from Value") {
    for (auto const& e : kTestValues) {
      const Token kToken(e.token.value);

      REQUIRE(static_cast<Token::Value>(kToken) == e.token.value);
    }
  }

  SECTION("from Vector") {
    for (auto const& e : kTestValues) {
      const Token kToken(e.token.vector_value);

      REQUIRE(static_cast<Token::Value>(kToken) == e.token.value);
    }
  }
}

TEST_CASE(kTestGroup + "operator Value() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    const Token kToken(e.token.vector_value);

    REQUIRE(static_cast<Token::Value>(kToken) == e.token.value);
  }
}

TEST_CASE(kTestGroup + "operator Vector() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    const Token kToken(e.token.vector_value);

    REQUIRE(static_cast<Token::Vector>(kToken) == e.token.vector_value);
  }
}

TEST_CASE(kTestGroup +
              "Vector constructor ignores lengths larger than the maximum",
          kTags) {
  Token::Vector const kValue(std::numeric_limits<Token::Length>::max(), 0xaa);
  Token::Data expected_token;
  std::copy(kValue.begin(), kValue.begin() + Token::kMaximumLength,
            expected_token.begin());

  for (Token::Length length = Token::kMaximumLength + 1; length < kValue.size();
       length++) {
    Token::Vector const kSubset(kValue.begin(), kValue.begin() + length);
    Token const kToken(kSubset);

    REQUIRE(static_cast<Token::Value>(kToken).length == Token::kMaximumLength);
    REQUIRE(static_cast<Token::Value>(kToken).data == expected_token);
  }
}

}  // namespace coap::test
