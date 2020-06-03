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

using TV = struct {
  struct {
    coap::Header::Type type;
    coap::Header::Value value;
  } header;

  struct {
    bool version_is_valid;
    bool contains_format_error;
    bool is_valid;
  } properties;
};

std::vector<TestValue> const
    kt =
        {
            TestValue{.header = {.type = {0x40, 0x00, 0x00, 0x00},
                                 .value =
                                     {
                                         .message_id = 0,
                                         .code = static_cast<Code::Value>(0),
                                         .token_length = 0,
                                         .type = Type::Value::kConfirmable,
                                         .version = 1,
                                     }},
                      .properties =
                          {
                              true,
                              false,
                              true,
                          }},
            TestValue{.header = {.type = {0x40, 0x00, 0xff, 0xff},
                                 .value =
                                     {
                                         .message_id = 65535,
                                         .code = static_cast<Code::Value>(0),
                                         .token_length = 0,
                                         .type = Type::Value::kConfirmable,
                                         .version = 1,
                                     }},
                      .properties =
                          {
                              true,
                              false,
                              true,
                          }},
};

TEST_CASE(kTestGroup + "correctly parses header", kTags) {
  SECTION("from Type") {
    for (auto const& e : kTestValues) {
      const Header kHeader(e.header.type);

      REQUIRE(static_cast<Header::Type>(kHeader) == e.header.type);
    }
  }

  SECTION("from Value") {
    printf(" V\n");
    int i = 0;
    for (auto const& e : kTestValues) {
      printf("Header %d: ", i++);
      for (auto const& x : e.header.type) {
        printf("0x%02hhx, ", x);
      }
      printf("\n");
      Header header(e.header.value.type, e.header.value.code,
                    e.header.value.message_id);
      if (e.header.value.token_length != 0) {
        header.TokenLength(e.header.value.token_length);
      }
      REQUIRE(static_cast<Header::Type>(header) == e.header.type);
    }
  }
}

}  // namespace coap::test

/**
 *
 Header: 0x40, 0x00, 0x00, 0x00,
Header: 0x00, 0x40, 0x01, 0x00,
Header: 0x40, 0x00, 0xff, 0xff,
Header: 0x00, 0x40, 0x01, 0x00,
Header: 0x40, 0x03, 0x00, 0x00,
Header: 0x03, 0x40, 0x01, 0x00,
Header: 0x40, 0x03, 0xff, 0xff,
Header: 0x03, 0x40, 0x01, 0x00,
Header: 0x48, 0x00, 0x00, 0x00,
Header: 0x00, 0x48, 0x01, 0x00,
Header: 0x48, 0x00, 0xff, 0xff,
Header: 0x00, 0x48, 0x01, 0x00,
Header: 0x48, 0x03, 0x00, 0x00,
Header: 0x03, 0x48, 0x01, 0x00,
Header: 0x48, 0x03, 0xff, 0xff,
Header: 0x03, 0x48, 0x01, 0x00,

TestValue{.header = {.type = { 0x40, 0x00, 0x00, 0x00 }, .value = { .message_id
= 0, .code = static_cast<Code::Value>(0), .token_length = 0, .type =
Type::Value::kConfirmable, .version = 1, }}, .properties = { true, false, true,
}}, TestValue{.header = {.type = { 0x40, 0x00, 0xff, 0xff }, .value = {
.message_id = 65535, .code = static_cast<Code::Value>(0), .token_length = 0,
.type = Type::Value::kConfirmable, .version = 1, }}, .properties = { true,
false, true, }}, TestValue{.header = {.type = { 0x40, 0x03, 0x00, 0x00 }, .value
= { .message_id = 0, .code = static_cast<Code::Value>(3), .token_length = 0,
.type = Type::Value::kConfirmable, .version = 1, }}, .properties = { true,
false, true, }}, TestValue{.header = {.type = { 0x40, 0x03, 0xff, 0xff }, .value
= { .message_id = 65535, .code = static_cast<Code::Value>(3), .token_length = 0,
.type = Type::Value::kConfirmable, .version = 1, }}, .properties = { true,
false, true, }}, TestValue{.header = {.type = { 0x48, 0x00, 0x00, 0x00 }, .value
= { .message_id = 0, .code = static_cast<Code::Value>(0), .token_length = 8,
.type = Type::Value::kConfirmable, .version = 1, }}, .properties = { true,
false, true, }}, TestValue{.header = {.type = { 0x48, 0x00, 0xff, 0xff }, .value
= { .message_id = 65535, .code = static_cast<Code::Value>(0), .token_length = 8,
.type = Type::Value::kConfirmable, .version = 1, }}, .properties = { true,
false, true, }}, TestValue{.header = {.type = { 0x48, 0x03, 0x00, 0x00 }, .value
= { .message_id = 0, .code = static_cast<Code::Value>(3), .token_length = 8,
.type = Type::Value::kConfirmable, .version = 1, }}, .properties = { true,
false, true, }}, TestValue{.header = {.type = { 0x48, 0x03, 0xff, 0xff }, .value
= { .message_id = 65535, .code = static_cast<Code::Value>(3), .token_length = 8,
.type = Type::Value::kConfirmable, .version = 1, }}, .properties = { true,
false, true, }}, TestValue{.header = {.type = { 0x70, 0x00, 0x00, 0x00 }, .value
= { .message_id = 0, .code = static_cast<Code::Value>(0), .token_length = 0,
.type = Type::Value::kReset, .version = 1, }}, .properties = { true, false,
true, }}, TestValue{.header = {.type = { 0x70, 0x00, 0xff, 0xff }, .value = {
.message_id = 65535, .code = static_cast<Code::Value>(0), .token_length = 0,
.type = Type::Value::kReset, .version = 1, }}, .properties = { true, false,
true, }}, TestValue{.header = {.type = { 0x70, 0x03, 0x00, 0x00 }, .value = {
.message_id = 0, .code = static_cast<Code::Value>(3), .token_length = 0, .type =
Type::Value::kReset, .version = 1, }}, .properties = { true, false, true, }},
TestValue{.header = {.type = { 0x70, 0x03, 0xff, 0xff }, .value = { .message_id
= 65535, .code = static_cast<Code::Value>(3), .token_length = 0, .type =
Type::Value::kReset, .version = 1, }}, .properties = { true, false, true, }},
TestValue{.header = {.type = { 0x78, 0x00, 0x00, 0x00 }, .value = { .message_id
= 0, .code = static_cast<Code::Value>(0), .token_length = 8, .type =
Type::Value::kReset, .version = 1, }}, .properties = { true, false, true, }},
TestValue{.header = {.type = { 0x78, 0x00, 0xff, 0xff }, .value = { .message_id
= 65535, .code = static_cast<Code::Value>(0), .token_length = 8, .type =
Type::Value::kReset, .version = 1, }}, .properties = { true, false, true, }},
TestValue{.header = {.type = { 0x78, 0x03, 0x00, 0x00 }, .value = { .message_id
= 0, .code = static_cast<Code::Value>(3), .token_length = 8, .type =
Type::Value::kReset, .version = 1, }}, .properties = { true, false, true, }},
TestValue{.header = {.type = { 0x78, 0x03, 0xff, 0xff }, .value = { .message_id
= 65535, .code = static_cast<Code::Value>(3), .token_length = 8, .type =
Type::Value::kReset, .version = 1, }}, .properties = { true, false, true, }},
*/
