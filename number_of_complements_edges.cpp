#include "number_of_complements_edges.h"

int get_edge_count(graph_t * graph){
    int edge_count = 0;
    for(int i = 0; i < graph->v_count; i++){
        for(int j = i+1; j < graph->v_count; j++){
            if(graph->vertices[i].neighbors[j] == true) edge_count++;

        }
    }
    return edge_count;
}

void number_of_complements_edges(graph_t * graph){
    int edge_count = get_edge_count(graph);

    int complete_edge_count = graph->v_count * (graph->v_count - 1) / 2;

    printf("%d", complete_edge_count - edge_count);
    printf("\n");
}

