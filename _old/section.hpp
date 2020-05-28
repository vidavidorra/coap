#pragma once

#include <cstdint>
#include <list>
#include <vector>

namespace sdk::models::coap::message {

class Section {
 public:
  using Element = std::uint8_t;

  using Data = std::vector<Element>;

  using LengthType = std::uint16_t;

  using Iterator = Data::iterator;

  using Value = struct Value {
    Iterator begin;
    Iterator end;
  };

  using Values = std::list<Value>;

  using Sections = std::list<Section>;

  Section(Value section);

  Section(Data& data);

  bool operator==(Section const& other) const;

  Iterator Begin() const;

  Iterator End() const;

  LengthType SectionLength() const;

 protected:
  virtual void ValidateLength() const {};

  bool LengthIsBetween(LengthType minimum_length,
                       LengthType maximum_length = 0) const;

  bool LengthEquals(LengthType length) const;

 private:
  Value const _kSection;
};

}  // namespace sdk::models::coap::message
