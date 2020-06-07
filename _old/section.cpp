#include "section.hpp"

#include <algorithm>

namespace sdk::models::coap::message {

Section::Section(Value section) : _kSection(section) {}

Section::Section(Data& data) : _kSection({data.begin(), data.end()}) {}

bool Section::operator==(Section const& other) const {
  return std::equal(_kSection.begin, _kSection.end, other.Begin());
}

Section::Iterator Section::Begin() const { return _kSection.begin; };

Section::Iterator Section::End() const { return _kSection.end; }

Section::LengthType Section::SectionLength() const {
  return _kSection.end - _kSection.begin;
}

bool Section::LengthIsBetween(LengthType minimum_length,
                              LengthType maximum_length) const {
  if (SectionLength() < minimum_length ||
      (maximum_length && SectionLength() > maximum_length)) {
    return false;
  }

  return true;
}

bool Section::LengthEquals(LengthType length) const {
  return SectionLength() == length;
}

}  // namespace sdk::models::coap::message
