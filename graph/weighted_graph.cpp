#include <iostream>
#include<algorithm>
using namespace std;

const int V = 4;

void init(int arr[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            arr[i][j] = 0;
        }
    }
}

void addEdge(int arr[][V], int i, int j, int weight) {
    arr[i][j] = weight;
    arr[j][i] = weight;
}

void printAdjMatrix(int arr[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int primeMST(int arr[][V]) {
    int key[V], res = 0 ;
    fill(key, key + V, INT_MAX) ;
    key[0] = 0 ;
    bool mSet[V] = {false} ;
    for(int count = 0; count < V; count++) {
        int u = -1 ; // finding minimum weighted vertex 
        for(int i = 0; i < V; i++) {
            if(!mSet[i] && (u == -1 || key[i] < key[u])) u = i ;
        }
        mSet[u] = true ;
        res += key[u] ;

        for(int v = 0; v < V; v++) {
            if(arr[u][v] != 0 && !mSet[v]) {
                key[v] = min(key[v], arr[u][v]) ;
            }
        }
    }
    return res ;

}

int main() {
    int arr[V][V];
    init(arr);
    addEdge(arr, 0, 1, 5);
    addEdge(arr, 0, 2, 8);
    addEdge(arr, 1, 2, 10);
    addEdge(arr, 1, 3, 15);
    addEdge(arr, 2, 3, 20) ;
    addEdge(arr, 2, 0, 8);
    addEdge(arr, 1, 0, 5);
    addEdge(arr, 2, 1, 10);
    addEdge(arr, 3, 1, 15);
    addEdge(arr, 3, 2, 20) ;
    printAdjMatrix(arr);
    cout << endl ;
    cout << primeMST(arr) ;
    return 0;
}
