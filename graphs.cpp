#include <iostream>
#include <climits>
using namespace std;


class Graph {
    private:
//    	const int size;
        int matrix[5][5];
        int NodeValues[5] = {0 , INT_MAX , INT_MAX , INT_MAX , INT_MAX};

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
        void valueOfNodes(){
        	for(int i=0; i<5; i++){
        		for(int j=0; j<5; j++){
        			if(matrix[i][j]!=0){
        				cout << endl << "[" << i << "][" << j << "] = " << matrix[i][j];
					};
				}
			}
		}
		
		void dijkastraAlgo(){
			cout << endl << "Hello World";
		}
    
};



int main() {

    int adjacencymatrix[5][5]={
    	{0, 1, 2, 0, 0},
		{0, 0, 4, 5, 0},
		{0, 0, 0, 0, 2},
		{0, 0, 0, 0, 8},
		{0, 3, 0, 0, 0}
	};
	
    // Passing arguments to the constructor
    Graph myGraph(adjacencymatrix);
    
    myGraph.valueOfNodes();
    myGraph.dijkastraAlgo();
    return 0;
}
