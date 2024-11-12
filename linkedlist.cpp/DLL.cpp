#include<iostream>
using namespace std ;
class node{
    public :
        int value ;
        node* next ;
        node* prev ;
        node(int value){
            this->value = value ;
            next = nullptr ;
            prev = nullptr ;
        }
};

class DoubleLinkedList{
    private:
        node* head ;
        node* tail ;
        int length ;
    public :
        DoubleLinkedList(int value){
            node* newnode = new node(value) ;
            head = newnode ;
            tail = newnode ;
            length = 1 ;
        }
        void printlist(){
            node* temp = head ;
            while(temp){
                cout << temp->value << endl ;
                temp = temp->next ;
            }
        }
        void append(int value){
            node* newnode = new node(value) ;
            if(!head){
                head = newnode ;
                tail = newnode ;
            }
            else{
                tail->next = newnode ;
                newnode->prev = tail ;
                tail = newnode ;
            }
            length++ ;
        }
        void deleteLast(){
            if(length == 0){
                return ;
            }
            node* temp = tail ;
            if(length == 1){
                head = nullptr ;
                tail = nullptr ;
            }
            else{
                tail = tail->prev ;
                tail->next = nullptr ;
            }
            delete temp ;
            length-- ;
        }
        void prepend(int value){
            node* newnode = new node(value) ;
            if(length == 0){
                head = newnode ;
                tail = newnode ;
            }
            else{
                newnode->next = head ;
                head->prev = newnode ;
                head = newnode ;
            }
            length++ ;
        }
        void deletefirst(){
            if(length == 0){
                return ;
            }
            node* temp = head ;
            if(length == 1){
                head = nullptr ;
                tail = nullptr ;
            }
            else{
                head = head->next ;
                head->prev = nullptr ;
            }
            delete temp ;
            length-- ;
        }
        node* get(int index){
            if(index < 0 || index >= length) return nullptr ;
            node* temp = head ;
            if(index < length/2){
                for (int i = 0 ; i < index ; i++ ){
                    temp = temp->next ;
                }
                return temp ;
            }
            else{
                temp = tail ;
                for ( int i = length-1 ; i>index ; i--){
                    temp = temp->prev ;
                }
                return temp ;
            }

        }
        bool set(int index, int value){
            node* temp = get(index) ;
            if(temp){
                temp->value = value ;
                return true ;
            }
            return false ;
        }
        bool insert(int index, int value){
            if( index < 0 || index > length ){
                return false;
            }
            if(index == 0){
                prepend(value) ;
                return true ;
            }
            if(index == length){
                append(value) ;
                return true ;
            }
            node* newnode = new node(value) ;
            node* pre = get(index-1) ;
            pre->next->prev = newnode ;
            newnode->next = pre->next ;
            pre->next = newnode ;
            newnode->prev = pre ;
            length++ ;
            return true ;
        }
        void deleteNode(int index){
            if(index < 0 || index >= length) return ;
            if(index == 0){
                return deletefirst() ;
            }
            if(index == length-1){
                return deleteLast() ;
            }
            node* pre = get(index-1) ;
            node* temp = pre->next ;
            pre->next = temp->next ;
            temp->next->prev = pre ;
            delete temp ;
            length-- ;
        }
        void swapPairs(){
            if(length <= 1){
                return ;
            }
            node* dummy = new node(0) ;
            dummy->next = head ;
            head->prev = dummy ;
            head = dummy ;
            node* pre = dummy ;
            while (pre->next) {
                node* temp = pre->next->next ;
                if(!temp){
                    pre->next->prev = pre ;
                }
                pre->next->next = temp->next ;
                pre->next->prev = temp ;
                temp->next = pre->next ;
                temp->prev = pre ;
                pre->next = temp ;
                pre = temp->next ;
            }
            head = head->next ;
        }
        void gethead(){
            cout << "Head : " << head->value << endl ;
        }
        void gettail(){
            cout << "Tail : " << tail->value << endl ;
        }
        void getlength(){
            cout << "length : " << length << endl ;
        }
        //~DoubleLinkedList(){}

};

int main(){
    DoubleLinkedList* myDLL = new DoubleLinkedList(1) ;
    myDLL->swapPairs() ;
    myDLL->printlist() ;
    return 0 ;
}