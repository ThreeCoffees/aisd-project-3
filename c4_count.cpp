#include "c4_count.h"

void cycle_detection_dfs(long long * c4_count, graph_t * graph, unsigned int curr, bool * visited, int curr_depth, unsigned int first_vert){
    /*if(curr_depth > MAX_DFS_DEPTH){
        return; 
    }

    visited[curr] = 1;

    for(unsigned int i = 0; i < graph->vertices[curr].n_count; i++){
        unsigned int i_neighbor = graph->vertices[curr].neighbors_by_degree[i];

        if(curr_depth == MAX_DFS_DEPTH && i_neighbor == first_vert){
            (*c4_count)++;
            continue;
        }
        if(visited[i_neighbor] == true) continue;

        cycle_detection_dfs(c4_count, graph, i_neighbor, visited, curr_depth+1, first_vert);
    }
    visited[curr] = 0;
    */
    //printf("%u - ", curr);
    for(unsigned int i = 0; i < graph->vertices[curr].n_count; i++){
        unsigned int i_neighbor = graph->vertices[curr].neighbors_by_degree[i];
        if(graph->vertices[i_neighbor].n_count > graph->vertices[curr].n_count) break;
        if(graph->vertices[i_neighbor].n_count == graph->vertices[curr].n_count
                && i_neighbor > curr) break;
        //printf("%u ", i_neighbor);
        for(unsigned int j = 0; j < graph->vertices[i_neighbor].n_count; j++){
            unsigned int j_neighbor = graph->vertices[i_neighbor].neighbors_by_degree[j];

        }

    }
    //printf("\n");
}

void number_of_c4_subgraphs(graph_t * graph){
    bool * visited = (bool *) calloc(graph->v_count, sizeof(bool));
    long long c4_count = 0;
    for(unsigned int i = 0; i < graph->v_count; i++){
        if(graph->skl_sp_v_counts[graph->vertices[i].skl_sp] < 4) continue;
        cycle_detection_dfs(&c4_count, graph, i, visited, 1, i);
    }

    //c4_count /= 8;

    free(visited);
    printf("%lld\n", c4_count);
}
