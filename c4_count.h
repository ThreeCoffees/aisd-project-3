#pragma once
#include "graph.h"

#define MAX_DFS_DEPTH 4

void cycle_detection_dfs(long long * c4_count, graph_t * graph, unsigned int curr, bool * visited, int curr_depth, unsigned int first_vert);

void number_of_c4_subgraphs(graph_t * graph);
