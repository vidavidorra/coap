#pragma once

#include <cstdint>

namespace coap {

/**
 * Implements CoAP message type as described in RFC 7252 §3.
 * https://tools.ietf.org/html/rfc7252#section-3
 */
class Type {
 public:
  /**
   * The type is represented by two bits. For values larger than those that can
   * be represented by two bits, so zero up to and including four, the other
   * bits are ignored.
   */
  using DataType = std::uint8_t;

  enum class Value : DataType {
    kConfirmable = 0,
    kNonConfirmable,
    kAcknowledgement,
    kReset,
  };

  Type(DataType value);

  Type(Value value);

  operator DataType() const;

  operator Value() const;

  bool IsConfirmable() const;

  bool IsNonConfirmable() const;

  bool IsAcknowledgement() const;

  bool IsReset() const;

 private:
  DataType const _kValueBitMask;
  Value const _kValue;
};

}  // namespace coap
