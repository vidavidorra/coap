import types, { Type } from './type';
import Code from './code';
import chalk from 'chalk';
import packet from 'coap-packet';

interface Properties {
  versionIsValid: boolean;
  containsFormatError: boolean;
  isValid: boolean;
}

interface Header {
  type: Buffer;
  value: number;
}

interface Value {
  version: number;
  type: number;
  tokenLength: number;
  code: number;
  messageId: number;
}

class TestValue {}

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

const tokenLengths = [...Array(8 + 1).keys()];
const codeBits = 8;
const codes: Code[] = [];

[0, 1, 2 ** codeBits - 2, 2 ** codeBits - 1].forEach((code) => {
  codes.push(new Code(code));
});

const messageIdBits = 16;
// const messageIds = [...Array(2 ** 16).keys()];
const messageIds = [0, 1, 2 ** messageIdBits - 2, 2 ** messageIdBits - 1];

interface TestElement {
  type: Type;
  tokenLength: number;
  code: Code;
  messageId: number;
}

const testVector: TestElement[] = [];
types.forEach((type) => {
  tokenLengths.forEach((tokenLength) => {
    codes.forEach((code) => {
      messageIds.forEach((messageId) => {
        testVector.push({
          type,
          tokenLength,
          code,
          messageId,
        });
      });
    });
  });
});

testVector.forEach((e) => {
  const token = Buffer.from(new ArrayBuffer(e.tokenLength));
  const messagePacket = packet.generate({
    token,
    confirmable: e.type.confirmable,
    ack: e.type.acknowledgement,
    reset: e.type.reset,
    code: e.code.HumanReadable(),
    messageId: e.messageId,
  });

  const buffer = messagePacket;
  if (e.messageId === 0) {
    /**
     * For some reason the `packet.generate()` doesn't create the expected
     * output for message ID zero. The CoAP specification (RFC 7252) doesn't say
     * anything specific about this, so just override those two bytes with
     * zeroes to create the test vector.
     */
    buffer[2] = 0;
    buffer[3] = 0;
  }

  let header = '';
  const maxIndex = 4;
  buffer.slice(0, maxIndex).forEach((byte, index) => {
    header += `0x${byte.toString(16).padStart(2, '0')}`;
    if (index < maxIndex - 1) {
      header += ', ';
    }
  });
  const expected = [
    `Types::${e.type.cppName}`,
    e.tokenLength,
    e.code.code,
    e.messageId,
  ];

  console.log(
    [
      'TestValue{.header = {',
      header,
      '},',
      '.properties = {',
      expected.join(', '),
      '}},',
    ].join(' '),
  );
});

console.log(chalk.green(`Generated ${testVector.length} test elements!`));
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
