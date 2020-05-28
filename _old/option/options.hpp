#pragma once

#include <map>

#include "option/option.hpp"

namespace sdk::models::coap::message::option {

using Options = std::map<Option::Numbers, Option::Values>;

}  // namespace sdk::models::coap::message::option
