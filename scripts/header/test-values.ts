import Header from './header';
import TestValue from './test-value';

function numericSort(a: number, b: number): number {
  return a - b;
}

class TestValues {
  private readonly outerValueCount = 2;
  private values: TestValue[] = [];

  generate(): number {
    this.generateValues();

    this.values.forEach((e) => {
      console.log(e.toString());
    });

    return this.values.length;
  }

  private generateValues(): void {
    const header = new Header(0, 0, 0, 0, 0);
    const versions = [1];
    const types = [];
    const tokenLengths = [];
    const codes = [];
    const messageIds = [];

    for (let i = 0; i < this.outerValueCount; i++) {
      types.push(header.type.minimumValue() + i);
      types.push(header.type.maximumValue() - i);
      tokenLengths.push(header.tokenLength.minimumValue() + i);
      tokenLengths.push(header.tokenLength.maximumValue() - i);
      codes.push(header.code.minimumValue() + i);
      codes.push(header.code.maximumValue() - i);
      messageIds.push(header.messageId.minimumValue() + i);
      messageIds.push(header.messageId.maximumValue() - i);
    }

    versions.sort(numericSort);
    types.sort(numericSort);
    tokenLengths.sort(numericSort);
    codes.sort(numericSort);
    messageIds.sort(numericSort);

    versions.forEach((version) => {
      types.forEach((type) => {
        tokenLengths.forEach((tokenLength) => {
          codes.forEach((code) => {
            messageIds.forEach((messageId) => {
              const testValue = new TestValue(
                new Header(version, type, tokenLength, code, messageId),
              );

              if (version === 1) {
                testValue.properties.versionIsValid = true;
              }

              if (tokenLength <= 8) {
                testValue.properties.containsFormatError = false;
              }
              testValue.properties.isValid = true;
              this.values.push(testValue);
            });
          });
        });
      });
    });
  }
}

export default TestValues;
