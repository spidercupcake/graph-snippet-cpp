#include<iostream>
using namespace std;

class Graph {
    private:
        int firstElement;
        int secondElement;

    public:
        // Constructor
        Graph(int firstElement, int secondElement) {
            this->firstElement = firstElement;
            this->secondElement = secondElement;
            cout << "Graph constructor executed." << endl;
            cout << "First elemet.	" << firstElement << endl;
            cout << "Second elemet.	" << secondElement << endl;
        }
};



int main() {
    // Passing arguments to the constructor
    int adjacencymatrix[5][5] = {
    	{1,2,3,4,5},
    	{6,7,8,9,0},
    	{1,2,3,4,5},
    	{6,7,8,9,0},
    	{1,2,3,4,5},
	};
    Graph graph1(adjacencymatrix[1][1], adjacencymatrix[2][2]);
    return 0;
}
