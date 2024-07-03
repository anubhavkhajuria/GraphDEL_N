#include"random.h"

auto Max_degree(graph& g)
{
  int max_degree = -1;
  int prox = -1;
  #pragma omp parallel for
  for (int n = 0; n < g.num_nodes(); n ++) 
  {
    prox = std::max(g.getOutDegree(n),g.getInDegree(n));
    max_degree = std::max(max_degree,prox);
  }
  return max_degree;

}

int main(){
	graph G("sample_graph.txt");
	G.parseGraph();

	int x = Max_degree(G);
	std::cout<< "maximum degree: " << x << std::endl;

	return 0 ;
}
