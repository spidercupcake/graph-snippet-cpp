#include<iostream>
using namespace std;

class Graph {
    private:
        int matrix[5][5];

    public:
        // Constructor
        Graph(int adjacencymatrix[5][5]) {
        	for(int i=0; i<5; i++){
        		for(int j=0; j<5; j++){
        			matrix[i][j] = adjacencymatrix[i][j];
				}
			}
			for(int i=0; i<5; i++){
        		for(int j=0; j<5; j++){
        			cout << matrix[i][j];
				}
			}
        }
    
};



int main() {

	
    int adjacencymatrix[5][5]={
    	{1,2,3,4,5},
    	{6,7,8,9,0},
    	{1,2,3,4,5},
    	{6,7,8,9,0},
    	{1,2,3,4,5},
	};
	
    // Passing arguments to the constructor
    Graph graph2(adjacencymatrix);
    return 0;
}
