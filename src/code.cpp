#include "code.hpp"

namespace coap {

Code::Code(Type value) noexcept : _kValue({.value = value}) {}

Code::Code(Value value) noexcept
    : _kValue({.value = static_cast<Type>(value)}) {}

Code::Code(Parts value) noexcept : _kValue({.parts = value}) {}

Code::operator Type() const noexcept { return _kValue.value; }

Code::operator Value() const noexcept {
  return static_cast<Value>(_kValue.value);
}

Code::operator Parts() const noexcept { return _kValue.parts; }

bool Code::IsRequest() const noexcept {
  return _kValue.parts.class_ == Class::kRequest;
}

bool Code::IsResponse() const noexcept { return !IsRequest(); }

bool Code::IsSuccess() const noexcept {
  return _kValue.parts.class_ == Class::kResponseSuccess;
}

bool Code::IsClientError() const noexcept {
  return _kValue.parts.class_ == Class::kResponseClientError;
}

bool Code::IsServerError() const noexcept {
  return _kValue.parts.class_ == Class::kResponseServerError;
}

}  // namespace coap
