typedef struct Graph
{
    int vertex,weight;
    struct Graph *next;
}Graph;


Graph *createNode(int vertex,int weight);
void display_adjList(Graph *adjList[], int vertices);
void displayMST(Graph *MST[],int vertices);
void addEdge(Graph *adjList[],int vertex1,int vertex2,int weight);
void bfs(Graph *adjList[],int start,int visited[]);
void dfs(Graph *adjList[], int vertex, int visited[]);
void prims(Graph *adjList[], int startvertex, int vertices);



