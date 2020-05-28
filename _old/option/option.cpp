#include "option/option.hpp"

#include <algorithm>
#include <iterator>

namespace sdk::models::coap::message::option {

Option::Option(Section const& section, Numbers last_number)
    : Section(section), _it(Begin()) {
  ValidateLength();

  Section const kFormatSection({_it, _it + Format::kLength});
  Format const kFormat(kFormatSection);
  _it += kFormat.SectionLength();

  Format::Value const kFormatValue = kFormat;
  _option.number = static_cast<Numbers>(static_cast<Number>(last_number) +
                                        kFormatValue.delta);
  _option.values.emplace_back(Section::Value{_it, _it + kFormatValue.length});
}

Option::Option(Section const& section, Numbers last_number, Value const& option)
    : Section(section), _it(Begin()), _option(option) {
  ValidateLength();

  // Empty option.
  Format::ValueElement delta =
      static_cast<Number>(option.number) - static_cast<Number>(last_number);

  if (option.values.size() == 0) {
    Section const kFormatSection({_it, _it + Format::kLength});
    Format const kFormat(kFormatSection, {delta, 0});
    _it += kFormat.SectionLength();
  }

  // Option with value(s).
  for (auto value_it = option.values.begin(); value_it != option.values.end();
       ++value_it) {
    Section const kValueSection(*value_it);
    Section const kFormatSection({_it, _it + Format::kLength});

    Format const kFormat(kFormatSection,
                         {delta, kValueSection.SectionLength()});
    _it += kFormat.SectionLength();

    std::copy(kValueSection.Begin(), kValueSection.End(), _it);
    _it += kValueSection.SectionLength();

    /**
     * Only the first format needs to have the delta of the option itself. The
     * remaining formats will have a delta of zero as they're for the same
     * option.
     */
    delta = 0;
  }
}

Option::operator Value() const { return _option; }

Section::LengthType Option::SectionLength() const { return _it - Begin(); }

void Option::ValidateLength() const {
  if (!LengthIsBetween(kLength)) {
    throw std::invalid_argument("Section length is invalid - " +
                                std::to_string(SectionLength()));
  }
}

}  // namespace sdk::models::coap::message::option
