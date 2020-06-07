#include "option/format.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "catch2/catch.hpp"
#include "test/helpers/catch_matchers.hpp"

namespace sdk::test::models::coap::message::option {

std::string const kTestGroup("CoAP message option format ");
std::string const kTags("[models][coap][message][option]");

// DUT (device under test).
using Format = sdk::models::coap::message::option::Format;

TEST_CASE(kTestGroup + "correctly parses format", kTags) {
  SECTION("delta 0B min, length 0B min") {
    sdk::models::coap::message::Section::Data data{(0 << 4) | 0, 0x14, 0x22,
                                                   0x14, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{0, 0});
    REQUIRE(kFormat.SectionLength() == 1);
  }  // namespace sdk::test::models::coap::message

  SECTION("delta 0B max, length 0B max") {
    sdk::models::coap::message::Section::Data data{(12 << 4) | 12, 0x14, 0x22,
                                                   0x14, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{12, 12});
    REQUIRE(kFormat.SectionLength() == 1);
  }

  // Delta
  SECTION("delta 1B min, length 0B min") {
    sdk::models::coap::message::Section::Data data{(13 << 4) | 0, 0x00, 0x22,
                                                   0x14, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{13, 0});
    REQUIRE(kFormat.SectionLength() == 2);
  }

  SECTION("delta 1B max, length 0B max") {
    sdk::models::coap::message::Section::Data data{(13 << 4) | 12, 0xff, 0x22,
                                                   0x14, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{268, 12});
    REQUIRE(kFormat.SectionLength() == 2);
  }

  SECTION("delta 2B min, length 0B min") {
    sdk::models::coap::message::Section::Data data{(14 << 4) | 0, 0x00, 0x00,
                                                   0x14, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{269, 0});
    REQUIRE(kFormat.SectionLength() == 3);
  }

  SECTION("delta 2B max, length 0B max") {
    sdk::models::coap::message::Section::Data data{(14 << 4) | 12, 0xfe, 0xf2,
                                                   0x14, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{65535, 12});
    REQUIRE(kFormat.SectionLength() == 3);
  }

  SECTION("delta 1B min, length 1B min") {
    sdk::models::coap::message::Section::Data data{(13 << 4) | 13, 0x00, 0x00,
                                                   0x14, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{13, 13});
    REQUIRE(kFormat.SectionLength() == 3);
  }

  SECTION("delta 1B max, length 1B max") {
    sdk::models::coap::message::Section::Data data{(13 << 4) | 13, 0xff, 0xff,
                                                   0x14, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{268, 268});
    REQUIRE(kFormat.SectionLength() == 3);
  }

  SECTION("delta 2B min, length 1B min") {
    sdk::models::coap::message::Section::Data data{(14 << 4) | 13, 0x00, 0x00,
                                                   0x00, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{269, 13});
    REQUIRE(kFormat.SectionLength() == 4);
  }

  SECTION("delta 2B max, length 1B max") {
    sdk::models::coap::message::Section::Data data{(14 << 4) | 13, 0xfe, 0xf2,
                                                   0xff, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{65535, 268});
    REQUIRE(kFormat.SectionLength() == 4);
  }

  // Length
  SECTION("delta 0B min, length 1B min") {
    sdk::models::coap::message::Section::Data data{(12 << 4) | 13, 0x00, 0x22,
                                                   0x14, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{12, 13});
    REQUIRE(kFormat.SectionLength() == 2);
  }

  SECTION("delta 0B max, length 1B max") {
    sdk::models::coap::message::Section::Data data{(12 << 4) | 13, 0xff, 0x22,
                                                   0x14, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{12, 268});
    REQUIRE(kFormat.SectionLength() == 2);
  }

  SECTION("delta 0B min, length 2B min") {
    sdk::models::coap::message::Section::Data data{(12 << 4) | 14, 0x00, 0x00,
                                                   0x14, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{12, 269});
    REQUIRE(kFormat.SectionLength() == 3);
  }

  SECTION("delta 0B max, length 2B max") {
    sdk::models::coap::message::Section::Data data{(12 << 4) | 14, 0xfe, 0xf2,
                                                   0x14, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{12, 65535});
    REQUIRE(kFormat.SectionLength() == 3);
  }

  // SECTION("delta 1B min, length 1B min") {

  // SECTION("delta 1B max, length 1B max") {

  SECTION("delta 1B min, length 2B min") {
    sdk::models::coap::message::Section::Data data{(13 << 4) | 14, 0x00, 0x00,
                                                   0x00, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{13, 269});
    REQUIRE(kFormat.SectionLength() == 4);
  }

  SECTION("delta 1B max, length 2B max") {
    sdk::models::coap::message::Section::Data data{(13 << 4) | 14, 0xff, 0xfe,
                                                   0xf2, 0x22};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{268, 65535});
    REQUIRE(kFormat.SectionLength() == 4);
  }

  SECTION("delta 2B min, length 2B min") {
    sdk::models::coap::message::Section::Data data{(14 << 4) | 14, 0x00, 0x00,
                                                   0x00, 0x00};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{269, 269});
    REQUIRE(kFormat.SectionLength() == 5);
  }

  SECTION("delta 2B max, length 2B max") {
    sdk::models::coap::message::Section::Data data{(14 << 4) | 14, 0xfe, 0xf2,
                                                   0xfe, 0xf2};
    Format const kFormat(data);
    Format::Value const kFormatValue = kFormat;

    REQUIRE(kFormatValue == Format::Value{65535, 65535});
    REQUIRE(kFormat.SectionLength() == 5);
  }
}

