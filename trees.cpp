#include<iostream>
#include<queue>
#include<stack>
using namespace std ;

class Node{
    public :
        int value ;
        Node* right ;
        Node* left ;
        Node(int value){
            this->value = value ;
            right = nullptr ;
            left = nullptr ;
        }
};

class BST{
    private :
        Node* root ;
    public :
        BST() {
            root = nullptr ;
        }

        bool insert(int value) {
            Node* newNode = new Node(value) ;
            if(root == nullptr){
                root = newNode ;
                return true ;
            }
            Node* temp = root ;
            while(1){
                if(temp->value > newNode->value){
                    if(temp->left == nullptr){
                        temp->left = newNode ;
                        return true ;
                    }
                    temp = temp->left ;
                }
                else if(temp->value < newNode->value){
                    if(temp->right == nullptr){
                        temp->right = newNode ;
                        return true ;
                    }
                    temp = temp->right ;
                }
                else{
                    return true ;
                }
            }

        }

        Node* rInsert(Node* currentNode, int value){
            if(currentNode == nullptr) return new Node(value) ;
            if( value < currentNode->value ){
                currentNode->left = rInsert(currentNode->left, value) ;
            }
            else if(value > currentNode->value){
                currentNode->right = rInsert(currentNode->right, value) ;
            }
            return currentNode ;
        }

        void rInsert(int value){
            rInsert(root, value) ;
        }

        bool Search(int value){
            if( root == nullptr ){
                return false ;
            }
            Node* temp = root ;
            while(temp != nullptr){
                if(value > temp->value){
                    temp = temp->right ;
                }
                else if(value < temp->value){
                    temp = temp->left ;
                }
                else{
                    return true ;
                }
            }
            return false ;
        }

        bool rSearch(Node* currentNode, int value) {
            if(currentNode == nullptr) return false ;
            if(value == currentNode->value){
                return true ; 
            }
            else if(value > currentNode->value){
                return rSearch(currentNode->right, value) ;
            }
            else{
                return rSearch(currentNode->left, value) ;
            }
        }

        bool rSearch(int value){
            return rSearch(root, value) ;
        }
        int minValue(Node* currentNode){
            while(currentNode->left != nullptr){
                currentNode = currentNode->left ;
            }
            return currentNode->value ;
        }

        int minValue(){
            return minValue(root) ;
        }

        int maxValue(Node* currentNode){
            while(currentNode->right != nullptr){
                currentNode = currentNode->right ;
            }
            return currentNode->value ;

        }
        int maxValue(){
            return maxValue(root) ;
        }

        Node* deleteNode(Node* currentNode, int value){
            if(currentNode == nullptr) return nullptr;
            if(currentNode->value > value){
                currentNode->left = deleteNode(currentNode->left, value) ;
            }
            else if(currentNode->value < value){
                currentNode->right = deleteNode(currentNode->right, value) ;
            }
            else{
                //leaf node
                if(currentNode->left == nullptr && currentNode->right == nullptr){
                    Node* temp = currentNode ;
                    delete temp ;
                    currentNode = nullptr ;
                }
                else if(currentNode->left == nullptr){
                    Node* temp = currentNode->right ;
                    delete(currentNode) ;
                    return temp ;
                }
                else if(currentNode->right == nullptr){
                    Node* temp = currentNode->left ;
                    delete (currentNode) ;
                    return temp ;
                }
                else{
                    int subTreeMin = maxValue(currentNode->left) ;
                    currentNode->value = subTreeMin ;
                    currentNode->left = deleteNode(currentNode->left, subTreeMin) ;
                }

            }
            return currentNode ;
        }

        void deleteNode(int value){
            root = deleteNode(root, value) ; 
        }

        void DFSPreorder(Node* currentNode){
            cout << currentNode->value << " " ;
            if(currentNode->left){
                DFSPreorder(currentNode->left) ;
            }
            if(currentNode->right){
                DFSPreorder(currentNode->right) ;
            }
        }

        void DFSPreorder(){
            DFSPreorder(root) ;
        }
        void DFSPostorder(Node* currentNode){
            if(currentNode->left){
                DFSPreorder(currentNode->left) ;
            }
            if(currentNode->right){
                DFSPreorder(currentNode->right) ;
            }
            cout << currentNode->value << " " ;
        }

        void DFSPostorder(){
            DFSPostorder(root) ;
        }
        void DFSInorder(Node* currentNode){
            if(currentNode->left){
                DFSInorder(currentNode->left) ;
            }
            cout << currentNode->value << " " ;
            if(currentNode->right){
                DFSInorder(currentNode->right) ;
            }
        }

        void DFSInorder(){
            DFSInorder(root) ;
        }
        // LEVEL ORDER TRAVERSAL
        void BFS() {
            queue<Node*> myQueue ;
            myQueue.push(root) ;
            while(myQueue.size() > 0){
                Node* currentNode = myQueue.front() ;
                myQueue.pop() ;
                cout << currentNode->value << " " ;
                if(currentNode->left != nullptr){
                    myQueue.push(currentNode->left) ;
                }
                if(currentNode->right != nullptr){
                    myQueue.push(currentNode->right) ;
                }
            }
        }
        //line by line
        void levelorder() {
            queue<Node*> q ;
            q.push(root) ;
            while(q.size() > 0) {
                int count = q.size() ;
                for(int i = 0; i < count; i++) {
                    Node* currentNode = q.front() ;
                    q.pop() ;
                    cout << currentNode->value << " " ;
                    if(currentNode->left != nullptr){
                        q.push(currentNode->left) ;
                    }
                    if(currentNode->right != nullptr){
                        q.push(currentNode->right) ;
                    }
                }
                cout << endl ;
            }

        }
 
        // COUNT NODE
        //recursive
        int countNode(Node* currentNode) {
            //base case
            if ( currentNode == nullptr ) {
                return 0 ;
            }
            else {
                return 1 + countNode(currentNode->left) + countNode(currentNode->right) ;
            }
        }
        int countNode() {
            return countNode(root) ;
        }

        // MAXIMUM NODE
        // recurive 
        int getMaxNode(Node* currentNode) {
            //base case
            if ( currentNode == nullptr ) return INT_MIN ;
            else {
                return max(currentNode->value, max(getMaxNode(currentNode->left), getMaxNode(currentNode->right))) ;
            }
        }

        int getMaxNode() {
            return getMaxNode(root) ;
        }
        
        bool checkTree(Node* root) {
            if(root->left == nullptr && root->right == nullptr) {
                return true ;
            }
            else if(root->left == nullptr) {
                return false ;
            }
            else if (root->right == nullptr) {
                return false ;
            }
            else{
                return root->value == checkTree(root->left) + checkTree(root->right) ;
            }
        }
        void norec_inorder(){
            if(root == nullptr) return ;
            Node* temp = root ;
            stack<Node*> s ;
            while(temp != nullptr || !s.empty()){
                while(temp){
                    s.push(temp) ;
                    temp = temp->left ;
                }

                temp = s.top() ;
                s.pop() ;
                cout << temp->value << " " ;
                temp = temp->right ;
            }
        }
};

int main(){
    BST *myBST = new BST() ;
    myBST->insert(10) ;
    myBST->rInsert(4) ;
    myBST->insert(20) ;
    myBST->insert(15) ;
    myBST->levelorder() ;
    return 0 ;
}
