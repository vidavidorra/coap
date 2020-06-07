#pragma once

#include <string>

#include "option/option.hpp"
#include "section.hpp"

namespace sdk::models::coap::message::option {

class RepeatableString {
 public:
  RepeatableString(std::string path);

  operator Option::Values() const;

 private:
  Section::Data _data;
  Option::Values _values;
};

}  // namespace sdk::models::coap::message::option
