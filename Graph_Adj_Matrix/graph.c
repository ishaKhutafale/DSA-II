#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

void init_graph(Graph *g, char *filename)
{
    FILE *fp1;
    fp1 = fopen(filename, "r");
    int numVertices, temp;
    fscanf(fp1, "%d", &numVertices);

    g->adjMatrix = (int **)malloc(numVertices * sizeof(int *));

    for (int i = 0; i < numVertices; i++)
    {
        g->adjMatrix[i] = (int *)malloc(numVertices * sizeof(int));

        for (int j = 0; j < numVertices; j++)
        {
            fscanf(fp1, "%d", &temp);
            g->adjMatrix[i][j] = temp;
        }
    }
    g->numVertices = numVertices;
}

int getDegree(Graph *g, int vertex)
{
    int degree = 0;
    for (int i = 0; i < g->numVertices; i++)
    {
        if (g->adjMatrix[vertex][i] != 0)
        {
            degree++;
        }
    }
    return degree;
}
void display_graph(Graph g)
{
    printf("Graph: \n");
    for (int i = 0; i < g.numVertices; i++)
    {
        printf("Row %d: ", i);
        for (int j = 0; j < g.numVertices; j++)
        {
            printf("%d ", g.adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int isAdjacent(Graph *g, int vertex1, int vertex2)
{
    if (g->adjMatrix[vertex1][vertex2] != 0)
        return 1;
    else
        return 0;
}

void bfs(Graph *g, int vertex, int *visited)
{
    queue q;
    init(&q);
    enqueue(&q, vertex);
    visited[vertex] = 1;
    while (!isEmpty(&q))
    {
        int val = dequeue(&q);
        printf("%d ", val);
        for (int i = 0; i < g->numVertices; i++)
        {
            if (g->adjMatrix[val][i] != 0 && visited[i] == 0)
            {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
}

int isConnected(Graph *g)
{
    int visited[g->numVertices];
    for (int i = 0; i < g->numVertices; i++)
    {
        visited[i] = 0;
    }
    int flag=0;
    queue q;
    init(&q);
    enqueue(&q, 0);
    visited[0] = 1;
    while (!isEmpty(&q))
    {
        int val = dequeue(&q);
        for (int i = 0; i < g->numVertices; i++)
        {
            if (g->adjMatrix[val][i] != 0 && visited[i] == 0)
            {
                enqueue(&q, i);
                visited[i] = 1;
            }
            if (!visited[i])
                flag=1;
            else 
                flag=0;
        }
    }
    if(flag) 
        return 0;

    return 1;
}

void displayComponents(Graph *g)
{
    int visited[g->numVertices];
    int c = 0;
    for (int i = 0; i < g->numVertices; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < g->numVertices; i++)
    {

        if (!visited[i])
        {

            printf("Component %d :", i + 1);
            bfs(g, i, visited);
            printf("\n");
            c++;
        }
    }
    printf("total number of components: %d \n", c);
}
