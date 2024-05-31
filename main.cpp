#include "stdio.h"
#include "stdlib.h"

#include "graph.h"

#include "degree_sequence.h"
#include "number_of_components.h"
#include "eccentricity_of_vertices.h"
#include "number_of_complements_edges.h"

void bipartiteness(graph_t * graph){
    if(graph->is_bipartite){
        printf("T\n");
    }
    else{
        printf("F\n");
    }
}

void planarity(graph_t * graph){
    printf("?\n");
}

void vertices_colors(graph_t * graph){
    printf("?\n");
    printf("?\n");
    printf("?\n");
}

#define MAX_DFS_DEPTH 4

void cycle_detection_dfs(long long * c4_count, graph_t * graph, unsigned int curr, bool * visited, int curr_depth, unsigned int first_vert){
    visited[curr] = 1;

    if(curr_depth <= MAX_DFS_DEPTH){
        for(unsigned int i = 0; i < graph->vertices[curr].n_count; i++){
            unsigned int curr_neighbor = graph->vertices[curr].neighbors[i];
            if(curr_depth == MAX_DFS_DEPTH && curr_neighbor == first_vert){
                c4_count++;
            }
            if(visited[curr_neighbor] == true) continue;

            cycle_detection_dfs(c4_count, graph, curr_neighbor, visited, curr_depth+1, first_vert);
        }
    }
    else{
        visited[curr] = 0;
    }

}

void number_of_c4_subgraphs(graph_t * graph){
    bool * visited = (bool *) calloc(graph->v_count, sizeof(bool));
    long long c4_count = 0;
    for(unsigned int i = 0; i < graph->v_count; i++){
        cycle_detection_dfs(&c4_count, graph, i, visited, 1, i);
    }

    free(visited);
    printf("%lld\n", c4_count);
}

void print_graph_info(graph_t * graph){
    degree_sequence(graph);
    number_of_components(graph);        
    bipartiteness(graph);               
    eccentricity_of_vertices(graph);    
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
