#include "code.hpp"

namespace coap {

Code::Code(Type code) : _kCode({.value = code}) {}

Code::Code(Value code) : _kCode({.value = static_cast<Type>(code)}) {}

Code::Code(Parts parts) : _kCode({.parts = parts}) {}

Code::operator Type() const { return _kCode.value; }

Code::operator Value() const { return static_cast<Value>(_kCode.value); }

Code::operator Parts() const { return _kCode.parts; }

bool Code::IsRequest() const { return _kCode.parts.class_ == Class::kRequest; }

bool Code::IsResponse() const { return !IsRequest(); }

bool Code::IsSuccess() const {
  return _kCode.parts.class_ == Class::kResponseSuccess;
}

bool Code::IsClientError() const {
  return _kCode.parts.class_ == Class::kResponseClientError;
}

bool Code::IsServerError() const {
  return _kCode.parts.class_ == Class::kResponseServerError;
}

}  // namespace coap
