#include "type.hpp"

namespace coap {

Type::Type(DataType value)
    : _kValueBitMask(0x03),
      _kValue(static_cast<Value>(value & _kValueBitMask)) {}

Type::Type(Value value)
    : _kValueBitMask(0x03),
      _kValue(
          static_cast<Value>(static_cast<DataType>(value) & _kValueBitMask)) {}

Type::operator DataType() const { return static_cast<DataType>(_kValue); }

Type::operator Value() const { return _kValue; }

bool Type::IsConfirmable() const { return _kValue == Value::kConfirmable; }

bool Type::IsNonConfirmable() const {
  return _kValue == Value::kNonConfirmable;
}

bool Type::IsAcknowledgement() const {
  return _kValue == Value::kAcknowledgement;
}

bool Type::IsReset() const { return _kValue == Value::kReset; }

}  // namespace coap
