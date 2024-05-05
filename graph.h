#pragma once

#include "stdio.h"
#include "stdlib.h"

typedef struct{
    int n_count;
    bool * neighbors;
}graph_vert_t;

typedef struct{
    int v_count;
    graph_vert_t * vertices;
}graph_t;

graph_vert_t * create_graph_vertices(int v_count);

graph_t * create_new_graph(int v_count);

void delete_graph_vert(graph_vert_t * vert);

void delete_graph(graph_t * graph);

void print_graph_dbg(graph_t * graph);

void add_graph_edge(graph_t * graph, int a, int b);
