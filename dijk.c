#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Step 1: Defining Node structure
struct node {
    char name;
    int weight;
    struct node* next;
};

// Step 2: Define WeightedGraph structure
struct WeightedGraph {
    int directed;
    int vertices;
    struct node** adj;
};

// Step 3: Function to create a new node
struct node* createNode(char n, int w) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->name = n;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Step 4: Function to create a new Weighted Graph
struct WeightedGraph* createWeightedGraph(int vertices, int directed) {
    struct WeightedGraph* graph = (struct WeightedGraph*)malloc(sizeof(struct WeightedGraph));
    graph->directed = directed;
    graph->vertices = vertices;
    graph->adj = (struct node**)malloc(vertices * sizeof(struct node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adj[i] = NULL;
    }

    return graph;
}

// Step 5: Function to add an edge to the graph
void addEdge(struct WeightedGraph* graph, char src, char dest, int weight) {
    // Create a new node for the destination vertex
    struct node* newNode = createNode(dest, weight);

    // Add the new node to the source vertex's adjacency list
    newNode->next = graph->adj[src - 'A'];
    graph->adj[src - 'A'] = newNode;

    // If the graph is undirected, add an edge in the other direction
    if (!graph->directed) {
        newNode = createNode(src, weight);
        newNode->next = graph->adj[dest - 'A'];
        graph->adj[dest - 'A'] = newNode;
    }
}

// Step 6: Function to print the graph
void printGraph(struct WeightedGraph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        struct node* current = graph->adj[i];
        printf("Vertex %c: ", i + 'A');
        while (current != NULL) {
            printf("(%c,%d) -> ", current->name, current->weight);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Step 7: Function to free memory used by the graph
void freeGraph(struct WeightedGraph* graph) {
    // Free each linked list
    for (int i = 0; i < graph->vertices; i++) {
        struct node* current = graph->adj[i];
        while (current != NULL) {
            struct node* next = current->next;
            free(current);
            current = next;
        }
    }

    // Free the array of linked lists
    free(graph->adj);

    // Free the graph structure
    free(graph);
}

// Step 8: Dijkstra's algorithm functions
// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int sptSet[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the path from source to the given vertex
void printPath(int parent[], int j) {
    // Base case: If the source vertex itself
    if (parent[j] == -1)
        return;

    // Recursive call to printPath
    printPath(parent, parent[j]);

    printf("%c ", j + 'A');
}

// Function to perform Dijkstra's algorithm
void dijkstra(struct WeightedGraph* graph, char src) {
    int vertices = graph->vertices;
    int dist[vertices];
    int parent[vertices];
    int sptSet[vertices];

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    // Distance of source vertex from itself is always 0
    dist[src - 'A'] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < vertices - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(dist, sptSet,vertices);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        struct node* current = graph->adj[u];
        while (current != NULL) {
            int v = current->name - 'A';
            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + current->weight < dist[v]) {
                dist[v] = dist[u] + current->weight;
                parent[v] = u;
            }
            current = current->next;
        }
    }

    // Print the constructed distance array and paths
    printf("Shortest paths from source %c:\n", src);
    for (int i = 0; i < vertices; i++) {
        printf("To vertex %c: Distance %d, Path: %c ", i + 'A', dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}

// Step 9: Main function
int main() {
    int vertices = 7;
    int directed = 0; // Set to 1 for a directed graph, 0 for an undirected graph

    struct WeightedGraph* graph = createWeightedGraph(vertices, directed);
    addEdge(graph, 'A', 'B', 4);
    addEdge(graph, 'A', 'C', 2);
    addEdge(graph, 'A', 'D', 8);
    addEdge(graph, 'B', 'F', 3);
    addEdge(graph, 'C', 'E', 3);
    addEdge(graph, 'C', 'G', 6);
    addEdge(graph, 'D', 'F', 1);
    addEdge(graph, 'D', 'G', 3);
    addEdge(graph, 'E', 'G', 2);
    addEdge(graph, 'F', 'G', 4);

    printGraph(graph);

    // Example of Dijkstra's algorithm
    dijkstra(graph, 'A');

    // Free memory
    freeGraph(graph);

    return 0;
}

