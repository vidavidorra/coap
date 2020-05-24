#include "type.hpp"

namespace coap {

Type::Type(DataType value) noexcept
    : _kValueBitMask(0x03),
      _kValue(static_cast<Value>(value & _kValueBitMask)) {}

Type::Type(Value value) noexcept
    : _kValueBitMask(0x03),
      _kValue(
          static_cast<Value>(static_cast<DataType>(value) & _kValueBitMask)) {}

Type::operator DataType() const noexcept {
  return static_cast<DataType>(_kValue);
}

Type::operator Value() const noexcept { return _kValue; }

bool Type::IsConfirmable() const noexcept {
  return _kValue == Value::kConfirmable;
}

bool Type::IsNonConfirmable() const noexcept {
  return _kValue == Value::kNonConfirmable;
}

bool Type::IsAcknowledgement() const noexcept {
  return _kValue == Value::kAcknowledgement;
}

bool Type::IsReset() const noexcept { return _kValue == Value::kReset; }

}  // namespace coap
