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
            TestValue{
                .header = {.type = {0x40, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x40, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x41, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x47, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x48, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x50, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x51, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x57, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x58, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kNonConfirmable,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x60, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x61, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x67, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x68, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kAcknowledgement,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x70, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 0,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x71, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 1,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x77, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 7,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0x00, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0x00, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0x00, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0x00, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k000,
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0x01, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0x01, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0x01, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0x01, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = Code::Value::k001,
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0xfe, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0xfe, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0xfe, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0xfe, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(254),
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0xff, 0x00, 0x00},
                           .value =
                               {
                                   .message_id = 0,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0xff, 0x00, 0x01},
                           .value =
                               {
                                   .message_id = 1,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0xff, 0xff, 0xfe},
                           .value =
                               {
                                   .message_id = 65534,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
            TestValue{
                .header = {.type = {0x78, 0xff, 0xff, 0xff},
                           .value =
                               {
                                   .message_id = 65535,
                                   .code = static_cast<Code::Value>(255),
                                   .token_length = 8,
                                   .type = Type::Value::kReset,
                                   .version = 1,
                               }},
                .properties =
                    {
                        .version_is_valid = true,
                        .contains_format_error = false,
                        .is_valid = true,
                    },
            },
};

}  // namespace coap::test
