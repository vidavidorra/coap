import Field from './field';

interface Value {
  name: string;
  confirmable: boolean;
  acknowledgement: boolean;
  reset: boolean;
}

class Type extends Field {
  private readonly valueType = 'Type::Value';
  private readonly types = new Map([
    [
      0,
      {
        name: 'kConfirmable',
        confirmable: true,
        acknowledgement: false,
        reset: false,
      },
    ],
    [
      1,
      {
        name: 'kNonConfirmable',
        confirmable: false,
        acknowledgement: false,
        reset: false,
      },
    ],
    [
      2,
      {
        name: 'kAcknowledgement',
        confirmable: false,
        acknowledgement: true,
        reset: false,
      },
    ],
    [
      3,
      {
        name: 'kReset',
        confirmable: false,
        acknowledgement: false,
        reset: true,
      },
    ],
  ]);

  readonly typeValue: Value;

  constructor(value: number) {
    super(2);
    this.value = value;

    this.validate();
  }

  get(): Value {
    this.validate();
    return this.types.get(this.value);
  }

  toString(): string {
    return `${this.valueType}::${this.get().name}`;
  }

  private validate(): void {
    if (this.value > this.types.size) {
      throw new Error(`Value '${this.value} is not an available type.`);
    }

    if (this.maximumValue() !== this.types.size - 1) {
      console.log(this.maximumValue(), this.types.size);
      throw new Error("The maximum value and available types don't match.");
    }
  }
}

export default Type;
export { Value };
