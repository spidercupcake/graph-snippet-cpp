#include<iostream>
using namespace std;

class Graph {
    private:
        int id;
        int name;

    public:
        // Constructor
        Graph(int id, int name) {
            this->id = id;
            this->name = name;
            cout << "Graph constructor executed." << endl;
        }
};

int main() {
    // Passing arguments to the constructor
    Graph graph1(1, 10);
    return 0;
}
