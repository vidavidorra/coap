#pragma once

#include <cstdint>

namespace coap {

/**
 * Implements CoAP message codes as described in RFC 7252 §5 and §12.1.
 * - https://tools.ietf.org/html/rfc7252#section-5
 * - https://tools.ietf.org/html/rfc7252#section-12.1
 */
class Code {
 public:
  using Type = std::uint8_t;

  /**
   * Code classes as described in RFC 7252 §3 and §5.2.
   * - https://tools.ietf.org/html/rfc7252#section-3
   * - https://tools.ietf.org/html/rfc7252#section-5.2
   */
  enum class Class : Type {
    kRequest = 0,
    kResponseSuccess = 2,
    kResponseClientError = 4,
    kResponseServerError = 5,
  };

  /**
   * Code construction as described in RFC 7252 §5.2, Figure 9.
   * - https://tools.ietf.org/html/rfc7252#section-5.2
   */
  using Parts = struct {
    Type detail : 5;
    // Trailing underscore because `class` is a reserved word.
    Class class_ : 3;
  };
  ////////////////////////
  /**
   * Codes as described in RFC 7252 §12.1.
   * - https://tools.ietf.org/html/rfc7252#section-12.1
   *
   * Contains t
   * - Empty message code (RFC 7252 §12.1)
   * - CoAP Method Codes sub-registry (RFC 7252 §12.1.2)
   * - CoAP Response Codes sub-registry (RFC 7252 §12.1.2)
   */
  enum class Value : Type {
    k000 = 0x00,  // Empty message.
    kEmpty = k000,

    k001 = 0x01,  // Method: GET.
    k002 = 0x02,  // Method: POST.
    k003 = 0x03,  // Method: PUT.
    k004 = 0x04,  // Method: DELETE.
    kGet = k001,
    kPost = k002,
    kPut = k003,
    kDelete = k004,

    k201 = 0x41,  // Response: Created.
    k202 = 0x42,  // Response: Deleted.
    k203 = 0x43,  // Response: Valid.
    k204 = 0x44,  // Response: Changed.
    k205 = 0x45,  // Response: Content.
    k400 = 0x80,  // Response: Bad Request.
    k401 = 0x81,  // Response: Unauthorized.
    k402 = 0x82,  // Response: Bad Option.
    k403 = 0x83,  // Response: Forbidden.
    k404 = 0x84,  // Response: Not Found.
    k405 = 0x85,  // Response: Method Not Allowed.
    k406 = 0x86,  // Response: Not Acceptable.
    k412 = 0x8c,  // Response: Precondition Failed.
    k413 = 0x8d,  // Response: Request Entity Too Large.
    k415 = 0x8f,  // Response: Unsupported Content-Format.
    k500 = 0xa0,  // Response: Internal Server Error.
    k501 = 0xa1,  // Response: Not Implemented.
    k502 = 0xa2,  // Response: Bad Gateway.
    k503 = 0xa3,  // Response: Service Unavailable.
    k504 = 0xa4,  // Response: Gateway Timeout.
    k505 = 0xa5,  // Response: Proxying Not Supported.
  };

  Code(Type code);

  Code(Value code);

  Code(Parts parts);

  operator Type() const;

  operator Value() const;

  operator Parts() const;

  bool IsRequest() const;

  bool IsResponse() const;

  bool IsSuccess() const;

  bool IsClientError() const;

  bool IsServerError() const;

 private:
  // RFC 7252 §5.2, Figure 9.
  union ValueFields {
    Type value;
    Parts parts;
  };

  ValueFields const _kCode;
};

}  // namespace coap
