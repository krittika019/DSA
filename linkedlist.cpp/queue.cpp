#include<iostream>
using namespace std ;

class Node{
    public :
        int value ;
        Node* next ;
        Node(int value){
            this->value = value ;
            next = nullptr ;
        }
};

class Stack{
    private :
        Node* top ;
        int height ;
    public :
        Stack(int value){
            Node* newnode = new Node(value) ;
            top = newnode ;
            height = 1 ;
        }

        void printstack(){
            Node* temp = top ;
            while(temp){
                cout << temp->value << endl ;
                temp = temp->next ;
            }
        }
        void push(int value){
            Node* newstack = new Node(value) ;
            newstack->next = top ;
            top = newstack ;
            height++ ;
        }

        int pop(){
            if(height == 0){
                return INT_MIN ;
            }
            Node* temp = top ;
            int poppedvalue = top->value ;
            top = top->next ;
            delete temp ;
            height-- ;

            return poppedvalue ;
        }
        void getTop(){
            cout << "Top : " << top->value << endl ;
        }

        void getHeight(){
            cout << "height : " << height << endl ;
        }
        void makeEmpty() {
            Node* temp;
            while (top) {
                temp = top;
                top = top->next;
                delete temp;
            }
            height = 0;
        }
        ~Stack() {
            Node* temp = top;
            while (top) {
                top = top->next;
                delete temp;
                temp = top;
            }
        }
        
};

int main(){
    Stack* myStack = new Stack(5) ;
    myStack->push(6) ;
    myStack->pop() ;
    myStack->pop() ;
    myStack->printstack() ;
    myStack->getHeight() ;
    myStack->getTop() ;
    delete myStack ;
    return 0 ;
}