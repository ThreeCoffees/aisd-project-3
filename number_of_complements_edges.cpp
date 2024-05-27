#include "number_of_complements_edges.h"

long long int get_edge_count(graph_t * graph){
    long long int edge_count = 0;
    for(unsigned int i = 0; i < graph->v_count; i++){
        edge_count += graph->vertices[i].n_count;
    }
    return edge_count/2;
}

void number_of_complements_edges(graph_t * graph){
    long long int edge_count = get_edge_count(graph);

    long long int complete_edge_count = (long long)graph->v_count * ((long long)graph->v_count - 1) / 2;

    printf("%lld", complete_edge_count - edge_count);
    printf("\n");
}

