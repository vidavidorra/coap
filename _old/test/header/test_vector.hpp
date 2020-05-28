#pragma once

#include <vector>

#include "code.hpp"
#include "header.hpp"
#include "section.hpp"
#include "type.hpp"

namespace sdk::test::models::coap::message::header {

struct TestValue {
  sdk::models::coap::message::Section::Data header;
  sdk::models::coap::message::Header::Value value;
};

extern std::vector<TestValue> const kTestValues;

}  // namespace sdk::test::models::coap::message::header
