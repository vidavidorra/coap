#include "option/option.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "catch2/catch.hpp"
#include "test/helpers/catch_matchers.hpp"

namespace sdk::test::models::coap::message::option {

std::string const kTestGroup("CoAP message option ");
std::string const kTags("[models][coap][message][option]");

// DUT (device under test).
using Option = sdk::models::coap::message::option::Option;

TEST_CASE(kTestGroup + "correctly parses option", kTags) {
  int const kValueByts = 3;
  sdk::models::coap::message::Section::Data const kFormatData{
      (13 << 4) | kValueByts, 0x02};
  sdk::models::coap::message::Section::Data kValue(kValueByts, 0xaa);

  sdk::models::coap::message::Section::Data data(Option::kLength, 0x55);
  auto data_it =
      std::copy(kFormatData.begin(), kFormatData.end(), data.begin());
  data_it = std::copy(kValue.begin(), kValue.end(), data_it);

  Option const kOption(data, static_cast<Option::Numbers>(0));
  Option::Value const kOptionValue = kOption;

  sdk::models::coap::message::Section const kVal(kValue);
  REQUIRE(kOptionValue.number == Option::Numbers::kUriQuery);
  REQUIRE(kOptionValue.values.front() == kVal);
}

TEST_CASE(kTestGroup + "correctly parses option after previous one", kTags) {
  int const kValueByts = 20;
  sdk::models::coap::message::Section::Data const kFormatData{(3 << 4) | 13,
                                                              kValueByts - 13};
  sdk::models::coap::message::Section::Data kValue(kValueByts, 0xaa);

  sdk::models::coap::message::Section::Data data(Option::kLength, 0x55);
  auto data_it =
      std::copy(kFormatData.begin(), kFormatData.end(), data.begin());
  data_it = std::copy(kValue.begin(), kValue.end(), data_it);

  Option const kOption(data, static_cast<Option::Numbers>(15));
  Option::Value const kOptionValue = kOption;

  sdk::models::coap::message::Section const kVal(kValue);
  REQUIRE(kOptionValue.number == static_cast<Option::Numbers>(18));
  REQUIRE(kOptionValue.values.front() == kVal);
}

TEST_CASE(kTestGroup + "correctly creates option", kTags) {
  int const kValueByts = 20;
  sdk::models::coap::message::Section::Data const kFormatData{(14 << 4) | 13,
                                                              0x03, 0xa3, 0x07};
  sdk::models::coap::message::Section::Data kValue(kValueByts, 0xaa);
  sdk::models::coap::message::Section::Data const kFormatData2{(0 << 4) | 13,
                                                               0x03};
  sdk::models::coap::message::Section::Data kValue2(16, 0x11);

  sdk::models::coap::message::Section::Data data(Option::kLength, 0x55);

  Option::Value const kOptionValue{static_cast<Option::Numbers>(1200),
                                   {kValue, kValue2}};
  Option const kOption(data, static_cast<Option::Numbers>(0), kOptionValue);

  sdk::models::coap::message::Section::Data expected_data(Option::kLength,
                                                          0x55);
  auto data_it =
      std::copy(kFormatData.begin(), kFormatData.end(), expected_data.begin());
  data_it = std::copy(kValue.begin(), kValue.end(), data_it);
  data_it = std::copy(kFormatData2.begin(), kFormatData2.end(), data_it);
  data_it = std::copy(kValue2.begin(), kValue2.end(), data_it);

  REQUIRE(data == expected_data);
}

}  // namespace sdk::test::models::coap::message::option
