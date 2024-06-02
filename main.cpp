#include "stdio.h"
#include "stdlib.h"

#include "graph.h"

#include "degree_sequence.h"
#include "number_of_components_bipartitness.h"
#include "eccentricity_of_vertices.h"
#include "vert_color.h"
#include "c4_count.h"
#include "number_of_complements_edges.h"


void planarity(graph_t * graph){
    printf("?\n");
}

void print_graph_info(graph_t * graph){
    degree_sequence(graph);
    number_of_components(graph);        
    bipartiteness(graph);               
    eccentricity_of_vertices(graph);    
    planarity(graph);                   //TODO
    vertices_colors(graph);             
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
