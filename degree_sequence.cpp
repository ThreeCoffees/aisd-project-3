#include "degree_sequence.h"

void degree_sequence(graph_t * graph){
    unsigned int * degrees = (unsigned int *) calloc(graph->v_count, sizeof(unsigned int));
    for(unsigned int i = 0; i < graph->v_count; i++){
        degrees[i] = 0;
    }
    for(unsigned int i = 0; i < graph->v_count; i++){
        degrees[graph->vertices[i].n_count]++;
    }

    for(unsigned int i = 0; i < graph->v_count; i++){
        for(unsigned int j = 0; j < degrees[graph->v_count - i - 1]; j++){
            printf("%u ",graph->v_count - i - 1);
        }
    }
    printf("\n");
    free(degrees);
}
