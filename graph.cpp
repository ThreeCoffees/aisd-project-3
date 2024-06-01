#include "graph.h"

template <typename F>
void merge(unsigned int * arr, unsigned int *tmp, unsigned int l, unsigned int r, unsigned int m, F&& cmp){
    for(unsigned int i = l; i < r+1; i++){
        tmp[i] = arr[i];
    }

    unsigned int i = l;
    unsigned int j = m+1;
    for(unsigned int k = l; k < r+1; k++){
        if(i > m){
            arr[k] = tmp[j];
            j++;
        }
        else if(j > r){
            arr[k] = tmp[i];
            i++;
        }
        else{
            if(cmp(tmp[i], tmp[j])){
                arr[k] = tmp[j];
                j++;
            }
            else{
                arr[k] = tmp[i];
                i++;
            }
        }
    }
}

template <typename F>
void mergeSort(unsigned int * arr, unsigned int *tmp, int l, int r, F&& cmp){
    if(l >= r) return;
    unsigned int m = (r+l)/2;

    mergeSort(arr, tmp, l, m, cmp);
    mergeSort(arr, tmp, m+1, r, cmp);

    merge(arr, tmp, l, r, m, cmp);
}

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

unsigned int * order_vertices_by_degree(graph_t * graph){
    unsigned int * ordered_verts = (unsigned int * )malloc(graph->v_count * sizeof(unsigned int));
    unsigned int * tmp = (unsigned int * )malloc(graph->v_count * sizeof(unsigned int));
    for(unsigned int i = 0; i < graph->v_count; i++){
        ordered_verts[i] = i;
    }

    mergeSort(ordered_verts, tmp, 0, graph->v_count-1, [graph](unsigned int a, unsigned int b)->bool{
            return graph->vertices[a].n_count <= graph->vertices[b].n_count;
            });
    

    free(tmp);
    return ordered_verts;
}

graph_t * create_new_graph(unsigned int v_count){
    graph_t * graph = (graph_t*) malloc(sizeof(graph_t));
    graph->v_count = v_count;
    graph->edge_count = 0;
    graph->is_bipartite = true;
    graph->skl_sp_v_counts = (unsigned int *) calloc(v_count, sizeof(unsigned int));
    create_graph_vertices(graph);

    graph->vertices_by_degree = order_vertices_by_degree(graph);
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
    free(graph->vertices_by_degree);
    free(graph);
}

void add_graph_edge(graph_t * graph, unsigned int a, unsigned int b){
    graph->vertices[a].neighbors[graph->vertices[a].n_count] = b;
    graph->vertices[a].n_count++;
    graph->edge_count++;
}

