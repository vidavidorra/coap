#include "coap.hpp"

#include <algorithm>  //
#include <cstdint>
#include <iostream>
#include <iterator>  //
#include <random>    //
#include <vector>

#include "catch2/catch.hpp"

namespace coap::test {

auto randomNumberInRange = [](std::uint8_t lowest_value,
                              std::uint8_t highest_value) {
  return [distribution = std::uniform_int_distribution<std::uint8_t>(
              lowest_value, highest_value),
          random_engine = std::mt19937{std::random_device{}()}]() mutable {
    return distribution(random_engine);
  };
};

std::string const kTestGroup("CoAP ");
std::string const kTags("[coap]");

// DUT (device under test).
using Coap = coap::Coap;

TEST_CASE(kTestGroup + "correctly parses code", kTags) {
  Coap coap(20);
  coap::Token::Value token{{0xff, 0x18}, 4};
  coap::Token::Value token2{{0xff, 0x18}, 4};

  REQUIRE(token == token2);

  coap::Token::Vector v = coap::Token(token);
  printf("Test token of %lu bytes: ", v.size());
  for (auto const& e : v) {
    printf("%02hhx, ", e);
  }
  printf("\n");

  // token.
  coap.option().payload().token(  //
      token);
  // coap::Token({0xaa, 0x11}));

  Coap coap2(20, coap::Header(coap::Type::Value::kConfirmable,
                              coap::Code::Value::kPost, 123));
  // coap2.option().payload().token();

  std::vector<std::uint8_t> numbers;
  std::generate_n(std::back_inserter(numbers), 100, randomNumberInRange(0, 10));
}

}  // namespace coap::test
