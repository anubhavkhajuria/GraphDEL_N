// FOR BC: nvcc bc_dsl_v2.cu -arch=sm_60 -std=c++14 -rdc=true # HW must support CC 6.0+ Pascal or after
#ifndef GENCPP_TEST_H
#define GENCPP_TEST_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <cuda.h>
#include "../graph.hpp"
#include "../libcuda.cuh"
#include <cooperative_groups.h>

void forward_prop(graph& g,float* features,int* labels,int layer
);

__device__ int layer ;


__device__ int bajkd ; // DEVICE ASSTMENT in .h

__global__ void forward_prop_kernel(int V, int E, int* d_meta, int* d_data,int* d_labels){ // BEGIN KER FUN via ADDKERNEL
  float num_nodes  = V;
  unsigned v = blockIdx.x * blockDim.x + threadIdx.x;
  if(v >= V) return;
  for (int edge = d_meta[v]; edge < d_meta[v+1]; edge++) { // FOR NBR ITR 
    int n = d_data[edge];
    if (d_labels[n] == d_labels[nod]){ // if filter begin 

    } // if filter end

  } //  end FOR NBR ITR. TMP FIX!
} // end KER FUNC
void Backward_prop(int* xyzzz);



void run(graph& g,float* features,int* labels);



__device__ int num_epoch ; // DEVICE ASSTMENT in .h

__device__ int num_layer ; // DEVICE ASSTMENT in .h

__device__ int x ; // DEVICE ASSTMENT in .h


#endif
