#include "number_of_complements_edges.h"

unsigned int get_edge_count(graph_t * graph){
    unsigned int edge_count = 0;
    for(unsigned int i = 0; i < graph->v_count; i++){
        for(unsigned int j = 0; j < graph->vertices[i].n_count; j++){
            if(graph->vertices[i].neighbors[j] > i) edge_count++;
        }

    }
    return edge_count;
}

void number_of_complements_edges(graph_t * graph){
    unsigned int edge_count = get_edge_count(graph);

    unsigned int complete_edge_count = graph->v_count * (graph->v_count - 1) / 2;

    printf("%u", complete_edge_count - edge_count);
    printf("\n");
}

