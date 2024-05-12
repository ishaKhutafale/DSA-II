#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "queue.h"
#include <limits.h>
Graph *createNode(int vertex, int weight)
{
    Graph *newnode = (Graph *)malloc(sizeof(Graph));
    newnode->vertex = vertex;
    newnode->weight = weight;
    newnode->next = NULL;
    return newnode;
}

void addEdge(Graph *adjList[], int vertex1, int vertex2, int weight)
{
    Graph *nn1 = createNode(vertex2, weight);
    nn1->next = adjList[vertex1];
    adjList[vertex1] = nn1;

    Graph *nn2 = createNode(vertex1, weight);
    nn2->next = adjList[vertex2];
    adjList[vertex2] = nn2;
}

void bfs(Graph *adjList[], int start, int visited[])
{
    queue q;
    init(&q);
    enqueue(&q, start);
    visited[start] = 1;
    while (!isEmpty(&q))
    {
        int vertex = dequeue(&q);
        printf("%d -> ", vertex);
        Graph *temp = adjList[vertex];
        while (temp != NULL)
        {
            if (!visited[temp->vertex])
            {
                visited[temp->vertex] = 1;
                enqueue(&q, temp->vertex);
            }
            temp = temp->next;
        }
    }
}

void dfs(Graph *adjList[], int vertex, int visited[])
{
    visited[vertex] = 1;
    printf("%d -> ", vertex);
    Graph *temp = adjList[vertex];
    while (temp != NULL)
    {
        if (!visited[temp->vertex])
        {
            dfs(adjList, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

void display_adjList(Graph *adjList[], int vertices)
{
    printf("Adjacency list :\n");
    for (int i = 0; i < vertices; ++i)
    {
        printf("%d:", i);
        Graph *temp = adjList[i];
        while (temp)
        {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}


void prims(Graph *adjList[], int startvertex, int vertices)
{
    int visited[vertices];
    Graph *MST[vertices];
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
        MST[i] = NULL;
    }
    visited[startvertex] = 1;
    // Loop until all vertices are visited
    while (1)
    {
        int minWeight = INT_MAX;
        int minVertex = -1;
        int parent = -1;
        // Traverse all vertices
        for (int i = 0; i < vertices; i++)
        {
            if (visited[i])
            {
                Graph *temp = adjList[i];
                while (temp != NULL)
                {
                    if (!visited[temp->vertex] && temp->weight < minWeight)
                    {
                        minWeight = temp->weight;
                        minVertex = temp->vertex;
                        parent = i;
                    }
                    temp = temp->next;
                }
            }
        }

        if (minVertex == -1)
        {
            break;
        } // No minimum weight edge found

        visited[minVertex] = 1;
        addEdge(MST, minVertex, parent, minWeight);
    }
    displayMST(MST, vertices);
}
void displayMST(Graph *MST[], int vertices)
{
    int visitedEdges[vertices];
    for (int i = 0; i < vertices; i++)
    {
        visitedEdges[i] = 0;
    }
    visitedEdges[0] = 1;
    // Printing the MST
    printf("MST using prims Algorithm: \n");
    for (int i = 0; i < vertices; i++)
    {
        Graph *temp = MST[i];
        while (temp)
        {
            // Check if the edge has not been visited yet
            if (!visitedEdges[temp->vertex])
            {
                printf(" %d -> %d : %d\n", i, temp->vertex, temp->weight);
                visitedEdges[temp->vertex] = 1; // Mark the edge as visited
            }
            temp = temp->next;
        }
    }
}