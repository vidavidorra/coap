#include <vector>

#include "token.hpp"

namespace coap::test {

using TestValue = struct {
  struct {
    coap::Token::Value value;
    coap::Token::VectorValue vector_value;
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
                                .size = 0,
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
                                .size = 1,
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
                                .size = 2,
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
                                .size = 3,
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
                                .size = 4,
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
                                .size = 5,
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
                                .size = 6,
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
                                .size = 7,
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
                                .size = 8,
                            },
                        .vector_value = {0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
                                         0x55, 0x55},
                    },
            },
};

}  // namespace coap::test
