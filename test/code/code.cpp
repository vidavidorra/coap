#include "code.hpp"

#include <limits>
#include <string>

#include "catch2/catch.hpp"
#include "test-data.hpp"

namespace coap::test {

std::string const kTestGroup("Code ");
std::string const kTags("[code]");

// DUT (device under test).
using Code = coap::Code;

TEST_CASE(kTestGroup + "correctly parses code", kTags) {
  SECTION("from Type") {
    for (auto const& e : kTestValues) {
      const Code kCode(e.code.type);
      REQUIRE(static_cast<Code::Type>(kCode) == e.code.type);
    }
  }

  SECTION("from Value") {
    for (auto const& e : kTestValues) {
      for (auto const& value : e.code.values) {
        const Code kCode(value);
        REQUIRE(static_cast<Code::Type>(kCode) == e.code.type);
      }
    }
  }

  SECTION("from Parts") {
    for (auto const& e : kTestValues) {
      const Code kCode(e.code.parts);
      REQUIRE(static_cast<Code::Type>(kCode) == e.code.type);
    }
  }
}

TEST_CASE(kTestGroup + "operator Type() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    const Code kCode(e.code.type);
    REQUIRE(static_cast<Code::Type>(kCode) == e.code.type);
  }
}

TEST_CASE(kTestGroup + "operator Value() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    const Code kCode(e.code.type);
    REQUIRE(static_cast<Code::Value>(kCode) == e.code.values.at(0));
  }
}

TEST_CASE(kTestGroup + "operator Parts() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    const Code kCode(e.code.type);
    REQUIRE(static_cast<Code::Parts>(kCode).class_ == e.code.parts.class_);
    REQUIRE(static_cast<Code::Parts>(kCode).detail == e.code.parts.detail);
  }
}

TEST_CASE(kTestGroup + "correctly parses all codes", kTags) {
  Code::Type code = std::numeric_limits<Code::Type>::min();

  do {
    /**
     * RFC 7252 §5.2: As a human-readable notation for specifications and
     * protocol diagnostics, CoAP code numbers including the response Code are
     * documented in the format "c.dd", where "c" is the class in decimal, and
     * "dd" is the detail as a two-digit decimal.  For example, "Forbidden" is
     * written as 4.03 -- indicating an 8-bit code value of hexadecimal 0x83
     * (4*0x20+3) or decimal 131 (4*32+3).
     */
    Code::Type const kClass = code / 0x20;
    Code::Type const kDetail = code - (kClass * 0x20);

    Code const kCode = Code(code);
    Code::Parts const kParts = kCode;

    REQUIRE(static_cast<Code::Type>(kCode) == code);
    REQUIRE(static_cast<Code::Type>(kParts.class_) == kClass);
    REQUIRE(kParts.detail == kDetail);
  } while (code++ != std::numeric_limits<Code::Type>::max());
}

TEST_CASE(kTestGroup + "assigns correct class", kTags) {
  for (auto const& e : kTestValues) {
    const Code kCode(e.code.type);
    REQUIRE(static_cast<Code::Parts>(kCode).class_ == e.code.parts.class_);
  }
}

TEST_CASE(kTestGroup + "assigns correct detail", kTags) {
  for (auto const& e : kTestValues) {
    const Code kCode(e.code.type);
    REQUIRE(static_cast<Code::Parts>(kCode).detail == e.code.parts.detail);
  }
}

TEST_CASE(kTestGroup + "IsRequest() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    REQUIRE(Code(e.code.type).IsRequest() == e.properties.is_request);
  }
}

TEST_CASE(kTestGroup + "IsResponse() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    REQUIRE(Code(e.code.type).IsResponse() == e.properties.is_response);
  }
}

TEST_CASE(kTestGroup + "IsSuccess() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    REQUIRE(Code(e.code.type).IsSuccess() == e.properties.is_success);
  }
}

TEST_CASE(kTestGroup + "IsClientError() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    REQUIRE(Code(e.code.type).IsClientError() == e.properties.is_client_error);
  }
}

TEST_CASE(kTestGroup + "IsServerError() returns correctly", kTags) {
  for (auto const& e : kTestValues) {
    REQUIRE(Code(e.code.type).IsServerError() == e.properties.is_server_error);
  }
}

}  // namespace coap::test
