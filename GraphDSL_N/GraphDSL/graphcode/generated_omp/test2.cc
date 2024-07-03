#include"test2.h"

void test1(graph& g , float* features , int* labels)
{
  int num_epoch = 100;
  int num_layer = 5;
  std::vector<int> layers;
  layers.pushback(123);

  layers.pushback(456);

  int bajkd = layers.getIdx(0);
  int x = 1;
  while (num_epoch-- ){
    num_layer = 5;
    x = 0;
    while (x < num_layer ){
      x++;
      for (int nod = 0; nod < g.num_nodes(); nod ++) 
      {
        #pragma omp parallel for
        for (int edge = g.indexofNodes[nod]; edge < g.indexofNodes[nod+1]; edge ++) 
        {int n = g.edgeList[edge] ;
          if (labels[n] == labels[nod] )
            {
          }
        }
      }
    }
    while (num_layer-- ){
    }
  }

}
