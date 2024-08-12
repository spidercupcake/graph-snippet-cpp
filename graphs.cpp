#include <iostream>
#include <climits>
using namespace std;

class Graph {
    private:
        static const int size = 5;
        int link[size][size];
        int node[size];
        bool visited[size]; // To track visited nodes

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
                visited[i] = false; // Initialize all nodes as unvisited
            }
            node[0] = 0; // Starting node
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
};


//			MIGHT USE LATER

//    		int startIndex = 3;  						// Starting index
//    		for (int i = 0; i < size; i++) {
//    		    int index = (startIndex + i) % size;	// LEARN WTF THIS IS
//    		    cout << index << " : " << node[index] << endl;	
//		    }



int main() {
    int adjacencymatrix[5][5] = {
        {0, 1, 2, 0, 0},
        {0, 0, 4, 5, 0},
        {0, 0, 0, 0, 2},
        {0, 0, 0, 0, 8},
        {0, 3, 0, 0, 0},
    };

    // Passing arguments to the constructor
    Graph myGraph(adjacencymatrix);
    
    myGraph.dijkstraAlgo();
    myGraph.showNodes();

    return 0;
}
