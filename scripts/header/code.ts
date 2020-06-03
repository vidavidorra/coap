import Field from './field';

class Code extends Field {
  constructor(public value: number) {
    super(2);
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
}

export default Code;
