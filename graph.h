#pragma once

#include "stdio.h"
#include "stdlib.h"

typedef struct{
    unsigned int skl_sp;
    unsigned int n_count;
    unsigned int * neighbors;
}graph_vert_t;

typedef struct{
    bool is_bipartite;
    unsigned int * skl_sp_v_counts;
    unsigned int * vertices_by_degree;
    unsigned int v_count;
    unsigned int edge_count;
    graph_vert_t * vertices;
}graph_t;

template <typename F>
void merge(unsigned int * arr, unsigned int *tmp, unsigned int l, unsigned int r, unsigned int m, F&& cmp);

template <typename F>
void mergeSort(unsigned int * arr, unsigned int *tmp, int l, int r, F&& cmp);

unsigned int * order_vertices_by_degree(graph_t * graph);

void create_graph_vertices(unsigned int v_count);

graph_t * create_new_graph(unsigned int v_count);

void delete_graph_vert(graph_vert_t * vert);

void delete_graph(graph_t * graph);

void print_graph_dbg(graph_t * graph);

void add_graph_edge(graph_t * graph, unsigned int a, unsigned int b);
