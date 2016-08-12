#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <stdexcept>
#include "graph.h"

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph<Vertex> g;
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 0, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 3, 1);
 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}
