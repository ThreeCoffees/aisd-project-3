#include "number_of_components.h"

void dfs(graph_t * graph, unsigned int curr, bool * visited ){
    visited[curr] = 1;

    for(unsigned int i = 0; i < graph->vertices[curr].n_count; i++){
        unsigned int curr_neighbor = graph->vertices[curr].neighbors[i];
        if(visited[curr_neighbor] == true) continue;

        dfs(graph, curr_neighbor, visited);
    }
}

void number_of_components(graph_t * graph){
    bool * visited = (bool *) calloc(graph->v_count, sizeof(bool));

    unsigned int c_count = 0;
    for(unsigned int i = 0; i < graph->v_count; i++){
        if(visited[i] == true) continue;

        dfs(graph, i, visited);

        c_count++;
    }

    printf("%d", c_count);

    free(visited);

    printf("\n");
}
