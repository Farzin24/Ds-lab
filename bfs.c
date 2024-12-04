#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct Graph_t {
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* Graph_create(int V) {
    Graph* g = malloc(sizeof(Graph));
    g->V = V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = false;
        }
    }
    return g;
}

void Graph_destroy(Graph* g) {
    free(g);
}

void Graph_addEdge(Graph* g, int v, int w) {
    g->adj[v][w] = true;
}

void Graph_BFS(Graph* g, int s) {
    bool visited[MAX_VERTICES + 1] = { false };
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[s] = true;
    queue[rear++] = s;

    while (front != rear) {
        s = queue[front++];
        printf("%d ", s);

        for (int adjecent = 0; adjecent < g->V; adjecent++) {
            if (g->adj[s][adjecent] && !visited[adjecent]) {
                visited[adjecent] = true;
                queue[rear++] = adjecent;
            }
        }
    }
}

int main() {
    int no_of_vertices;
    printf("Enter the no. of vertices in graph: ");
    scanf("%d", &no_of_vertices);
    Graph* g = Graph_create(no_of_vertices);

    int choice, sv, dv;
    while (1) {
        printf("Enter choice \n1. Add Edge\n2. BFS\n-1. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the source vertex: ");
                scanf("%d", &sv);
                printf("Enter the destination vertex: ");
                scanf("%d", &dv);
                Graph_addEdge(g, sv, dv);
                break;
            case 2:
                printf("Enter the source vertex: ");
                scanf("%d", &sv);
                printf("Following is Breadth First Traversal (starting from vertex %d):\n", sv);
                Graph_BFS(g, sv);
                printf("\n");
                break;
            case -1:
                printf("Exiting\n");
                Graph_destroy(g);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
