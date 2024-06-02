#pragma once

#include "graph.h"

void dfs(graph_t * graph, unsigned int curr, bool * visited );

void number_of_components(graph_t * graph);

void bipartiteness(graph_t * graph);
