#include "c4_count.h"

void cycle_detection_dfs(long long * c4_count, graph_t * graph, unsigned int curr, bool * visited, int curr_depth, unsigned int first_vert){
    if(curr_depth > MAX_DFS_DEPTH){
        return; 
    }

    visited[curr] = 1;

    for(unsigned int i = 0; i < graph->vertices[curr].n_count; i++){
        unsigned int curr_neighbor = graph->vertices[curr].neighbors[i];
        if(curr_depth == MAX_DFS_DEPTH && curr_neighbor == first_vert){
            (*c4_count)++;
        }
        if(visited[curr_neighbor] == true) continue;

        cycle_detection_dfs(c4_count, graph, curr_neighbor, visited, curr_depth+1, first_vert);
    }
    visited[curr] = 0;
}

void number_of_c4_subgraphs(graph_t * graph){
    bool * visited = (bool *) calloc(graph->v_count, sizeof(bool));
    long long c4_count = 0;
    for(unsigned int i = 0; i < graph->v_count; i++){
        cycle_detection_dfs(&c4_count, graph, i, visited, 1, i);
    }

    c4_count /= 8;

    free(visited);
    printf("%lld\n", c4_count);
}
