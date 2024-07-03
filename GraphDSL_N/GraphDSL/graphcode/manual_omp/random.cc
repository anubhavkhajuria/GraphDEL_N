#include"random.h"

auto Max_degree(graph& g)
{
  int max_degree = -1;
  int prox = -1;
  #pragma omp parallel for
  for (int n = 0; n < g.num_nodes(); n ++) 
  {
    prox = max(g.out_degree(n),g.in_degree(n));
    max_degree = max(max_degree,prox);
  }
  return max_degree;

}

int main(int argc, char *argv[]){
	graph G(argv[0]);
	G.parseGraph();

	int x = Max_degree(G);
	std::cout<< "maximum degree: " << x << std::endl;

	return 0 ;
}
