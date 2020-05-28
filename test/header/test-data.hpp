#include <vector>

#include "header.hpp"

namespace coap::test {

using TestValue = struct TestValue {
  struct {
    Header::Type type;
    Header::Value value;
  } header;

  struct {
    bool version_is_valid;
    bool contains_format_error;
    bool is_valid;
  } properties;
};

std::vector<TestValue> const kTestValues = {
    TestValue{.header = {.type = {0x40, 0x00, 0x00, 0x00},
                         .value =
                             {
                                 .message_id = 0,
                                 .code = Code::Value::kEmpty,
                                 .token_length = 0,
                                 .type = Type::Value::kConfirmable,
                                 .version = 1,
                             }},
              .properties = {true, false, true}},
};

}  // namespace coap::test
