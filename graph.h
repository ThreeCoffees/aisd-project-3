#pragma once

#include "stdio.h"
#include "stdlib.h"

typedef struct{
    unsigned int n_count;
    unsigned int * neighbors;
}graph_vert_t;

typedef struct{
    unsigned int v_count;
    graph_vert_t * vertices;
}graph_t;

void create_graph_vertices(unsigned int v_count);

graph_t * create_new_graph(unsigned int v_count);

void delete_graph_vert(graph_vert_t * vert);

void delete_graph(graph_t * graph);

void print_graph_dbg(graph_t * graph);

void add_graph_edge(graph_t * graph, unsigned int a, unsigned int b);
