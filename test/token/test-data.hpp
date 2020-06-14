#include <vector>

#include "token.hpp"

namespace coap::test {

using TestValue = struct {
  struct {
    coap::Token::Value value;
    coap::Token::Vector vector_value;
  } token;
};

std::vector<TestValue> const
    kTestValues =
        {
            TestValue{
                .token =
                    {
                        .value =
                            {
                                .data = {},
                                .length = 0,
                            },
                        .vector_value = {},
                    },
            },
            TestValue{
                .token =
                    {
                        .value =
                            {
                                .data = {0x55},
                                .length = 1,
                            },
                        .vector_value = {0x55},
                    },
            },
            TestValue{
                .token =
                    {
                        .value =
                            {
                                .data = {0x55, 0x55},
                                .length = 2,
                            },
                        .vector_value = {0x55, 0x55},
                    },
            },
            TestValue{
                .token =
                    {
                        .value =
                            {
                                .data = {0x55, 0x55, 0x55},
                                .length = 3,
                            },
                        .vector_value = {0x55, 0x55, 0x55},
                    },
            },
            TestValue{
                .token =
                    {
                        .value =
                            {
                                .data = {0x55, 0x55, 0x55, 0x55},
                                .length = 4,
                            },
                        .vector_value = {0x55, 0x55, 0x55, 0x55},
                    },
            },
            TestValue{
                .token =
                    {
                        .value =
                            {
                                .data = {0x55, 0x55, 0x55, 0x55, 0x55},
                                .length = 5,
                            },
                        .vector_value = {0x55, 0x55, 0x55, 0x55, 0x55},
                    },
            },
            TestValue{
                .token =
                    {
                        .value =
                            {
                                .data = {0x55, 0x55, 0x55, 0x55, 0x55, 0x55},
                                .length = 6,
                            },
                        .vector_value = {0x55, 0x55, 0x55, 0x55, 0x55, 0x55},
                    },
            },
            TestValue{
                .token =
                    {
                        .value =
                            {
                                .data = {0x55, 0x55,
                                         0x55, 0x55, 0x55, 0x55, 0x55},
                                .length = 7,
                            },
                        .vector_value = {0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
                                         0x55},
                    },
            },
            TestValue{
                .token =
                    {
                        .value =
                            {
                                .data = {0x55, 0x55,
                                         0x55, 0x55, 0x55, 0x55, 0x55, 0x55},
                                .length = 8,
                            },
                        .vector_value = {0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
                                         0x55, 0x55},
                    },
            },
};

}  // namespace coap::test
