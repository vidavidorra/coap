#include <vector>

#include "header.hpp"

namespace coap::test {

using TestValue = struct {
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
    kTestValues =
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
            TestValue{.header = {.type = {0x40, 0x03, 0x00, 0x00},
                                 .value =
                                     {
                                         .message_id = 0,
                                         .code = static_cast<Code::Value>(3),
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
            TestValue{.header = {.type = {0x40, 0x03, 0xff, 0xff},
                                 .value =
                                     {
                                         .message_id = 65535,
                                         .code = static_cast<Code::Value>(3),
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
            TestValue{.header = {.type = {0x48, 0x00, 0x00, 0x00},
                                 .value =
                                     {
                                         .message_id = 0,
                                         .code = static_cast<Code::Value>(0),
                                         .token_length = 8,
                                         .type = Type::Value::kConfirmable,
                                         .version = 1,
                                     }},
                      .properties =
                          {
                              true,
                              false,
                              true,
                          }},
            TestValue{.header = {.type = {0x48, 0x00, 0xff, 0xff},
                                 .value =
                                     {
                                         .message_id = 65535,
                                         .code = static_cast<Code::Value>(0),
                                         .token_length = 8,
                                         .type = Type::Value::kConfirmable,
                                         .version = 1,
                                     }},
                      .properties =
                          {
                              true,
                              false,
                              true,
                          }},
            TestValue{.header = {.type = {0x48, 0x03, 0x00, 0x00},
                                 .value =
                                     {
                                         .message_id = 0,
                                         .code = static_cast<Code::Value>(3),
                                         .token_length = 8,
                                         .type = Type::Value::kConfirmable,
                                         .version = 1,
                                     }},
                      .properties =
                          {
                              true,
                              false,
                              true,
                          }},
            TestValue{.header = {.type = {0x48, 0x03, 0xff, 0xff},
                                 .value =
                                     {
                                         .message_id = 65535,
                                         .code = static_cast<Code::Value>(3),
                                         .token_length = 8,
                                         .type = Type::Value::kConfirmable,
                                         .version = 1,
                                     }},
                      .properties =
                          {
                              true,
                              false,
                              true,
                          }},
            TestValue{.header = {.type = {0x70, 0x00, 0x00, 0x00},
                                 .value =
                                     {
                                         .message_id = 0,
                                         .code = static_cast<Code::Value>(0),
                                         .token_length = 0,
                                         .type = Type::Value::kReset,
                                         .version = 1,
                                     }},
                      .properties =
                          {
                              true,
                              false,
                              true,
                          }},
            TestValue{.header = {.type = {0x70, 0x00, 0xff, 0xff},
                                 .value =
                                     {
                                         .message_id = 65535,
                                         .code = static_cast<Code::Value>(0),
                                         .token_length = 0,
                                         .type = Type::Value::kReset,
                                         .version = 1,
                                     }},
                      .properties =
                          {
                              true,
                              false,
                              true,
                          }},
            TestValue{.header = {.type = {0x70, 0x03, 0x00, 0x00},
                                 .value =
                                     {
                                         .message_id = 0,
                                         .code = static_cast<Code::Value>(3),
                                         .token_length = 0,
                                         .type = Type::Value::kReset,
                                         .version = 1,
                                     }},
                      .properties =
                          {
                              true,
                              false,
                              true,
                          }},
            TestValue{.header = {.type = {0x70, 0x03, 0xff, 0xff},
                                 .value =
                                     {
                                         .message_id = 65535,
                                         .code = static_cast<Code::Value>(3),
                                         .token_length = 0,
                                         .type = Type::Value::kReset,
                                         .version = 1,
                                     }},
                      .properties =
                          {
                              true,
                              false,
                              true,
                          }},
            TestValue{.header = {.type = {0x78, 0x00, 0x00, 0x00},
                                 .value =
                                     {
                                         .message_id = 0,
                                         .code = static_cast<Code::Value>(0),
                                         .token_length = 8,
                                         .type = Type::Value::kReset,
                                         .version = 1,
                                     }},
                      .properties =
                          {
                              true,
                              false,
                              true,
                          }},
            TestValue{.header = {.type = {0x78, 0x00, 0xff, 0xff},
                                 .value =
                                     {
                                         .message_id = 65535,
                                         .code = static_cast<Code::Value>(0),
                                         .token_length = 8,
                                         .type = Type::Value::kReset,
                                         .version = 1,
                                     }},
                      .properties =
                          {
                              true,
                              false,
                              true,
                          }},
            TestValue{.header = {.type = {0x78, 0x03, 0x00, 0x00},
                                 .value =
                                     {
                                         .message_id = 0,
                                         .code = static_cast<Code::Value>(3),
                                         .token_length = 8,
                                         .type = Type::Value::kReset,
                                         .version = 1,
                                     }},
                      .properties =
                          {
                              true,
                              false,
                              true,
                          }},
            TestValue{.header = {.type = {0x78, 0x03, 0xff, 0xff},
                                 .value =
                                     {
                                         .message_id = 65535,
                                         .code = static_cast<Code::Value>(3),
                                         .token_length = 8,
                                         .type = Type::Value::kReset,
                                         .version = 1,
                                     }},
                      .properties =
                          {
                              true,
                              false,
                              true,
                          }},
};

}  // namespace coap::test
