#include <iostream>
#include <climits>
using namespace std;

class Graph {
    private:
        static const int size = 5;  // keep it static constant or the code will shout at you
        int link[size][size];
        int node[size];

    public:
        // Constructor
        Graph(int adjacencymatrix[5][5]) {
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    link[i][j] = adjacencymatrix[i][j];
                }
            }
            for (int i = 0; i < size; i++) {
                node[i] = INT_MAX; // Initialize nodes with "infinity"
            }
            node[0] = 0; // Starting node
        }
        
        void resetNodes() {
            for (int i = 0; i < size; i++) {
                node[i] = INT_MAX;
            }
            node[0] = 0;
        }

        void showLinks() {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    cout << link[i][j] << " ";
                }
                cout << endl;
            }
        }
        
        void showNodes() {
            for (int i = 0; i < size; i++) {
                cout << "Node " << i << ": " << node[i] << endl;
            }
        }

        void dijkstraAlgo() {
            bool visited[size] = {false};

            for (int count = 0; count < size - 1; count++) {
                int minDistance = INT_MAX;
                int minIndex = -1;

                // Find the node with the smallest distance that hasn't been visited
                for (int i = 0; i < size; i++) {
                    if (!visited[i] && node[i] <= minDistance) {
                        minDistance = node[i];
                        minIndex = i;
                    }
                }

                // Mark the picked node as visited
                visited[minIndex] = true;

                // Update the distance value of the adjacent nodes
                for (int i = 0; i < size; i++) {
                    if (!visited[i] && link[minIndex][i] && node[minIndex] != INT_MAX 
                        && node[minIndex] + link[minIndex][i] < node[i]) {
                        node[i] = node[minIndex] + link[minIndex][i];
                    }
                }
            }
        }

        void bellmanFordAlgo() {
            // Relax all edges |V| - 1 times
            for (int k = 0; k < size - 1; k++) {
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (link[i][j] != 0 && node[i] != INT_MAX 
                            && node[i] + link[i][j] < node[j]) {
                            node[j] = node[i] + link[i][j];
                        }
                    }
                }
            }
            
            // Check for negative-weight cycles
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (link[i][j] != 0 && node[i] != INT_MAX 
                        && node[i] + link[i][j] < node[j]) {
                        cout << "Graph contains a negative-weight cycle" << endl;
                        return;
                    }
                }
            }
        }
};

int main() {
int adjacencymatrix[5][5] = {
    {0, -1,  4,  0,  0},
    {0,  0,  3,  2,  2},
    {0,  0,  0,  0,  0},
    {0,  1,  5,  0,  0},
    {0,  0,  0, -3,  0},
};

    // Passing arguments to the constructor
    Graph myGraph(adjacencymatrix);
    
    // Use Bellman-Ford algorithm
    myGraph.bellmanFordAlgo();
    myGraph.showNodes();
    
    // To use Dijkstra's algorithm instead, reset nodes and uncomment the lines below:
    // myGraph.resetNodes();
    // myGraph.dijkstraAlgo();
    // myGraph.showNodes();

    return 0;
}
