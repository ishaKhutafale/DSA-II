#include <stdio.h>
#include "graph.h"

int main(int argc, char *argv[])
{
    Graph g;
    init_graph(&g, argv[1]);
    int n;
    do
    {
        printf("\nEnter the operation you want to perform:\n1.Display the Graph\n2.Display degree of each vertex\n3.Verify if the graph is connected.\n4.Number of components & Vertices\n5.Check if one vertex is adjacent to another.\n6.EXIT\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            display_graph(g);
            break;
        case 2:
            for (int i = 0; i < g.numVertices; i++)
            {
                printf("Degree of vertex %d : %d \n", i, getDegree(&g, i));
            }
            break;
        case 3:
            if (isConnected(&g))
                printf("Graph is connected\n");
            else
                printf("Graph is not connected\n");

            break;
        case 4:
            displayComponents(&g);
            break;
        case 5:
            int v1, v2;
            printf("Enter the two vertices:");
            scanf("%d%d", &v1, &v2);
            if (isAdjacent(&g, v1, v2))
                printf("The vertices %d & %d are adjacent\n", v1, v2);
            else
                printf("The vertices %d & %d are not adjacent\n", v1, v2);

            break;
        case 6:
            break;
        default:
            break;
        }
    } while (n != 6);

    return 0;
}