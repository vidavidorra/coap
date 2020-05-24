#include <vector>

#include "type.hpp"

namespace coap::test {

using TestValue = struct TestValue {
  struct {
    Type::DataType data;
    Type::Value value;
  } type;

  struct {
    bool is_confirmable;
    bool is_non_confirmable;
    bool is_acknowledgement;
    bool is_reset;
  } properties;
};

std::vector<TestValue> const kTestValues = {
    TestValue{.type = {.data = 0x00, .value = Type::Value::kConfirmable},
              .properties = {true, false, false, false}},
    TestValue{.type = {.data = 0x01, .value = Type::Value::kNonConfirmable},
              .properties = {false, true, false, false}},
    TestValue{.type = {.data = 0x02, .value = Type::Value::kAcknowledgement},
              .properties = {false, false, true, false}},
    TestValue{.type = {.data = 0x03, .value = Type::Value::kReset},
              .properties = {false, false, false, true}},
};

}  // namespace coap::test
