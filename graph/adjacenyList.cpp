#include<iostream>
#include<queue>
#include<vector>
using namespace std ;

class graphNode{
    public :
        int value ;
        graphNode *next ;
        graphNode(int value) {
            this->value = value ;
            next = nullptr ;
        }
};
class listGraph{
    private :
        graphNode* adList[7] ;
        int num ;
    public :
        listGraph(int n) {
            num = n ;
            for(int i = 0; i < num; i++) {
                adList[i] = nullptr ;
            }
        }
        void create() {
            int i, j ;
            char answer ;
            graphNode *temp ;
            graphNode *newNode ;
            for(i = 0; i < num; i++) {
                for(j = 0; j < num; j++) {
                    cout << "Is there an edge between vertex " << i + 1 << " and " << "vertex " << j + 1 ;
                    cout << "Enter Y/y for yes : " ;
                    cin >> answer ;
                    if(answer == 'Y' || answer == 'y') {
                        newNode = new graphNode(j+1) ;

                        if(adList[i] == nullptr) {
                            adList[i] = newNode ;
                            temp = adList[i] ;
                        }
                        else{
                            temp->next = newNode ;
                            temp = newNode ;
                        }
                    }
                }
            }
        }

        void addEdge(int vertex_1, int vertex_2) {
            graphNode *newNode = new graphNode(vertex_2) ;
            if(adList[vertex_1 - 1] == nullptr) {
                adList[vertex_1 - 1] = newNode ;
                return ;
            }
            graphNode *temp = adList[vertex_1 - 1] ;
            while(temp->next != nullptr) {
                temp =temp->next ;
            }
            temp->next = newNode ;
        }

        void display() {
            int i ;
            graphNode* temp ;
            for(i = 0; i < num; i++) {
                cout << "Vertex " << i + 1 << " ->  " ;
                temp = adList[i] ;
                while(temp != nullptr) {
                    cout << "V" << temp->value << " ->  " ;
                    temp = temp->next ;
                }
                cout << "NULL" ;
                cout << endl ;
            }
            cout << endl ;
        }

        void checkanEdge(int vertex_1, int vertex_2) {
            graphNode* temp = adList[vertex_1-1] ;
            while(temp != nullptr) {
                if(temp->value == vertex_2){
                    cout << "An edge is present " << endl ;
                    return ;
                }
                temp =temp->next ;
            }
            cout << "An edge is not present " << endl ;
        }

        void removeVertex(int vertex) {
            if (vertex < 1 || vertex > num) {
                cout << "Vertex out of bounds!" << endl;
                return;
            }
            for(int i = 0; i < num; i++) {
                if(i + 1 == vertex) continue; 
                graphNode *curr = adList[i] ;
                graphNode *prev = nullptr ;
                while(curr != nullptr) {
                    if(curr->value == vertex) {
                        if(prev == nullptr) {
                            adList[i] = curr->next ;
                        }
                        else {
                            prev->next = curr->next ;
                        }
                        delete curr ;
                        break ;
                    }
                    prev = curr ;
                    curr = curr->next ;
                }
            }

            graphNode *curr = adList[vertex - 1] ;
            while(curr != nullptr) {
                graphNode* nextNode = curr->next ;
                delete curr ;
                curr = nextNode ;
            }
            adList[vertex-1] = nullptr ;
        }

        void BFS(int sourceVertex) {
            queue<graphNode*> q ;
            vector<bool> visited(num, false) ;
            q.push(adList[sourceVertex - 1]) ;
            visited[sourceVertex - 1] = true ;
            cout << sourceVertex << " " ;
            while(q.empty() == false) {
                graphNode* current = q.front() ;
                q.pop() ;

                while(current != nullptr) {
                    int vertexIdx = current->value - 1 ;
                    if(!visited[vertexIdx]) {
                        visited[vertexIdx] = true ;
                        q.push(adList[vertexIdx]) ;
                        cout << current->value << " " ;
                    }
                    current = current->next ;
                }
            }

        }

        void DFSRec(int sourceVertex, vector<bool> &visited) {
            visited[sourceVertex - 1] = true ;
            cout << sourceVertex << " " ;

            graphNode* node = adList[sourceVertex - 1] ;
            while(node != nullptr) {
                if(!visited[node->value - 1]) {
                    DFSRec(node->value, visited) ;
                }
                node = node->next ;
            }
        }

        void DFS(int sourceVertex){
            vector<bool> visited(num, false) ;
            DFSRec(sourceVertex, visited) ;
        }
};

int main() {
    listGraph* myGraph = new listGraph(4) ;
    myGraph->addEdge(1,2) ;
    myGraph->addEdge(1,3) ;
    myGraph->addEdge(2,3) ;
    myGraph->addEdge(3,1) ;
    myGraph->addEdge(2,1) ;
    myGraph->addEdge(3,2) ;
    myGraph->addEdge(3,4) ;
    myGraph->addEdge(4,3) ;
    myGraph->display() ;
    myGraph->BFS(4) ;
    cout << endl ;

    
    myGraph->DFS(1) ;
    return 0 ;
}