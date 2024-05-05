#include "graph.h"

graph_vert_t * create_graph_vertices(int v_count){
    graph_vert_t * vertices = (graph_vert_t *) calloc(v_count, sizeof(graph_vert_t));
    for(int i = 0; i < v_count; i++){
        vertices[i].neighbors = (bool *) calloc(v_count, sizeof(bool));
        vertices[i].n_count = 0;
        for(int j = 0; j < v_count; j++){
            vertices[i].neighbors[j] = false;
        }
    }
    return vertices;
}

graph_t * create_new_graph(int v_count){
    graph_t * graph = (graph_t*) malloc(sizeof(graph_t));
    graph->v_count = v_count;
    graph->vertices = create_graph_vertices(v_count);

    return graph;
}

void delete_graph_vert(graph_vert_t * vert){
    free(vert->neighbors);
}

void delete_graph(graph_t * graph){
    for(int i = 0; i < graph->v_count; i++){
        delete_graph_vert(&(graph->vertices[i]));
    }
    free(graph->vertices);
    free(graph);
}

void print_graph_dbg(graph_t * graph){
    printf("Vertex count: %d\n", graph->v_count);
    printf("Vertices: \n");
    for(int i = 0; i < graph->v_count; i++){
        printf("%d\t", graph->vertices[i].n_count);
        for(int j = 0; j < graph->v_count; j++){
            printf("%d", graph->vertices[i].neighbors[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void add_graph_edge(graph_t * graph, int a, int b){
    graph->vertices[a].neighbors[b] = true;
    graph->vertices[a].n_count++;
}

