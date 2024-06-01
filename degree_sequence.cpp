#include "degree_sequence.h"

void degree_sequence(graph_t * graph){
    for(unsigned int i = 0; i < graph->v_count; i++){
        printf("%u ", graph->vertices[graph->vertices_by_degree[i]].n_count);
    }
    printf("\n");
}
