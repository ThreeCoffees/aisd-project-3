#include "number_of_components_bipartitness.h"
#include "graph.h"

void dfs(graph_t * graph, unsigned int curr, bool * visited, unsigned int skl_sp_id, bool * bipartite_color, bool prev_bipartite_color){
    visited[curr] = 1;
    bipartite_color[curr] = !prev_bipartite_color;
    graph->vertices[curr].skl_sp = skl_sp_id;

    for(unsigned int i = 0; i < graph->vertices[curr].n_count; i++){
        unsigned int curr_neighbor = graph->vertices[curr].neighbors[i];
        if(visited[curr_neighbor] == true){
            if(bipartite_color[curr_neighbor] == bipartite_color[curr]){
                graph->is_bipartite = false;
            }
            continue;
        } 

        graph->skl_sp_v_counts[skl_sp_id]++;
        dfs(graph, curr_neighbor, visited, skl_sp_id, bipartite_color, bipartite_color[curr]);
    }
}

void number_of_components(graph_t * graph){
    bool * visited = (bool *) calloc(graph->v_count, sizeof(bool));
    bool * bipartite_color = (bool *) malloc(graph->v_count * sizeof(bool));

    unsigned int c_count = 0;
    for(unsigned int i = 0; i < graph->v_count; i++){
        if(visited[i] == true) continue;

        graph->skl_sp_v_counts[c_count] = 1;
        dfs(graph, i, visited, c_count, bipartite_color, 1);
        c_count++;
    }

    printf("%u", c_count);

    free(visited);
    free(bipartite_color);

    printf("\n");
}

void bipartiteness(graph_t * graph){
    if(graph->is_bipartite){
        printf("T\n");
    }
    else{
        printf("F\n");
    }
}

