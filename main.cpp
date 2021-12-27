#include <iostream>
#include "DGraph.cpp"

using namespace std;

int main(){
    graph G;
    adrVertex v;
    adrEdge e;
    char data, idE;
    string t;
    bool cek = true;

    initGraph(G);
    buildG(G);
    int n = 0;
    cout << endl;
    while(t!="N" && t!= "n"){
        printG(G);
        cout << "\nAdd edge to vertex : ";
        cin >> data;
        cout << "How many? ";
        cin >> n;
        cout << "Edge Id : ";
        while(findV(G, data)!=NULL && n!=0){
            cin >> idE;
            if(idE >= 'A' && idE <= 'Z' && findV(G, idE)!=NULL){
                addE(G, data, idE);
            }else{
                cout << "Edge Id invalid\n";
            }
            n--;
        }
        cout << "Continue? ";
        cin >> t;
    }
    
    sort(G);


    return 0;
}