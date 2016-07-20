#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "graph.h"

void bypass_to_deep(Graph graph, int node, bool used_nodes[], std::vector<int> component){
  used_nodes[node] = true;
  component.push_back(node);

  for(int i=0; i<graph.adjacency_list[node].size(); ++i){
    int to = graph.adjacency_list[node][i];
    if (!used_nodes[to]){
      bypass_to_deep(graph, to, used_nodes, component);
    }
  }
}

std::vector< std::vector<int> > find_components(Graph graph){
  std::vector< std::vector<int> > components;
  bool used_nodes[graph.nodes_count];

  for(int i=0; i<graph.nodes_count; ++i){
    used_nodes[i] = false;
  };

  for (int i=0; i<graph.nodes_count; ++i){
    if (!used_nodes[i]) {
      std::vector<int> component;
      components.push_back(component);
      bypass_to_deep(graph, i, used_nodes, component);
    }
  }
  return components;
}