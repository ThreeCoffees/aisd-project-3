#include "number_of_components.h"

void dfs(graph_t * graph, unsigned int curr, bool * visited, unsigned int skl_sp_id){
    visited[curr] = 1;
    graph->vertices[curr].skl_sp = skl_sp_id;

    for(unsigned int i = 0; i < graph->vertices[curr].n_count; i++){
        unsigned int curr_neighbor = graph->vertices[curr].neighbors[i];
        if(visited[curr_neighbor] == true) continue;

        graph->skl_sp_v_counts[skl_sp_id]++;
        dfs(graph, curr_neighbor, visited, skl_sp_id);
    }
}

void number_of_components(graph_t * graph){
    bool * visited = (bool *) calloc(graph->v_count, sizeof(bool));

    unsigned int c_count = 0;
    for(unsigned int i = 0; i < graph->v_count; i++){
        if(visited[i] == true) continue;

        graph->skl_sp_v_counts[c_count] = 1;
        dfs(graph, i, visited, c_count);
        c_count++;
    }

    printf("%u", c_count);

    free(visited);

    printf("\n");
}