TEST_CASE(kTestGroup + "correctly creates format", kTags) {
  SECTION("delta 0B min, length 0B min") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{0, 0};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(0 << 4) | 0, 0x00, 0x00,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 1);
    REQUIRE(option_data == data);
  }

  SECTION("delta 0B max, length 0B max") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{12, 12};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(12 << 4) | 12, 0x00, 0x00,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 1);
    REQUIRE(option_data == data);
  }

  // Delta
  SECTION("delta 1B min, length 0B min") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{13, 0};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(13 << 4) | 0, 0x00, 0x00,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 2);
    REQUIRE(option_data == data);
  }

  SECTION("delta 1B max, length 0B max") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{268, 12};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(13 << 4) | 12, 0xff, 0x00,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 2);
    REQUIRE(option_data == data);
  }

  SECTION("delta 2B min, length 0B min") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{269, 0};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(14 << 4) | 0, 0x00, 0x00,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 3);
    REQUIRE(option_data == data);
  }

  SECTION("delta 2B max, length 0B max") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{65535, 12};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(14 << 4) | 12, 0xfe, 0xf2,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 3);
    REQUIRE(option_data == data);
  }

  SECTION("delta 1B min, length 1B min") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{13, 13};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(13 << 4) | 13, 0x00, 0x00,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 3);
    REQUIRE(option_data == data);
  }

  SECTION("delta 1B max, length 1B max") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{268, 268};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(13 << 4) | 13, 0xff, 0xff,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 3);
    REQUIRE(option_data == data);
  }

  SECTION("delta 2B min, length 1B min") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{269, 13};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(14 << 4) | 13, 0x00, 0x00,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 4);
    REQUIRE(option_data == data);
  }

  SECTION("delta 2B max, length 1B max") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{65535, 268};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(14 << 4) | 13, 0xfe, 0xf2,
                                                   0xff, 0x00};
    REQUIRE(kFormat.SectionLength() == 4);
    REQUIRE(option_data == data);
  }

  // Length
  SECTION("delta 0B min, length 1B min") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{12, 13};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(12 << 4) | 13, 0x00, 0x00,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 2);
    REQUIRE(option_data == data);
  }

  SECTION("delta 0B max, length 1B max") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{12, 268};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(12 << 4) | 13, 0xff, 0x00,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 2);
    REQUIRE(option_data == data);
  }

  SECTION("delta 0B min, length 2B min") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{12, 269};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(12 << 4) | 14, 0x00, 0x00,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 3);
    REQUIRE(option_data == data);
  }

  SECTION("delta 0B max, length 2B max") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{12, 65535};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(12 << 4) | 14, 0xfe, 0xf2,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 3);
    REQUIRE(option_data == data);
  }

  // SECTION("delta 1B min, length 1B min") {

  // SECTION("delta 1B max, length 1B max") {

  SECTION("delta 1B min, length 2B min") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{13, 269};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(13 << 4) | 14, 0x00, 0x00,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 4);
    REQUIRE(option_data == data);
  }

  SECTION("delta 1B max, length 2B max") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{268, 65535};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(13 << 4) | 14, 0xff, 0xfe,
                                                   0xf2, 0x00};
    REQUIRE(kFormat.SectionLength() == 4);
    REQUIRE(option_data == data);
  }

  SECTION("delta 2B min, length 2B min") {
    sdk::models::coap::message::Section::Data option_data(5, 0);
    Format::Value kFormatValue{269, 269};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(14 << 4) | 14, 0x00, 0x00,
                                                   0x00, 0x00};
    REQUIRE(kFormat.SectionLength() == 5);
    REQUIRE(option_data == data);
  }

  SECTION("delta 2B max, length 2B max") {
    sdk::models::coap::message::Section::Data option_data(5, 0);

    Format::Value kFormatValue{65535, 65535};
    Format const kFormat(option_data, kFormatValue);

    sdk::models::coap::message::Section::Data data{(14 << 4) | 14, 0xfe, 0xf2,
                                                   0xfe, 0xf2};
    REQUIRE(kFormat.SectionLength() == 5);
    REQUIRE(option_data == data);
  }
}

TEST_CASE(kTestGroup + "constructor throws for invalid length", kTags) {
  auto const kMessage = "Section length is invalid";
  using Exception = std::invalid_argument;

  SECTION("section length too short") {
    auto const kLength = Format::kLength - 1;
    auto data = sdk::models::coap::message::Section::Data(kLength, 0);

    REQUIRE_THROWS_MATCHES(
        Format(data), Exception,
        sdk::test::helpers::MatcherStartsWith<Exception>(kMessage));
    REQUIRE_THROWS_MATCHES(
        Format(data, Format::Value{0, 0}), Exception,
        sdk::test::helpers::MatcherStartsWith<Exception>(kMessage));
  }

  SECTION("section length too long") {
    auto const kLength = Format::kLength + 1;
    auto data = sdk::models::coap::message::Section::Data(kLength, 0);

    REQUIRE_THROWS_MATCHES(
        Format(data), Exception,
        sdk::test::helpers::MatcherStartsWith<Exception>(kMessage));
    REQUIRE_THROWS_MATCHES(
        Format(data, Format::Value{0, 0}), Exception,
        sdk::test::helpers::MatcherStartsWith<Exception>(kMessage));
  }
}
}  // namespace sdk::test::models::coap::message::option
