#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <stdexcept>

using namespace std;

class Vertex;

typedef vector<int> IntVector;

class Edge {
  int weight;
  Vertex* vertexPtr;

public:
  Edge(Vertex* vPtr, int w) {
    vertexPtr = vPtr;
    weight = w;
  }
  int getWeight() {
    return weight;
  }
  Vertex* getVertex() {
    return vertexPtr;
  }
};

typedef vector<Edge *> EdgeVector;

class Vertex {
  int data;
  bool visited;

public:
  EdgeVector edges;
  Vertex() {
    data = 0;
  }
  Vertex(int d) : data(d), visited(false) {
  }
  int getData() { return data; }
  void addEdge(Edge* edge) {
    edges.push_back(edge);
  }
  
  void clearVisitedFlag() {
    visited = false;
  }
  void setVisitedFlag() {
    visited = true;
  }
  bool isVisited() {
    return visited;
  }
};

class ColorVertex : public Vertex {
  int color;

public:
  ColorVertex(int c, int d) : color(c), Vertex(d) {
  }
  ColorVertex(int d) : color(-1), Vertex(d) {
  }
  int getColor() { return color; }
  void setColor(int c) { color = c; }
  bool isColorSet() { return (color != -1); }
};

typedef vector<Vertex *> VertexVector;
typedef unordered_map<int, Vertex *> VertexMap;
typedef deque<Vertex *> VertexQueue;


template <class VType>
class Graph {

protected:
  vector<VType *> adjacencyList;
  VertexMap vertexDataMap;

public:
  void addEdge(int data1, int data2, int weight) {
    if(vertexDataMap.find(data1) == vertexDataMap.end()) {
      VType* nVertex = new VType(data1);
      vertexDataMap[data1] = nVertex;
      adjacencyList.push_back(nVertex);
    }
    if(vertexDataMap.find(data2) == vertexDataMap.end()) {
      VType* nVertex = new VType(data2);
      vertexDataMap[data2] = nVertex;
      adjacencyList.push_back(nVertex);
    }
    VType* vertex1 = (ColorVertex *)vertexDataMap[data1];
    VType* vertex2 = (ColorVertex *)vertexDataMap[data2];
    Edge* edge = new Edge(vertex2, weight);
    vertex1->addEdge(edge);
  }

  void BFS(int data) {
    if(adjacencyList.empty()) {
      return;
    }
    if(vertexDataMap.find(data) == vertexDataMap.end()) {
      return;
    }
    for( VType* vertex: adjacencyList ) {
      vertex->clearVisitedFlag();
    }
    VertexQueue vQueue;
    vQueue.push_front(vertexDataMap[data]);    
    while(!vQueue.empty()) {
      VType* vertex = vQueue.back();
      vQueue.pop_back();
      vertex->setVisitedFlag();
      cout << vertex->getData() << endl;
      for (Edge* edge: vertex->edges) {
        cout << vertex->getData() << " --> " << edge->getVertex()->getData() << endl;
        if(!edge->getVertex()->isVisited()) {
          vQueue.push_front(edge->getVertex());
        }                
      }      
    }
  }

  void DFS(int data) {
    if(adjacencyList.empty()) {
      return;
    }
    if(vertexDataMap.find(data) == vertexDataMap.end()) {
      return;
    }
    for( VType* vertex: adjacencyList ) {
      vertex->clearVisitedFlag();
    }
    vector<VType *> vStack;
    vStack.push_back(vertexDataMap[data]);    
    while(!vStack.empty()) {
      VType* vertex = vStack.back();
      vStack.pop_back();
      vertex->setVisitedFlag();
      cout << vertex->getData() << endl;
      for (Edge* edge: vertex->edges) {
        if(!edge->getVertex()->isVisited()) {
          vStack.push_back(edge->getVertex());
        }
      }
    }
  }

  VType* getVertex(int data) {
    if(vertexDataMap.find(data) == vertexDataMap.end()) {
      return NULL;
    }
    return vertexDataMap[data];
  }
};
