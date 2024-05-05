#include "degree_sequence.h"

void degree_sequence(graph_t * graph){
    int * degrees = (int *) calloc(graph->v_count+1, sizeof(int));
    for(int i = 0; i < graph->v_count + 1; i++){
        degrees[i] = 0;
    }
    for(int i = 0; i < graph->v_count; i++){
        degrees[graph->vertices[i].n_count]++;
    }

    for(int i = graph->v_count; i >= 0; i--){
        for(int j = 0; j < degrees[i]; j++){
            printf("%d ",i);
        }
    }
    printf("\n");
}
