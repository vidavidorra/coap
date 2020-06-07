import Field from './field';

interface Value {
  name: string;
}

class Code extends Field {
  private readonly valueType = 'Code::Value';
  private readonly codes = new Map([
    [0, { name: 'k000' }],
    [1, { name: 'k001' }],
    [2, { name: 'k002' }],
    [3, { name: 'k003' }],
    [4, { name: 'k004' }],
  ]);

  constructor(value: number) {
    super(8);
    this.value = value;
  }

  humanReadable(): string {
    /**
     * RFC 7252 §5.2: As a human-readable notation for specifications and
     * protocol diagnostics, CoAP code numbers including the response Code are
     * documented in the format "c.dd", where "c" is the class in decimal, and
     * "dd" is the detail as a two-digit decimal.  For example, "Forbidden" is
     * written as 4.03 -- indicating an 8-bit code value of hexadecimal 0x83
     * (4*0x20+3) or decimal 131 (4*32+3).
     * - https://tools.ietf.org/html/rfc7252#section-5.2
     */

    const codeClass = Math.floor(this.value / 0x20);
    const codeDetail = this.value - codeClass * 0x20;

    return `${codeClass}.${codeDetail.toString(10).padStart(2, '0')}`;
  }

  get(): Value | undefined {
    return this.codes.get(this.value);
  }

  toString(): string {
    const value = this.get();
    if (value) {
      return `${this.valueType}::${value.name}`;
    }

    return `static_cast<${this.valueType}>(${this.value})`;
  }
}

export default Code;
