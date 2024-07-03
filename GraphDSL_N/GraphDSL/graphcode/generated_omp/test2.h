#ifndef GENCPP_TEST2_H
#define GENCPP_TEST2_H
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<atomic>
#include<omp.h>
#include"../graph.hpp"
#include"../atomicUtil.h"

void test1(graph& g , float* features , int* labels);

#endif
