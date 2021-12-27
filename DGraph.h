#ifndef DGraph_H_INCLUDED
#define DGraph_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct edge *adrEdge;
typedef struct vertex *adrVertex;

struct edge{
    char destVertexId;
    int weight;
    adrEdge nextE; 
};

struct vertex{
    char Idvertex;
    adrVertex nextV;
    adrEdge firstE;
};
struct graph{
    adrVertex firstV;
};

adrVertex createV(char IdV);
void initGraph(graph &G);
void addV(graph &G, char IdV);
void buildG(graph &G);
adrVertex findV(graph G, char IdV);
void printG(graph G);

adrEdge createE(char destNodeId, int weight);
void addE(graph &G, char originNodeId, char destNodeId);
int outDegree(graph G, char nodeID);

void seeDegree(graph G);

#endif // DGraph_H_INCLUDED