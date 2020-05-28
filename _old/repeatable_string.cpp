#include "option/repeatable_string.hpp"

#include <algorithm>

namespace sdk::models::coap::message::option {

RepeatableString::RepeatableString(std::string path)
    : _data(path.begin(), path.end()) {
  auto const kSeperator = '/';

  auto it = _data.begin();
  auto const kSectionCount = std::count(_data.begin(), _data.end(), kSeperator);

  /**
   * Loop to section count plus one to include the section after the last
   * match. On that last loop, `std::find` will find no match and return an
   * iterator to the last element, which creates the section after the last
   * match.
   */
  for (int i = 0; i < kSectionCount + 1; i++) {
    auto const kMatchIt = std::find(it, _data.end(), kSeperator);
    if (it != _data.end()) {
      _values.emplace_back(Section::Value{it, kMatchIt});
    }

    // Plus one to get past the found element for the next iteration.
    it = kMatchIt + 1;
  }
}

RepeatableString::operator Option::Values() const { return _values; }

}  // namespace sdk::models::coap::message::option
