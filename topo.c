#include <stdio.h>
#define MAX 20

int graph[MAX][MAX];
int indegree[MAX] = {0};
int visited[MAX] = {0};

// Function to calculate initial indegree of all vertices
void makeIndegree(int n) {
    for (int i = 0; i < n; i++) {
        indegree[i] = 0; // Initialize to zero
        for (int j = 0; j < n; j++) {
            if (graph[j][i] == 1) { // If there's an edge from j to i
                indegree[i]++;
            }
        }
    }
}

// Decrease step: Find a vertex with 0 indegree that hasn't been visited
int findZeroin(int n) {
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0 && !visited[i]) {
            return i;
        }
    }
    return -1; // No source found (potential cycle)
}

// Conquer step: Process the vertex and reduce the problem size
void topoSort(int n) {
    makeIndegree(n);
    printf("Topological Order: ");

    for (int i = 0; i < n; i++) {
        int u = findZeroin(n);
        
        if (u == -1) {
            printf("\nCycle detected! Topological sort not possible.");
            return;
        }

        printf("%d ", u);
        visited[u] = 1;

        // "Remove" vertex: Reduce indegree of all its neighbors
        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1) {
                indegree[v]--;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topoSort(n);
    return 0;
}
