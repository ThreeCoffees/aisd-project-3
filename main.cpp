#include "stdio.h"
#include "stdlib.h"

#include "graph.h"
#include "degree_sequence.h"
#include "number_of_components.h"
#include "number_of_complements_edges.h"

void bipartiteness(graph_t * graph){
    printf("?\n");
}

void eccentricity_bfs(graph_t * graph, unsigned int curr, unsigned int * max_distance){
    int f = 0, r = 0;

    bool * visited = (bool *) calloc(graph->v_count, sizeof(bool));
    unsigned int * distances = (unsigned int *) calloc(graph->v_count, sizeof(unsigned int));
    unsigned int * queue = (unsigned int *) calloc(graph->v_count, sizeof(unsigned int));

    visited[curr] = true;
    queue[r] = curr;
    distances[r] = 0;
    r++;

    while(f != r){
        curr = queue[f];
        int curr_dist = distances[f];
        f++;
        //printf("bfs - %u %u\n", curr, curr_dist);
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

void planarity(graph_t * graph){
    printf("?\n");
}

void vertices_colors(graph_t * graph){
    printf("?\n");
    printf("?\n");
    printf("?\n");
}

void number_of_c4_subgraphs(graph_t * graph){
    printf("?\n");
}

void print_graph_info(graph_t * graph){
    degree_sequence(graph);
    number_of_components(graph);        
    bipartiteness(graph);               //TODO
    eccentricity_of_vertices(graph);    //TODO
    planarity(graph);                   //TODO
    vertices_colors(graph);             //TODO
    number_of_c4_subgraphs(graph);      //TODO
    number_of_complements_edges(graph); 

    printf("\n");
}

void handle_graph(){
    unsigned int n;
    scanf("%u", &n);
    graph_t * graph = create_new_graph(n);

    print_graph_info(graph);

    delete_graph(graph);
}

int main(){
    unsigned int k;
    scanf("%u", &k);
    for(unsigned int i = 0; i < k; i++){
        handle_graph();
    }
    return 0;
}
