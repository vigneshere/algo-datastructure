#include "graph.h"
#include <iostream>

typedef int color_t;
typedef unordered_map<color_t, bool> ColorMap;
typedef vector<color_t> ColorVector;


class ColoredGraph : public Graph<ColorVertex> {

  typedef vector<ColorVertex *>::iterator CVertexVectorIter;

public:

int Color(ColorVector& colors) {
  int maxColorUsed = 0;

  //Reset all the colors
  for(ColorVertex* cVertex:  adjacencyList) {
    cVertex->setColor(-1);
  }

  for(ColorVertex* cVertex:  adjacencyList) {
    ColorMap cmap;
    for(Edge* edge: cVertex->edges) {
      cmap[((ColorVertex *)(edge->getVertex()))->getColor()] = true;
    }
    for(color_t color: colors) {
      if(cmap.find(color) == cmap.end()) {
        cout << color << endl;
        cVertex->setColor(color);
        if(color > maxColorUsed) {
          maxColorUsed = color;
        }
        break;
      }
    }
  }
  return maxColorUsed;
}

};

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    ColoredGraph g;
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 4, 4);
    g.addEdge(4, 3, 2);
    g.addEdge(3, 5, 1);
    
    ColorVector cv = {1, 2, 3, 4, 5};
    cout << g.Color(cv) << endl;
    return 0;
}
