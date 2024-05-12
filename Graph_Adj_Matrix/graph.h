typedef struct Graph
{
    int **adjMatrix;
    int numVertices;

}Graph;

void init_graph(Graph *,char *filename);
void display_graph(Graph g);
int isAdjacent(Graph *g,int vertex1,int vertex2);
void bfs(Graph *g,int vertex,int visited[]);
int isConnected(Graph *g);
void displayComponents(Graph *g);
int getDegree(Graph *g,int vertex);