#include "number_of_components.h"

void dfs(graph_t * graph, int curr, bool * visited ){
    visited[curr] = 1;

    for(int i = 0; i < graph->v_count; i++){
        if(graph->vertices[curr].neighbors[i] == false) continue;
        if(visited[i] == 1) continue;

        dfs(graph, i, visited);
    }
}

void number_of_components(graph_t * graph){
    bool * visited = (bool *) calloc(graph->v_count, sizeof(bool));

    int c_count = 0;
    for(int i = 0; i < graph->v_count; i++){
        if(visited[i] == true) continue;

        dfs(graph, i, visited);

        c_count++;
    }

    printf("%d", c_count);

    free(visited);

    printf("\n");
}
