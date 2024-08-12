# Graph Utility Snippet

This project provides a utility snippet that simplifies working with graph objects in C++. The snippet includes functions for easy manipulation and traversal of graphs using adjacency matrices and other common representations.

## Features
- Simplified creation of graph objects
- Easy-to-use functions for adding and removing links
- Supports common graph algorithms like Bellman-Ford and Dijkstra
- Handles both directed and undirected graphs

## Usage
To use this snippet in your project, copy the code into your main file and call the relevant functions to create and manipulate your graphs.

### Example Usage

```cpp
#include <iostream>
using namespace std;

// Define the Graph class and its methods here

int main() {
    // Define your adjacency matrix
    int adjacencymatrix[5][5] = {
        {0, -1,  4,  0,  0},
        {0,  0,  3,  2,  2},
        {0,  0,  0,  0,  0},
        {0,  1,  5,  0,  0},
        {0,  0,  0, -3,  0},
    };

    // Create a Graph object
    Graph myGraph(adjacencymatrix);
    
    // Run Bellman-Ford algorithm
    myGraph.bellmanFordAlgo();
    myGraph.showNodes();

    // Optionally, reset and run Dijkstra's algorithm
    myGraph.resetNodes();
    myGraph.dijkstraAlgo();
    myGraph.showNodes();

    return 0;
}
