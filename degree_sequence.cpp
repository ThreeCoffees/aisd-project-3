#include "degree_sequence.h"

void merge(unsigned int * arr, unsigned int *tmp, unsigned int l, unsigned int r, unsigned int m){
    for(unsigned int i = l; i < r+1; i++){
        tmp[i] = arr[i];
    }

    unsigned int i = l;
    unsigned int j = m+1;
    for(unsigned int k = l; k < r+1; k++){
        if(i > m){
            arr[k] = tmp[j];
            j++;
        }
        else if(j > r){
            arr[k] = tmp[i];
            i++;
        }
        else{
            if(tmp[i] <= tmp[j]){
                arr[k] = tmp[j];
                j++;
            }
            else{
                arr[k] = tmp[i];
                i++;
            }
        }
    }
}

void mergeSort(unsigned int * arr, unsigned int *tmp, int l, int r){
    if(l >= r) return;
    unsigned int m = (r+l)/2;

    mergeSort(arr, tmp, l, m);
    mergeSort(arr, tmp, m+1, r);

    merge(arr, tmp, l, r, m);
}

void degree_sequence(graph_t * graph){
    unsigned int * degrees = (unsigned int *) malloc(graph->v_count* sizeof(unsigned int));
    for(unsigned int i = 0; i < graph->v_count; i++){
        degrees[i] = graph->vertices[i].n_count;
    }

    unsigned int * tmp = (unsigned int *) malloc(graph->v_count* sizeof(unsigned int));
    mergeSort(degrees, tmp, 0, graph->v_count-1);
    for(unsigned int i = 0; i < graph->v_count; i++){
        printf("%u ", degrees[i]);
    }
    printf("\n");
    free(tmp);
    free(degrees);
}
