#include <iostream>
using namespace std;

typedef struct edge *adrEdge;

struct edge{
    char destVertexId;
    adrEdge nextE; 
};

struct vertex{
    char Idvertex;
    adrEdge firstE;
    int degree, color;
};


vertex * insertVertex(vertex *g,int n){
    int i = 0;
    char x;
    cout << "Insert ID : ";
    while(i!=n){
        cin >> x;
        if(x >= 'A' && x <= 'Z'){
            g[i].Idvertex = x;
            g[i].firstE = NULL;
            g[i].color = 0;
            g[i].degree = 0;
            i++;
        }else{
            cout << "Invalid\n";
        }
    }
    return g;
}

adrEdge newEdge(char x){
    adrEdge p = new edge();
    p->destVertexId = x;
    p->nextE = NULL;
    return p;
}

bool cekVertex(vertex *g, int n, char x){
    bool cek = false;
    while(n!=0 && !cek){
        if(g[n].Idvertex == x){
            cek = true;
        }
        n--;
    }
    return cek;
}

vertex * insertEdge(vertex *g, int n){
    int i = 0, m = 0;
    char x;
    while(i!=n){
        printG(g,n);
        cout << "[" << g[i].Idvertex << "] Add how many? ";
        cin >> m;
        if(m!=0){
            cout << "Insert Edge : ";
        }
        while(m!=0){
            cin >> x;
            if(cekVertex(g,n,x)){
                
            }
        }
        i++;
    }
}

void printG(vertex g[], int n){
    int i = 0;
    while(i!=n){
        cout << g[i].Idvertex << " | ";
        i++;
    }
    cout << endl;
}

vertex * graphColoring(vertex *g, int n){

    return g;
}

int main(){
    int n = 0;
    cout << "Total? ";
    cin >> n;
    vertex graph[n];
    vertex* g = insertVertex(graph, n);
    printG(g,n); 
}