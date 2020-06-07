import Header from './header';
import TestValue from './test-value';
import chalk from 'chalk';

class GenerateTestValues {
  private readonly outerValueCount = 2;
  private testValues: TestValue[] = [];

  createValues(): void {
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

    versions.sort((a, b) => a - b);
    types.sort((a, b) => a - b);
    tokenLengths.sort((a, b) => a - b);
    codes.sort((a, b) => a - b);
    messageIds.sort((a, b) => a - b);

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
              this.testValues.push(testValue);
            });
          });
        });
      });
    });

    //
    this.testValues.forEach((e) => {
      console.log(e.toString());
    });
  }
}

const gtv = new GenerateTestValues();
gtv.createValues();

console.log(chalk.green(`Generated ${1} test elements!`));
