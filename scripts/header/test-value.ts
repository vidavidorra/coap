import Header from './header';

interface Properties {
  versionIsValid: boolean;
  containsFormatError: boolean;
  isValid: boolean;
}

class TestValue {
  header: Header;
  properties: {
    versionIsValid: boolean;
    containsFormatError: boolean;
    isValid: boolean;
  } = {
    versionIsValid: false,
    containsFormatError: true,
    isValid: false,
  };

  constructor(header: Header) {
    this.header = header;
  }

  toString(): string {
    return [
      'TestValue{.header =',
      `{.type = ${this.header.byteString()},`,
      '.value = {',
      `.message_id = ${this.header.messageId.value},`,
      `.code = static_cast<Code::Value>(${this.header.code.value}),`,
      `.token_length = ${this.header.tokenLength.value},`,
      `.type = ${this.header.type.toString()},`,
      `.version = ${this.header.version.value},`,
      '}},',
      '.properties = {',
      `${this.properties.versionIsValid},`,
      `${this.properties.containsFormatError},`,
      `${this.properties.isValid},`,
      '}},',
    ].join(' ');
  }
}

export default TestValue;
export { Properties };

/*
TestValue{.header = {.type = {0x40, 0x30, 0x20, 0x10},
                      .value =
                          {
                              .message_id = 0,
                              .code = Code::Value::kEmpty,
                              .token_length = 0,
                              .type = Type::Value::kConfirmable,
                              .version = 1,
                          }},
          .properties = {true, false, true}},
*/
