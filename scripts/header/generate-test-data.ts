import TestValues from './test-values';
import chalk from 'chalk';

const testValues = new TestValues();
const count = testValues.generate();

console.log(chalk.green(`Generated ${count} test elements!`));
