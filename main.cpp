#include "stdio.h"
#include "stdlib.h"

#include "graph.h"
#include "degree_sequence.h"
#include "number_of_components.h"
#include "number_of_complements_edges.h"

void bipartiteness(graph_t * graph){
    printf("?\n");
}

void eccentricity_of_vertices(graph_t * graph){
    printf("?\n");
}

void planarity(graph_t * graph){
    printf("?\n");
}

void vertices_colors(graph_t * graph){
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
    int n;
    scanf("%d", &n);
    graph_t * graph = create_new_graph(n);

    for(int i = 0; i < n; i++){
        int s;
        scanf("%d", &s);
        for(int j = 0; j < s; j++){
            int n_i;
            scanf("%d", &n_i);
            n_i--;
            add_graph_edge(graph, i, n_i);
        }
    }
    print_graph_dbg(graph);

    print_graph_info(graph);


    delete_graph(graph);
}

int main(){
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        handle_graph();
    }
    return 0;
}
