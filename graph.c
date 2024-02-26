#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// step 1. defining Node structure
struct node {
    char name;
    int weight;
    struct node* next;
};
// step 2 define WeightedGraph structure
struct WeightedGraph {
    int directed;
    int vertices;
    struct node** adj;
};

// ste 3 Function to create a new node
struct node* createNode(char n, int w) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->name = n;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}



// step 4 Function to create a new Weighted Graph
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

// step 5 Function to add an edge to the graph
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

// step 6 Function to print the graph
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

//step 7 Function to free memory used by the graph
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

//  step 8Main function
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
}

