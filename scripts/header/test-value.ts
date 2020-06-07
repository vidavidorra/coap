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
      `.code = ${this.header.code.toString()},`,
      `.token_length = ${this.header.tokenLength.value},`,
      `.type = ${this.header.type.toString()},`,
      `.version = ${this.header.version.value},`,
      '}},',
      '.properties = {',
      `.version_is_valid = ${this.properties.versionIsValid},`,
      `.contains_format_error = ${this.properties.containsFormatError},`,
      `.is_valid = ${this.properties.isValid},`,
      '},',
      '},',
    ].join(' ');
  }
}

export default TestValue;
export { Properties };
