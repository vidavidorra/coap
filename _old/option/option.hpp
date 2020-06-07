#pragma once

#include <cstdint>

#include "option/format.hpp"
#include "section.hpp"

namespace sdk::models::coap::message::option {

/**
 * Implements CoAP message option as described in RFC 7252 §12.2.
 * https://tools.ietf.org/html/rfc7252#section-12.2
 */
class Option : public Section {
 public:
  using Number = std::uint16_t;

  using Data = Section::Data;

  enum class Numbers : Number {
    kInitial = 0,

    // Option definitions (RFC 7252 §5.10).
    k3 = 3,    // Uri-Host
    k7 = 7,    // Uri-Port
    k11 = 11,  // Uri-Path
    k15 = 15,  // Uri-Query
    k35 = 35,  // Proxy-Uri
    k39 = 39,  // Proxy-Scheme
    k12 = 12,  // Content-Format
    k17 = 17,  // Accept
    k14 = 14,  // Max-Age
    k4 = 4,    // ETag
    k8 = 8,    // Location-Path
    k20 = 20,  // Location-Query
    k1 = 1,    // If-Match
    k5 = 5,    // If-None-Match
    k60 = 60,  // Size1
    kUriHost = k3,
    kUriPort = k7,
    kUriPath = k11,
    kUriQuery = k15,
    kProxyUri = k35,
    kProxyScheme = k39,
    kContentFormat = k12,
    kAccept = k17,
    kMaxAge = k14,
    kETag = k4,
    kLocationPath = k8,
    kLocationQuery = k20,
    kIfMatch = k1,
    kIfNoneMatch = k5,
    kSize1 = k60,

    /**
     * Size2 and Size1 options (RFC 7959 §4).
     *
     * The Size1 option is specified in both the RFC 7252 and RFC 7959 and is
     * included in the RFC7252 section of these options.
     */
    k28 = 28,  // Size2
    kSize2 = k28,

    // Block2 and Block1 options (RFC 7959 §2.1).s
    k27 = 27,  // Block1
    k23 = 23,  // Block2
    kBlock1 = k27,
    kBlock2 = k23,

    // withthegrid options
    k2109 = 2109,  // Authentication token
    k2141 = 2141,  // Payload version
    k2205 = 2205,  // Payload generation timestamp
  };

  using Values = Section::Sections;

  using Value = struct Value {
    Numbers number;
    Values values;
  };

  static Section::LengthType const kMaximumValueLength = 64;

  static Section::LengthType const kLength =
      Format::kLength + kMaximumValueLength;

  Option(Section const& section, Numbers last_number);

  Option(Section const& section, Numbers last_number, Value const& option);

  operator Value() const;

  Section::LengthType SectionLength() const;

 private:
  void ValidateLength() const final;

  Section::Iterator _it;
  Value _option;
};

}  // namespace sdk::models::coap::message::option
