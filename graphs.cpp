#include <iostream>
#include <climits>
using namespace std;


class Graph {
    private:
    	static const int size = 5;
        int link[size][size];
        int node[size] = {0 , INT_MAX , INT_MAX , INT_MAX , INT_MAX};

    public:
        // Constructor
        Graph(int adjacencymatrix[5][5]) {
        	for(int i=0; i<5; i++){
        		for(int j=0; j<5; j++){
        			link[i][j] = adjacencymatrix[i][j];
				}
			}
			showLinks();
        }
        
        void showLinks(){
			for	(int i=0; i<size; i++){
        		for	(int j=0; j<size; j++){
        			cout << link[i][j] << " ";
				}
				cout << endl;
			}
		}
		
        void showNodes(){
			for	(int i=0; i<size; i++){
				cout << endl << node[i];
			}
		}
		
        void valueOfNodes(){
        	int indexOf=0;
        	for	(int i=0; i < size; i++){
        		for	(int j=0; j<size; j++){
        			if	(link[i][j]!=0){
        				cout << endl << "[" << i << "][" << j << "] = " << link[i][j];
					};
				}
			}
		}
		

		void dijkastraAlgo(){
        	for	(int i=0; i < size; i++){
        		for	(int j=0; j < size; j++){
        			if(link[i][j]!=0)
        				if(node[i]+link[i][j]<node[j]){
        					node[j]=node[i]+link[i][j];        					
						}						                    
				}                     				
			}
		};
	
};			

//			MIGHT USE LATER

//    		int startIndex = 3;  						// Starting index
//    		for (int i = 0; i < size; i++) {
//    		    int index = (startIndex + i) % size;	// LEARN WTF THIS IS
//    		    cout << index << " : " << node[index] << endl;	
//		    }




int main() {

    int adjacencymatrix[5][5]={
		{0, 1, 2, 0, 0},
		{0, 0, 4, 5, 0},
		{0, 0, 0, 0, 2},
		{0, 0, 0, 0, 8},
		{0, 3, 0, 0, 0},
	};                
	                  
    // Passing arguments to the constructor
    Graph myGraph(adjacencymatrix);
    cout << endl;
    
    myGraph.dijkastraAlgo();
    cout << endl;
    
    myGraph.showNodes();
//    cout << endl;      


    
    return 0;
}
