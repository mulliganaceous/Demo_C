/* ------------
 * This code is provided solely for the personal and private use of
 * students taking the CSC367H5 course at the University of Toronto.
 * Copying for purposes other than this use is expressly prohibited.
 * All forms of distribution of this code, whether as given or with
 * any changes, are expressly prohibited.
 *
 * Authors: Bogdan Simion, Felipe de Azevedo Piovezan
 *
 * All of the files in this directory and all subdirectories are:
 * Copyright (c) 2019 Bogdan Simion
 * -------------
 */

#include "kernels.h"

#include <stdio.h>
#include <string>
#define IDCOLROW                                   \
  int idx = blockIdx.x * blockDim.x + threadIdx.x; \
  int row = idx / width;                           \
  int col = idx % width;

void run_kernel2(const int8_t *filter, int32_t dimension, 
                 const int32_t *input, int32_t *output, 
                 int32_t width, int32_t height, int32_t smallest, int32_t largest) {
  // Setting for single-thread-pixel
  const unsigned THREADS_PER_BLOCK = 512;
  dim3 threads(THREADS_PER_BLOCK, 1);
  dim3 blocks((width * height + THREADS_PER_BLOCK - 1) / THREADS_PER_BLOCK);

  // launch kernel
  kernel2<<<blocks, threads>>>(filter, dimension, input, output, width, height);
  normalize2<<<blocks, threads>>>(output, width, height, smallest, largest);
}

__global__ void kernel2(const int8_t *filter, int32_t dimension,
                        const int32_t *input, int32_t *output, 
                        int32_t width, int32_t height) 
{
  IDCOLROW
  int pix = 0;

  // Perform (no reduction needed)
  if (idx < width * height) {
    // Perform filtering
    for (int ip = 0; ip < dimension; ip++) {
      for (int jp = 0; jp < dimension; jp++) {
        int row_cur = row + ip - (dimension-1)/2;
        int col_cur = col + jp - (dimension-1)/2;
        if (row_cur >= 0 && row_cur < height && col_cur >= 0 && col_cur < width) {
          pix += filter[dimension*ip + jp]*input[width*row_cur + col_cur];
        }
      }
    }
    // Update to shared data (a pointer)
    output[width*row + col] = pix;
  }
  __syncthreads();
}

__global__ void normalize2(int32_t *image, int32_t width, int32_t height,
                           int32_t smallest, int32_t biggest) 
{
  int idx = blockIdx.x * blockDim.x + threadIdx.x;
  if (smallest == biggest || idx >= width*height)
    return;
  // Perform (no reduction needed)
  if (idx < width * height) {
    image[idx] = ((image[idx] - smallest)*255) / (biggest - smallest);
  }
  __syncthreads();
}
