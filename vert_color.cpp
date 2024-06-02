#include "vert_color.h"

void color_vert(graph_t * graph, unsigned int * colors, unsigned int curr_vert){
    unsigned int curr_color = 1;
    for(unsigned int j = 0; j < graph->vertices[curr_vert].n_count;){
        if(colors[graph->vertices[curr_vert].neighbors[j]] != curr_color) {
            j++;
            continue;
        }
        curr_color++;
        j = 0;
    }
    colors[curr_vert] = curr_color;
}

void vertices_colors(graph_t * graph){
    //greedy
    unsigned int * greedy_colors = (unsigned int *) calloc(graph->v_count, sizeof(unsigned int));
    for(unsigned int i = 0; i < graph->v_count; i++){
        color_vert(graph, greedy_colors, i);
    }
    for(unsigned int i = 0; i < graph->v_count; i++){
        printf("%u ", greedy_colors[i]);
    }
    printf("\n");

    free(greedy_colors);

    //lf
    unsigned int * lf_colors = (unsigned int *) calloc(graph->v_count, sizeof(unsigned int));
    
    for(unsigned int i = 0; i < graph->v_count; i++){
        color_vert(graph, lf_colors, graph->vertices_by_degree[i]);
    }
    for(unsigned int i = 0; i < graph->v_count; i++){
        printf("%u ", lf_colors[i]);
    }
    printf("\n");

    free(lf_colors);

    //slf
    printf("?\n"); //TODO
}
