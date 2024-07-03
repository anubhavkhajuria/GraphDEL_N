// FOR BC: nvcc bc_dsl_v2.cu -arch=sm_60 -std=c++14 -rdc=true # HW must support CC 6.0+ Pascal or after
#ifndef GENCPP_TEST2_H
#define GENCPP_TEST2_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <cuda.h>
#include "../graph.hpp"
#include "../libcuda.cuh"
#include <cooperative_groups.h>

void test1(graph& g,float* features,int* labels);



__device__ int num_epoch ; // DEVICE ASSTMENT in .h

__device__ int num_layer ; // DEVICE ASSTMENT in .h

__device__ int bajkd ; // DEVICE ASSTMENT in .h

__device__ int x ; // DEVICE ASSTMENT in .h


#endif
