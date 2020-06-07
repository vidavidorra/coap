#include "message.hpp"

#include "option/option.hpp"

namespace sdk::models::coap::message {

Message::Message(sdk::models::coap::message::Section::Data& data)
    : sdk::models::coap::message::Section(data),
      _kHeaderSection(
          {Begin(), Begin() + sdk::models::coap::message::Header::kLength}),
      _kHeader(_kHeaderSection),
      _kTokenSection({_kHeaderSection.End(),
                      _kHeaderSection.End() + Header().TokenLength()}),
      _kToken(_kTokenSection),
      _kPayloadSection({_kTokenSection.End() + 1, End()}),
      _it(Begin() + _kHeader.SectionLength() + _kToken.SectionLength()) {}

Message::Message(sdk::models::coap::message::Section::Data& data,
                 sdk::models::coap::message::Header::Value header,
                 sdk::models::coap::message::Token::Value token,
                 sdk::models::coap::message::Section::Data const& payload,
                 option::Options options)
    : sdk::models::coap::message::Section(data),
      _kHeaderSection(
          {Begin(), Begin() + sdk::models::coap::message::Header::kLength}),
      _kHeader(_kHeaderSection, header),
      _kTokenSection({_kHeaderSection.End(),
                      _kHeaderSection.End() + Header().TokenLength()}),
      _kToken(_kTokenSection, token),
      _kPayloadSection({_kTokenSection.End() + 1,
                        _kTokenSection.End() + 1 + payload.size()}),
      _it(Begin() + _kHeader.SectionLength() + _kToken.SectionLength()) {
  // Options
  auto last_option = option::Option::Numbers::kInitial;

  for (auto const& option : options) {
    Section const kSection({_it, _it + option::Option::kLength});

    option::Option const kOption(kSection, last_option,
                                 {option.first, option.second});
    _it += kOption.SectionLength();
    last_option = option.first;
  }

  // Payload
  if (payload.size()) {
    *_it++ = 0xff;  // Payload marker

    std::copy(payload.begin(), payload.end(), _it);
    _it += payload.size();
  }
}

Section::LengthType Message::SectionLength() const { return _it - Begin(); }

sdk::models::coap::message::Header const& Message::Header() const {
  return _kHeader;
}

sdk::models::coap::message::Token const& Message::Token() const {
  return _kToken;
}

sdk::models::coap::message::Section Message::Payload() const {
  return _kPayloadSection;
}

}  // namespace sdk::models::coap::message
