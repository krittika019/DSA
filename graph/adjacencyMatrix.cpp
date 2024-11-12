#include <iostream>
using namespace std;

const int V = 4;

void init(int arr[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            arr[i][j] = 0;
        }
    }
}

void addEdge(int arr[][V], int i, int j) {
    arr[i][j] = 1;
    arr[j][i] = 1;
}

void printAdjMatrix(int arr[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[V][V];
    init(arr);
    addEdge(arr, 0, 0);
    addEdge(arr, 0, 1);
    addEdge(arr, 1, 2);
    addEdge(arr, 3, 0);
    printAdjMatrix(arr);

    return 0;
}
