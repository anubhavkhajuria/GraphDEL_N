#ifndef GENCPP_TEST2_H
#define GENCPP_TEST2_H
#include <CL/sycl.hpp>
#include <iostream>
#include <fstream>
#include "../graph.hpp"
using namespace sycl;

void test1(graph& g,float* features,int* labels)
{
  queue Q(default_selector_v);
  std::cout << "Selected device: " << Q.get_device().get_info<info::device::name>() << std::endl;
  // CSR BEGIN
  int V = g.num_nodes();
  int E = g.num_edges();

  printf("#nodes:%d\n",V);
  printf("#edges:%d\n",E);
  int* edgeLen = g.getEdgeLen();

  int *h_meta;
  int *h_data;
  int *h_src;
  int *h_weight;
  int *h_rev_meta;

  h_meta = (int *)malloc( (V+1)*sizeof(int));
  h_data = (int *)malloc( (E)*sizeof(int));
  h_src = (int *)malloc( (E)*sizeof(int));
  h_weight = (int *)malloc( (E)*sizeof(int));
  h_rev_meta = (int *)malloc( (V+1)*sizeof(int));

  for(int i=0; i<= V; i++) {
    int temp = g.indexofNodes[i];
    h_meta[i] = temp;
    temp = g.rev_indexofNodes[i];
    h_rev_meta[i] = temp;
  }

  for(int i=0; i< E; i++) {
    int temp = g.edgeList[i];
    h_data[i] = temp;
    temp = g.srcList[i];
    h_src[i] = temp;
    temp = edgeLen[i];
    h_weight[i] = temp;
  }


  int* d_meta;
  int* d_data;
  int* d_src;
  int* d_weight;
  int* d_rev_meta;
  bool* d_modified_next;

  d_meta=malloc_device<int>((1+V), Q);
  d_data=malloc_device<int>((E), Q);
  d_src=malloc_device<int>((E), Q);
  d_weight=malloc_device<int>((E), Q);
  d_rev_meta=malloc_device<int>((V+1), Q);
  d_modified_next=malloc_device<bool>((V), Q);

  Q.submit([&](handler &h)
    { h.memcpy(  d_meta,   h_meta, sizeof(int)*(V+1)); })
  .wait();
  Q.submit([&](handler &h)
    { h.memcpy(  d_data,   h_data, sizeof(int)*(E)); })
  .wait();
  Q.submit([&](handler &h)
    { h.memcpy(   d_src,    h_src, sizeof(int)*(E)); })
  .wait();
  Q.submit([&](handler &h)
    { h.memcpy(d_weight, h_weight, sizeof(int)*(E)); })
  .wait();
  Q.submit([&](handler &h)
    { h.memcpy(d_rev_meta, h_rev_meta, sizeof(int)*((V+1))); })
  .wait();

  // CSR END
  //LAUNCH CONFIG
  int NUM_THREADS = 1048576;
  int stride = NUM_THREADS;

  // TIMER START
  std::chrono::steady_clock::time_point tic = std::chrono::steady_clock::now();

  //DECLAR DEVICE AND HOST vars in params
  float* d_features;
  d_features=malloc_device<float>(V, Q);

  int* d_labels;
  d_labels=malloc_device<int>(V, Q);


  //BEGIN DSL PARSING 
  int num_epoch = 100; // asst in main

  int num_layer = 5; // asst in main

  int bajkd = ; // asst in main

  int x = 1; // asst in main

  Q.submit([&](handler &h){ h.parallel_for(NUM_THREADS, [=](id<1> nod){for (; nod < V; nod += NUM_THREADS){ // BEGIN KER FUN via ADDKERNEL
    // for all else part
    for (int edge = d_meta[nod]; edge < d_meta[nod+1]; edge++) { // FOR NBR ITR 
      int n = d_data[edge];
      if (d_labels[n] == d_labels[nod]){ // if filter begin 

      } // if filter end

    } //  end FOR NBR ITR. TMP FIX!
  }
}); }).wait(); // end KER FUNC


//TIMER STOP
std::chrono::steady_clock::time_point toc = std::chrono::steady_clock::now();
std::cout<<"Time required: "<<std::chrono::duration_cast<std::chrono::microseconds>(toc - tic).count()<<"[µs]"<<std::endl;

Q.submit([&](handler &h)
{ h.memcpy(features, d_features, sizeof(float)*(V)); })
.wait();
Q.submit([&](handler &h)
{ h.memcpy(  labels, d_labels, sizeof(int)*(V)); })
.wait();
} //end FUN

#endif
