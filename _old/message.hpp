#pragma once

#include "header.hpp"
#include "option/options.hpp"
#include "section.hpp"
#include "token.hpp"

namespace sdk::models::coap::message {

/**
 * Implements CoAP message as described in RFC 7252 §3.
 * https://tools.ietf.org/html/rfc7252#section-3
 */
class Message : public sdk::models::coap::message::Section {
 public:
  using Data = Section::Data;

  static sdk::models::coap::message::Section::LengthType const kMaximumLength =
      1280;

  static sdk::models::coap::message::Section::Element const kPayloadMarker =
      0xff;

  Message(sdk::models::coap::message::Section::Data& data);

  Message(sdk::models::coap::message::Section::Data& data,
          sdk::models::coap::message::Header::Value header,
          sdk::models::coap::message::Token::Value token,
          sdk::models::coap::message::Section::Data const& payload,
          option::Options options);

  Section::LengthType SectionLength() const;

  sdk::models::coap::message::Header const& Header() const;

  sdk::models::coap::message::Token const& Token() const;

  sdk::models::coap::message::Section Payload() const;

 private:
  /**
   * | Name           | Size     | Remaining    |
   * | -------------- | -------- | ------------ |
   * |                |          | 1280         |
   * | Header         | 4        | 1276         |
   * | Token          | 0 - 8    | 1268 - 1276  |
   * | Options        | 0 - 243  | 1025 - 1276  |
   * | Payload marker | 1        | 1024 - 1275  |
   * | Payload        | 0 - 1024 | 0    - 1275  |
   */
  sdk::models::coap::message::Section const _kHeaderSection;
  sdk::models::coap::message::Header const _kHeader;
  sdk::models::coap::message::Section const _kTokenSection;
  sdk::models::coap::message::Token const _kToken;
  sdk::models::coap::message::Section const _kPayloadSection;
  Section::Iterator _it;
};

}  // namespace sdk::models::coap::message
