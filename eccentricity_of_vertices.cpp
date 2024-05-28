#include "eccentricity_of_vertices.h"

void eccentricity_bfs(graph_t * graph, unsigned int curr, unsigned int * max_distance, unsigned int * distances, unsigned int * queue){
    unsigned int f = 0, r = 0;

    bool * visited = (bool *) calloc(graph->v_count, sizeof(bool));

    visited[curr] = true;
    queue[r] = curr;
    distances[r] = 0;
    r++;

    while(f < r){
        curr = queue[f];
        unsigned int curr_dist = distances[f];
        f++;

        for(unsigned int i = 0; i < graph->vertices[curr].n_count; i++){
            auto neigbor = graph->vertices[curr].neighbors[i];
            if(!visited[neigbor]){
                visited[neigbor] = true;
                queue[r] = neigbor;
                distances[r] = curr_dist+1;

                if(r+1 >= graph->skl_sp_v_counts[graph->vertices[curr].skl_sp]){
                    *max_distance = distances[r];
                    free(visited);
                    return;
                }

                r++;
            }
        }
    }
    free(visited);
}


void eccentricity_of_vertices(graph_t * graph){
    unsigned int * distances = (unsigned int *) malloc(graph->v_count* sizeof(unsigned int));
    unsigned int * queue = (unsigned int *) malloc(graph->v_count* sizeof(unsigned int));

    for(unsigned int i = 0; i < graph->v_count; i++){
        unsigned int max_distance = 0;
        eccentricity_bfs(graph, i, &max_distance, distances, queue);
        printf("%u ", max_distance);
    }

    free(queue);
    free(distances);
    printf("\n");
}

