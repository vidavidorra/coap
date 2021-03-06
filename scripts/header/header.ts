import { Code, Field, Type } from '..';
import packet from 'coap-packet';

class Header {
  // See the C++ header class for documentation on the header construction.
  readonly byteCount = 4;
  version = new Field(2);
  type: Type;
  tokenLength = new Field(4, 8);
  code: Code;
  messageId = new Field(16);

  constructor(
    version: number,
    type: number,
    tokenLength: number,
    code: number,
    messageId: number,
  ) {
    this.version.value = version;
    this.type = new Type(type);
    this.tokenLength.value = tokenLength;
    this.code = new Code(code);
    this.messageId.value = messageId;
  }

  byteString(): string {
    const token = Buffer.from(new ArrayBuffer(this.tokenLength.value));
    const buffer = packet.generate({
      token,
      confirmable: this.type.get().confirmable,
      ack: this.type.get().acknowledgement,
      reset: this.type.get().reset,
      code: this.code.humanReadable(),
      messageId: this.messageId.value,
    });
    if (this.messageId.value === 0) {
      /**
       * The coap-packet package checks if the messageId property exists and if
       * the property is zero or doesn't exist it is generated. To circumvent
       * this we override the last 16 bits, representing the message ID.
       * https://github.com/mcollina/coap-packet/blob/v0.1.14/index.js#L292
       */
      buffer.writeInt16BE(0, 2);
    }

    return `{${this.bufferToHex(buffer)}}`;
  }

  bufferToHex(buffer: Buffer): string {
    const prefix = '0x';
    return [
      prefix,
      [...new Uint8Array(buffer.slice(0, this.byteCount))]
        .map((e) => e.toString(16).padStart(2, '0'))
        .join(`, ${prefix}`),
    ].join('');
  }
}

export default Header;
