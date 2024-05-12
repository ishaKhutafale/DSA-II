#include<stdio.h>
#include "heap.h"

int main()
{
    int num = 9;
    Graph *g[num];
    int visited[num];
    for (int i = 0; i < num; ++i)
    {
        g[i] = NULL;
        visited[i]=0; // Initialize each pointer to NULL
    }

   addEdge(g, 0, 1, 2);
    addEdge(g, 0, 2, 4);
    addEdge(g, 0, 3, 6);
    addEdge(g, 1, 2, 5);
    addEdge(g, 2, 3, 1);
    addEdge(g, 3, 4, 4);
    addEdge(g, 2, 5, 2);
    addEdge(g, 3, 6, 3);
    addEdge(g, 5, 6, 1);
    addEdge(g, 5, 7, 3);
    addEdge(g, 5, 8, 5);
    addEdge(g, 6, 8, 4);


   /* addEdge(g,0,1,2);
    addEdge(g,0,2,6);
    addEdge(g,0,3,5);
    addEdge(g,1,2,3);
    addEdge(g,2,3,4);*/
    


    display_adjList(g, num);
    printf("BFS Traversal:\n");
   // bfs(g,0,visited);
    printf("\nDFS Traversal:\n");
    dfs(g,0,visited);
    printf("\n");
    prims(g,0,num);
    

    return 0;
}
