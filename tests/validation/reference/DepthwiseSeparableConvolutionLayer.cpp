/*
 * Copyright (c) 2017 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "DepthwiseConvolutionLayer.h"

#include "DepthwiseSeparableConvolutionLayer.h"

#include "ConvolutionLayer.h"
#include "Utils.h"

#include "tests/validation/Helpers.h"

namespace arm_compute
{
namespace test
{
namespace validation
{
namespace reference
{
// Depthwise separable convolution layer
template <typename T>
SimpleTensor<T> depthwise_separable_convolution_layer(const SimpleTensor<T> &src, const SimpleTensor<T> &depthwise_weights, const SimpleTensor<T> &depthwise_biases,
                                                      const TensorShape     &depthwise_out_shape,
                                                      const SimpleTensor<T> &pointwise_weights,
                                                      const SimpleTensor<T> &pointwise_biases, const TensorShape &dst_shape, const PadStrideInfo &depthwise_conv_info, const PadStrideInfo &pointwise_conv_info)
{
    // Compute reference
    SimpleTensor<T> depthwise_out = depthwise_convolution(src, depthwise_weights, depthwise_biases, depthwise_out_shape, depthwise_conv_info);
    SimpleTensor<T> dst           = convolution_layer(depthwise_out, pointwise_weights, pointwise_biases, dst_shape, pointwise_conv_info);

    return dst;
}

template SimpleTensor<float> depthwise_separable_convolution_layer(const SimpleTensor<float> &in, const SimpleTensor<float> &depthwise_weights, const SimpleTensor<float> &depthwise_biases,
                                                                   const TensorShape         &depthwise_out_shape,
                                                                   const SimpleTensor<float> &pointwise_weights, const SimpleTensor<float> &pointwise_biases, const TensorShape &dst_shape, const PadStrideInfo &depthwise_conv_info,
                                                                   const PadStrideInfo &pointwise_conv_info);
} // namespace reference
} // namespace validation
} // namespace test
} // namespace arm_compute
