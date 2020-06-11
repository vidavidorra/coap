#include "type.hpp"

#include <limits>
#include <string>

#include "catch2/catch.hpp"
#include "test-data.hpp"

namespace coap::test {

std::string const kTestGroup("Type ");
std::string const kTags("[type]");

// DUT (device under test).
using Type = coap::Type;

TEST_CASE(kTestGroup + "correctly parses type", kTags) {
  SECTION("from DataType") {
    for (auto const& e : kTestValues) {
      const Type kType(e.type.data);
      REQUIRE(static_cast<Type::DataType>(kType) == e.type.data);
    }
  }

  SECTION("from Value") {
    for (auto const& e : kTestValues) {
      const Type kType(e.type.value);
      REQUIRE(static_cast<Type::DataType>(kType) == e.type.data);
    }
  }
}

TEST_CASE(kTestGroup + "ignores unused bits", kTags) {
  Type::DataType type = std::numeric_limits<Type::DataType>::min();
  Type::DataType const kMax = std::numeric_limits<Type::DataType>::max();
  /**
   * Type is a 2-bit unsigned integer as described by RFC 7252 §3.
   * - https://tools.ietf.org/html/rfc7252#section-3
   */
  Type::DataType const kTwoBitBitmask = 0x03;

  SECTION("from DataType") {
    do {
      const Type kType(type);
      REQUIRE(static_cast<Type::DataType>(kType) == (type & kTwoBitBitmask));
    } while (type++ != kMax);
  }

  SECTION("from Value") {
    do {
      const Type kType(static_cast<Type::Value>(type));
      REQUIRE(static_cast<Type::DataType>(kType) == (type & kTwoBitBitmask));
    } while (type++ != kMax);
  }
}

TEST_CASE(kTestGroup + "operator DataType() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    const Type kType(e.type.data);
    REQUIRE(static_cast<Type::DataType>(kType) == e.type.data);
  }
}

TEST_CASE(kTestGroup + "operator Value() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    const Type kType(e.type.data);
    REQUIRE(static_cast<Type::Value>(kType) == e.type.value);
  }
}

TEST_CASE(kTestGroup + "IsConfirmable() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    REQUIRE(Type(e.type.data).IsConfirmable() == e.properties.is_confirmable);
  }
}

TEST_CASE(kTestGroup + "IsNonConfirmable() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    REQUIRE(Type(e.type.data).IsNonConfirmable() ==
            e.properties.is_non_confirmable);
  }
}

TEST_CASE(kTestGroup + "IsAcknowledgement() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    REQUIRE(Type(e.type.data).IsAcknowledgement() ==
            e.properties.is_acknowledgement);
  }
}

TEST_CASE(kTestGroup + "IsReset() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    REQUIRE(Type(e.type.data).IsReset() == e.properties.is_reset);
  }
}

}  // namespace coap::test
