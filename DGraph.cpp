#include "DGraph.h"
#include <iostream>
using namespace std;

adrVertex createV(char IdV){
    adrVertex p = new vertex();
    p->Idvertex = IdV;
    p->nextV = NULL;
    p->firstE = NULL;
    return p;
}

void initGraph(graph &G){
    G.firstV = NULL;

}
void addV(graph &G, char IdV){
    if(G.firstV ==NULL){
        adrVertex v = createV(IdV);
        G.firstV = v;
        
    }else{
        adrVertex v = createV(IdV), p = G.firstV;
        while(p->nextV !=NULL){
            p = p->nextV;
        }
        p->nextV = v;
    }
}
void buildG(graph &G){
    char data;
    bool cek = true, t = false;
    cout << "Input vertex ID : ";
    cin >> data;
    while(cek){
        if(data >= 'A' && data <= 'Z'){
            if(G.firstV ==NULL){
                addV(G, data);
            }
            if(findV(G, data) == NULL && t){
                addV(G,data);
            }else if(findV(G, data) != NULL && t){
                cout << "Vertex ID already exist\n";
            }
            cout << "Input vertex ID : ";
            cin >> data;
            t = true;
        }else{
            cek = false;
        }
    }
}

adrVertex findV(graph G, char IdV){
    adrVertex p = NULL;
    if(G.firstV !=NULL){
        bool cek = true;
        p = G.firstV;
        while(p!=NULL && cek){
            if(p->Idvertex == IdV && cek){
                cek = false;
            }else{
                p = p->nextV;
            }
        }
    }
    return p;
}
void printG(graph G){
    if(G.firstV !=NULL){
        cout << "----Print Graph----\n";
        adrVertex p = G.firstV;
        while(p != NULL){
            cout << p->Idvertex << " | ";
            p = p->nextV;
        }
    }
}

adrEdge createE(char destNodeId, int weight){
    adrEdge p = new edge();
    p->destVertexId = destNodeId;
    //p->weight = weight;
    p->nextE = NULL;
    return p;
}
void addE(graph &G, char originNodeId, char destNodeId){
    adrVertex v = findV(G, originNodeId);
    adrEdge e;
    int weight = 0 ;
    if(v!=NULL){
        if(v->firstE == NULL){
            //cout << "Weight = ";
            //cin >> weight;
            e = createE(destNodeId, weight);
            v->firstE = e;
        }else{
            e = v->firstE;
            while(e->nextE!=NULL){
                e = e->nextE;
            }
            //cout << "Weight = ";
            //cin >> weight;
            e->nextE = createE(destNodeId, weight);
        }
    }
}
int outDegree(graph G, char nodeID){
    int n = 0;
    if(G.firstV !=NULL){
        adrVertex v = findV(G, nodeID);
        if(v!=NULL){
            adrEdge e = v->firstE;
            while(e!=NULL){
                n++;
                e = e->nextE;
            }
        }
    }
    return n;
}

void seeDegree(graph G){
    adrVertex p;
    if(G.firstV != NULL){
        p = G.firstV;
        while(p!=NULL){
            cout << p->Idvertex << " | " << outDegree(G, p->Idvertex) << "\n";
            p = p->nextV;
        }
    }
}

string colour(int code){
    string x = "";
    if(code == 1){
        x = "Red";
    }else if(code == 2){
        x = "Blue";
    }else if(code == 3){
        x = "Yellow";
    }else if(code == 4){
        x = "Green";
    }
    return x;
}

void Keqing(graph G){
    int n = 1;
    adrVertex p, m, c;
    adrEdge e;
    if(G.firstV != NULL){
        p = G.firstV;
        m = p;
        cout << "Test\n";
        p->nextV;
        while(p!=NULL){
            if(outDegree(G, m->Idvertex) < outDegree(G, p->Idvertex)){
                m = p;
            }
            p = p->nextV;
        }
    }
    cout << m->Idvertex <<" | "<< outDegree(G, m->Idvertex) << " | " << colour(n) << endl;
    p = G.firstV;
    p = p->nextV;
    bool cek = true;
    while(p!=NULL){
        e = p->firstE;
        while(e!=NULL){
            c = G.firstV;
            while(c != NULL && cek){
                if(c->Idvertex == e->destVertexId){
                    n++;
                    cek = false;
                }
                c = c->nextV;
            }
            cek = true;
            e = e->nextE;
        }
        cout << p->Idvertex <<" | "<< outDegree(G, p->Idvertex) << " | " << colour(n) << endl;
        p = p->nextV;
    }
}

