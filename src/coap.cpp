#include "code.hpp"

namespace coap {

/**
 * I want a fluent-type interface so I can do something like the following. The
 * data should be externally defined so its easy to manage externally.
 *
 * coap(data, type, code, message_id)
 *   .token(0x1234)
 *   .option(2109, {0xaa, 0x55})
 *   .option(10, 5)
 *   .option(Option::kUriPath, "/test/file.txt")
 *   .payload({0x00, 0x11, 0x22, 0x33, 0x44, 0x55})
 */

class Coap {
 public:
  Coap() = default;
};

}  // namespace coap
