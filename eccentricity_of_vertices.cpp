#include "eccentricity_of_vertices.h"

void eccentricity_bfs(graph_t * graph, unsigned int curr, unsigned int * max_distance){
    unsigned int f = 0, r = 0;

    bool * visited = (bool *) calloc(graph->v_count, sizeof(bool));
    unsigned int * distances = (unsigned int *) calloc(graph->v_count, sizeof(unsigned int));
    unsigned int * queue = (unsigned int *) calloc(graph->v_count, sizeof(unsigned int));

    visited[curr] = true;
    queue[r] = curr;
    distances[r] = 0;
    r++;

    while(f != r){
        curr = queue[f];
        unsigned int curr_dist = distances[f];
        f++;
        if(curr_dist >= *max_distance) *max_distance = curr_dist;

        for(unsigned int i = 0; i < graph->vertices[curr].n_count; i++){
            auto neigbor = graph->vertices[curr].neighbors[i];
            if(!visited[neigbor]){
                visited[neigbor] = true;
                queue[r] = neigbor;
                distances[r] = curr_dist+1;
                r++;
            }

        }
    }
    free(visited);
    free(distances);
    free(queue);
}


void eccentricity_of_vertices(graph_t * graph){
    for(unsigned int i = 0; i < graph->v_count; i++){
        unsigned int max_distance = 0;
        eccentricity_bfs(graph, i, &max_distance);
        printf("%u ", max_distance);
    }
    printf("\n");
}

