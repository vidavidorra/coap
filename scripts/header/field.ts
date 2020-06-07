class Field {
  value: number;

  constructor(
    public readonly bits: number,
    private readonly maximum: number | undefined = undefined,
  ) {
    this.value = 0;
  }

  minimumValue(): number {
    return 0;
  }

  maximumValue(): number {
    if (this.maximum) {
      return this.maximum;
    }

    return 2 ** this.bits - 1;
  }
}

export default Field;
