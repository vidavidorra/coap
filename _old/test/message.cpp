#include "message.hpp"

#include <string>
#include <vector>

#include "catch2/catch.hpp"
#include "option/repeatable_string.hpp"

namespace sdk::test::models::coap::message {

std::string const kTestGroup("CoAP message ");
std::string const kTags("[models][coap][message]");

// DUT (device under test).
using Message = sdk::models::coap::message::Message;

TEST_CASE(kTestGroup + "correctly parses message", kTags) {
  sdk::models::coap::message::Section::Data message_data(
      sdk::models::coap::message::Message::kMaximumLength, 0);

  // Header
  sdk::models::coap::message::Section::Data const kHeader{0x42, 0x01, 0xff,
                                                          0xfe};
  auto data_it =
      std::copy(kHeader.begin(), kHeader.end(), message_data.begin());
  // Token
  sdk::models::coap::message::Section::Data const kToken{0x55, 0xaa};
  data_it = std::copy(kToken.begin(), kToken.end(), data_it);

  // Options
  int const kValueBytes = 3;
  sdk::models::coap::message::Section::Data const kFormatData{
      (13 << 4) | kValueBytes, 0x02};
  sdk::models::coap::message::Section::Data const kValue(kValueBytes, 0xa5);
  data_it = std::copy(kFormatData.begin(), kFormatData.end(), data_it);
  data_it = std::copy(kValue.begin(), kValue.end(), data_it);

  Message const kMessage(message_data);

  REQUIRE(kMessage.Header().Version() == 1);
  REQUIRE(kMessage.Header().Type() ==
          sdk::models::coap::message::Type::Types::kConfirmable);
  REQUIRE(kMessage.Header().TokenLength() == 2);
  REQUIRE(kMessage.Header().Code() == 1);
  REQUIRE(kMessage.Header().MessageId() == 65534);
  REQUIRE(static_cast<sdk::models::coap::message::Token::Value>(
              kMessage.Token()) == kToken);
}

TEST_CASE(kTestGroup + "correctly parses message with options and payload",
          kTags) {
  sdk::models::coap::message::Section::Data message_data(
      sdk::models::coap::message::Message::kMaximumLength, 0);

  // Header
  sdk::models::coap::message::Section::Data const kHeader{0x42, 0x01, 0xff,
                                                          0xfe};
  auto data_it =
      std::copy(kHeader.begin(), kHeader.end(), message_data.begin());
  // Token
  sdk::models::coap::message::Section::Data const kToken{0x55, 0xaa};
  data_it = std::copy(kToken.begin(), kToken.end(), data_it);

  Message const kMessage(message_data);

  REQUIRE(kMessage.Header().Version() == 1);
  REQUIRE(kMessage.Header().Type() ==
          sdk::models::coap::message::Type::Types::kConfirmable);
  REQUIRE(kMessage.Header().TokenLength() == 2);
  REQUIRE(kMessage.Header().Code() == 1);
  REQUIRE(kMessage.Header().MessageId() == 65534);
  REQUIRE(static_cast<sdk::models::coap::message::Token::Value>(
              kMessage.Token()) == kToken);
}

TEST_CASE(kTestGroup + "correctly creates message", kTags) {
  sdk::models::coap::message::Section::Data message_data(
      sdk::models::coap::message::Message::kMaximumLength, 0);

  sdk::models::coap::message::Section::Data const kPayload{0x00, 0x11, 0xff,
                                                           0x5a};
  Message const kMessage(
      message_data,
      {sdk::models::coap::message::Type::Types::kConfirmable, 2, 1, 65534},
      {0x55, 0xaa}, kPayload, {});

  sdk::models::coap::message::Section::Data const kMessageData{
      0x42, 0x01, 0xff, 0xfe, 0x55, 0xaa, 0xff, 0x00, 0x11, 0xff, 0x5a};

  REQUIRE(kMessageData == sdk::models::coap::message::Section::Data{
                              message_data.begin(),
                              message_data.begin() + kMessageData.size()});
}

TEST_CASE(kTestGroup +
              "correctly creates message with multiple options and payload",
          kTags) {
  // 480170fa48af7a59f68b2706b86669726d77617265066b6439366579c202b6ed07192b7971776a6d793ac39dc39cc28863c28a5cc39ac2adc392c2953d5c74c2821712c380c2b4c289c3bec3a767c3a9c28f054a07112264c28902
  sdk::models::coap::message::Section::Data kData = {
      0x48, 0x01, 0x70, 0xfa, 0x48, 0xaf, 0x7a, 0x59, 0xf6, 0x8b, 0x27, 0x06,
      0xb8, 0x66, 0x69, 0x72, 0x6d, 0x77, 0x61, 0x72, 0x65, 0x06, 0x6b, 0x64,
      0x39, 0x36, 0x65, 0x79, 0xc2, 0x02, 0xb6, 0xed, 0x07, 0x19, 0x2b, 0x79,
      0x71, 0x77, 0x6a, 0x6d, 0x79, 0x3a, 0xc3, 0x9d, 0xc3, 0x9c, 0xc2, 0x88,
      0x63, 0xc2, 0x8a, 0x5c, 0xc3, 0x9a, 0xc2, 0xad, 0xc3, 0x92, 0xc2, 0x95,
      0x3d, 0x5c, 0x74, 0xc2, 0x82, 0x17, 0x12, 0xc3, 0x80, 0xc2, 0xb4, 0xc2,
      0x89, 0xc3, 0xbe, 0xc3, 0xa7, 0x67, 0xc3, 0xa9, 0xc2, 0x8f, 0x05, 0x4a,
      0x07, 0x11, 0x22, 0x64, 0xc2, 0x89, 0x02,
  };

  // 48af7a59f68b2706
  sdk::models::coap::message::Section::Data const kToken = {
      0x48, 0xaf, 0x7a, 0x59, 0xf6, 0x8b, 0x27, 0x06};

  sdk::models::coap::message::Section::Data data(
      sdk::models::coap::message::Message::kMaximumLength, 0);

  /**
   * uriPath:
   *  - `firmware` (6669726d77617265)
   *  - `kd96ey` (6b6439366579)
   * Block2:
   *  - `{ size: 1024, more: false, number: 43 }` (b6ed)
   * 2109:
   * 7971776a6d793ac39dc39cc28863c28a5cc39ac2adc392c2953d5c74c2821712c380c2b4c289c3bec3a767c3a9c28f054a07112264c28902
   */

  sdk::models::coap::message::Section::Data kUriPath1 = {
      0x66, 0x69, 0x72, 0x6d, 0x77, 0x61, 0x72, 0x65};
  sdk::models::coap::message::Section::Data kUriPath2 = {0x6b, 0x64, 0x39,
                                                         0x36, 0x65, 0x79};
  sdk::models::coap::message::Section::Data kBlock2 = {0x02, 0xb6};
  sdk::models::coap::message::Section::Data kAuthentication = {
      0x79, 0x71, 0x77, 0x6a, 0x6d, 0x79, 0x3a, 0xc3, 0x9d, 0xc3, 0x9c, 0xc2,
      0x88, 0x63, 0xc2, 0x8a, 0x5c, 0xc3, 0x9a, 0xc2, 0xad, 0xc3, 0x92, 0xc2,
      0x95, 0x3d, 0x5c, 0x74, 0xc2, 0x82, 0x17, 0x12, 0xc3, 0x80, 0xc2, 0xb4,
      0xc2, 0x89, 0xc3, 0xbe, 0xc3, 0xa7, 0x67, 0xc3, 0xa9, 0xc2, 0x8f, 0x05,
      0x4a, 0x07, 0x11, 0x22, 0x64, 0xc2, 0x89, 0x02};

  sdk::models::coap::message::option::RepeatableString uri_path(
      "firmware/kd96ey");

  sdk::models::coap::message::option::Options options;

  options.emplace(sdk::models::coap::message::option::Option::Numbers::kUriPath,
                  uri_path);
  options.emplace(
      sdk::models::coap::message::option::Option::Numbers::k2109,
      sdk::models::coap::message::option::Option::Values{kAuthentication});
  options.emplace(sdk::models::coap::message::option::Option::Numbers::kBlock2,
                  sdk::models::coap::message::option::Option::Values{kBlock2});

  Message const kMessage(data,
                         {sdk::models::coap::message::Type::Types::kConfirmable,
                          static_cast<std::uint8_t>(kToken.size()),
                          sdk::models::coap::message::Code::Codes::kGet, 28922},
                         kToken, {}, options);

  REQUIRE(kMessage.Header().Version() == 1);
  REQUIRE(kMessage.Header().Type() ==
          sdk::models::coap::message::Type::Types::kConfirmable);
  REQUIRE(kMessage.Header().TokenLength() == kToken.size());
  REQUIRE(kMessage.Header().Code() ==
          sdk::models::coap::message::Code::Codes::kGet);
  REQUIRE(kMessage.Header().MessageId() == 28922);
  REQUIRE(static_cast<sdk::models::coap::message::Token::Value>(
              kMessage.Token()) == kToken);
  data.resize(kMessage.SectionLength());
  REQUIRE(data == kData);
}

}  // namespace sdk::test::models::coap::message
