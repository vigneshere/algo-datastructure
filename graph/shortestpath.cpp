#include "graph.h"
#include <iostream>

struct PathWeight {
  int weight;
  VertexVector path;
  PathWeight() {
    weight = 0;
  }
  PathWeight(int w, VertexVector& p) {
    weight = w;
    path = p;
  }
};

typedef struct PathWeight PathWeight;
typedef unordered_map<Vertex *, PathWeight*> VertexPWMap;
VertexPWMap dpResults;

PathWeight* shortestPath(Vertex*& v1, Vertex*& v2) {

  if(!v1 || !v2 || v1->getData() == v2->getData()) {
    return NULL;
  }

  if(dpResults.find(v1) != dpResults.end()) {
    return dpResults[v1];
  }

  PathWeight* minPW = new PathWeight();
  for(Edge* e: v1->edges) {
    Vertex* tVertex = e->getVertex();
    cout << v1->getData() << "-" << v2->getData() << " " << tVertex->getData() << endl;
    if (tVertex->getData() == v2->getData() && ((e->getWeight() < minPW->weight) || !minPW->weight)) {
      cout << "end node" << endl;
      vector <Vertex *> tempPath;
      tempPath.push_back(v2);  
      minPW->weight = e->getWeight();
      minPW->path = tempPath;
      continue;
    }
    PathWeight* pw = shortestPath(tVertex, v2);
    if (!pw) {
      continue;
    }
    if(!minPW->weight || ((pw->weight + e->getWeight()) < minPW->weight) ) {
      minPW->weight = pw->weight + e->getWeight();
      minPW->path = pw->path;
    }
  }
   
  minPW->path.push_back(v1); 
  dpResults[v1] = minPW;
  return minPW;
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph<Vertex> g;
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 4, 4);
    g.addEdge(4, 3, 2);
    g.addEdge(3, 5, 1);

    Vertex* v1 = g.getVertex(1);
    Vertex* v2 = g.getVertex(5);
    cout << "v1 " << v1->getData() << endl;
    cout << "v2 " << v2->getData() << endl;

    PathWeight* pw = shortestPath(v1, v2);
    if (pw->path.empty()) {
      cout << "No path" << endl;
      return 1;
    }
    for(Vertex* v: pw->path) {
      cout << v->getData() << " ";
    }
    cout << endl;
    cout << "Distance " << pw->weight << endl;
    return 0;
}
