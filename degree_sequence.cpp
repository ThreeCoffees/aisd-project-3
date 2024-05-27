#include "degree_sequence.h"

void degree_sequence(graph_t * graph){
    unsigned int * degrees = (unsigned int *) calloc(graph->v_count, sizeof(unsigned int));
    for(unsigned int i = 0; i < graph->v_count; i++){
        degrees[i] = 0;
    }
    for(unsigned int i = 0; i < graph->v_count; i++){
        degrees[graph->vertices[i].n_count]++;
    }

    for(unsigned int i = graph->v_count-1; i > 0; i--){
        for(unsigned int j = 0; j < degrees[i]; j++){
            printf("%u ",i);
        }
    }
    printf("\n");
    free(degrees);
}
