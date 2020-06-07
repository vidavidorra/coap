#include "token.hpp"

#include <algorithm>

namespace sdk::models::coap::message {

Token::Token(sdk::models::coap::message::Section const& section)
    : sdk::models::coap::message::Section(section) {
  ValidateLength();
}

Token::Token(sdk::models::coap::message::Section const& section,
             Value const& token)
    : sdk::models::coap::message::Section(section) {
  ValidateLength();
  if (token.size() != section.SectionLength()) {
    throw std::invalid_argument("Section length is invalid - " +
                                std::to_string(SectionLength()));
  }

  std::copy(token.begin(), token.end(), Begin());
}

Token::operator Value() const { return Value{Begin(), End()}; }

void Token::ValidateLength() const {
  if (!LengthIsBetween(0, kMaximumLength)) {
    throw std::invalid_argument("Section length is invalid - " +
                                std::to_string(SectionLength()));
  }
}

}  // namespace sdk::models::coap::message
