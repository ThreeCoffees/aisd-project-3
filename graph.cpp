#include "graph.h"

void create_graph_vertices(graph_t * graph){
    graph_vert_t * vertices = (graph_vert_t *) malloc(graph->v_count* sizeof(graph_vert_t));
    graph->vertices = vertices;
    for(unsigned int i = 0; i < graph->v_count; i++){
        unsigned int s;
        scanf("%u", &s);
        vertices[i].n_count = 0;
        vertices[i].neighbors = (unsigned int *) calloc(s, sizeof(unsigned int));
        for(unsigned int j = 0; j < s; j++){
            unsigned int n_i;
            scanf("%u", &n_i);
            n_i--;
            add_graph_edge(graph, i, n_i);
        }
    }
    return;
}

graph_t * create_new_graph(unsigned int v_count){
    graph_t * graph = (graph_t*) malloc(sizeof(graph_t));
    graph->v_count = v_count;
    graph->edge_count = 0;
    graph->skl_sp_v_counts = (unsigned int *) calloc(v_count, sizeof(unsigned int));
    create_graph_vertices(graph);

    return graph;
}

void delete_graph_vert(graph_vert_t * vert){
    free(vert->neighbors);
}

void delete_graph(graph_t * graph){
    for(unsigned int i = 0; i < graph->v_count; i++){
        delete_graph_vert(&(graph->vertices[i]));
    }
    free(graph->vertices);
    free(graph->skl_sp_v_counts);
    free(graph);
}

void add_graph_edge(graph_t * graph, unsigned int a, unsigned int b){
    graph->vertices[a].neighbors[graph->vertices[a].n_count] = b;
    graph->vertices[a].n_count++;
    graph->edge_count++;
}

