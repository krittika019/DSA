#include<iostream>
#include<unordered_set>
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

class linkedList{
    private :
        Node* head ;
        Node* tail ;
        int length ;
    public :
        linkedList(int value){
            Node* newnode = new Node(value) ;
            head = newnode ;
            tail = newnode ;
            length = 1 ;
        }
        void printList(){
            Node* temp = head ;
            while(temp){
                cout << temp->value << endl ;
                temp = temp->next ;
            }
        }
        void append(int value){
            Node* newnode = new Node(value) ;
            if(head == nullptr){
                head = newnode ;
                tail = newnode ;
            }
            else{
                tail->next = newnode ;
                tail = newnode ;
            }
            length++ ;
        }
        void deleteLast(){
            if(head == nullptr){
                return ;
            }
            Node* temp = head ;
            if(head->next == nullptr){
                head = nullptr ;
                tail = nullptr ;
            }
            else{
                Node* prev = temp ;
                while(temp->next){
                    prev = temp ;
                    temp = temp->next ;
                }
                tail = prev ;
                tail->next = nullptr ;
            }
            delete temp ;
            length-- ;
        }
        void deleteFirst(){
            if(head == nullptr){
                return ;
            }
            Node* temp = head ;
            if(head->next == nullptr){
                head = nullptr ;
                tail = nullptr ;
            }
            else{
                head = head->next ;
            }
            delete temp ;
            length-- ;
        }
        void prepend(int value){
            Node* newnode = new Node(value) ;
            if(head == nullptr){
                head = newnode ;
                tail = newnode ;
            }
            else{
                newnode->next = head ;
                head = newnode ;
            }
            length++ ;
        }
        Node* get(int index){
            if( index<0 || index>=length){
                return nullptr ;
            }
            Node* temp = head ;
            for(int i = 0 ; i < index ; i++){
                temp = temp->next ;
            }
            return temp ;
        }
        bool set(int index, int value){
            Node* temp = get(index) ;
            if(temp != nullptr){
                temp->value = value ;
                return true ;
            }
            return false ;

        }
        bool insert(int index, int value){
            if(index < 0 || index > length ){
                return false ;
            }
            if(index == 0){
                prepend(value) ;
                return true ;
            }
            if(index == length){
                append(value) ;
                return true ;
            }
            Node* newnode = new Node(value) ;
            Node* prev = get(index-1) ;
            Node* temp = prev->next ;
            prev->next = newnode ;
            newnode->next = temp ;
            length++ ;
            return true ;
        }
        void deleteNode(int index){
            if(index < 0 || index >= length){
                return ;
            }
            if(index == 0){
                return deleteFirst() ;
            }
            if(index == length-1){
                return deleteLast() ;
            }
            Node* prev = get(index-1) ;
            prev->next = prev->next->next ;

        }
        void reverse(){
            if(head == nullptr || head->next == nullptr){
                return ;
            }
            Node* before = nullptr ;
            Node* temp = head ;
            Node* after = temp ;
            head = tail ;
            tail = temp ;
            while(temp){
                after = after->next ;
                temp->next = before ;
                before = temp ;
                temp = after ;
            }
        }
        void deleteDuplicates() {
            Node* dummy = new Node(0) ;
            dummy->next = head ;
            Node* prev = dummy ;
            Node* slow = head ;
            Node* fast = slow->next ;
            while(fast){
                if(slow->value == fast->value){
                    if(slow->value != fast->next->value){
                        prev->next = fast->next ;
                        slow = prev->next ;
                        fast = slow->next ;
                    }
                    else{
                        fast = fast->next ;
                    }
                }
                else{
                    prev = slow ;
                    slow = fast ;
                    fast = fast->next ;
                }
            }
            head = dummy->next ;
        }
        void gethead(){
            cout << "Head : " << head->value << endl ;
        }
        void gettail(){
            cout << "Tail : " << tail->value << endl ;
        }
        void getlength(){
            cout << "Length : " << length << endl ;
        }
};

int main(){
    linkedList* myLL = new linkedList(1) ;
    myLL->append(1) ;
    myLL->append(1) ;
    myLL->append(2) ;
    myLL->append(3) ;
    myLL->deleteDuplicates() ;
    myLL->printList() ;
    myLL->gethead() ;
    myLL->gettail() ;
    return 0 ;
}

