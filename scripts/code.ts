import Field from './field';

interface Value {
  name: string;
}

class Code extends Field {
  private readonly valueType = 'Code::Value';
  private readonly codes = new Map([
    [0x00, { name: 'k000' }],
    [0x01, { name: 'k001' }],
    [0x02, { name: 'k002' }],
    [0x03, { name: 'k003' }],
    [0x04, { name: 'k004' }],
    [0x41, { name: 'k201' }],
    [0x42, { name: 'k202' }],
    [0x43, { name: 'k203' }],
    [0x44, { name: 'k204' }],
    [0x45, { name: 'k205' }],
    [0x80, { name: 'k400' }],
    [0x81, { name: 'k401' }],
    [0x82, { name: 'k402' }],
    [0x83, { name: 'k403' }],
    [0x84, { name: 'k404' }],
    [0x85, { name: 'k405' }],
    [0x86, { name: 'k406' }],
    [0x8c, { name: 'k412' }],
    [0x8d, { name: 'k413' }],
    [0x8f, { name: 'k415' }],
    [0xa0, { name: 'k500' }],
    [0xa1, { name: 'k501' }],
    [0xa2, { name: 'k502' }],
    [0xa3, { name: 'k503' }],
    [0xa4, { name: 'k504' }],
    [0xa5, { name: 'k505' }],
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
export { Value };
