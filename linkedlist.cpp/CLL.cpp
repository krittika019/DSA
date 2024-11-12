#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Create or add an element to the circular linked list
    void create(int data) {
        Node* newNode = new Node();
        newNode->data = data;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Insert an element at a specified position
    void insert(int data, int position) {
        Node* newNode = new Node();
        newNode->data = data;

        if (position == 1) {
            if (head == nullptr) {
                head = newNode;
                newNode->next = head;
            } else {
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = head;
                head = newNode;
            }
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete a node by its value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            if (head->next == head) {
                head = nullptr;
                delete temp;
                return;
            } else {
                Node* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                head = head->next;
                last->next = head;
                delete temp;
                return;
            }
        }

        Node* temp = head;
        while (temp->next != head && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == head) {
            cout << "Value not found in the list" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // Reverse the circular linked list
    void reverse() {
        if (head == nullptr || head->next == head) return;

        Node *prev = nullptr, *current = head, *next = nullptr, *last = head;
        do {
            last = last->next;
        } while (last->next != head);
        
        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);

        head->next = prev;
        head = prev;
        last->next = head;
    }

    // Concatenate another circular linked list
    void concatenate(CircularLinkedList& list) {
        if (head == nullptr) {
            head = list.head;
            return;
        }
        if (list.head == nullptr) return;

        Node* temp1 = head;
        while (temp1->next != head) {
            temp1 = temp1->next;
        }

        Node* temp2 = list.head;
        while (temp2->next != list.head) {
            temp2 = temp2->next;
        }

        temp1->next = list.head;
        temp2->next = head;
    }

    // Display the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};

int main() {
    CircularLinkedList list1, list2;
    int choice, data, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create (Add to end)\n";
        cout << "2. Insert at position\n";
        cout << "3. Delete by value\n";
        cout << "4. Reverse\n";
        cout << "5. Concatenate another list\n";
        cout << "6. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add: ";
                cin >> data;
                list1.create(data);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> position;
                list1.insert(data, position);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> data;
                list1.deleteNode(data);
                break;
            case 4:
                list1.reverse();
                cout << "List reversed.\n";
                break;
            case 5:
                cout << "Creating another list to concatenate.\n";
                int n;
                cout << "Enter number of elements in the second list: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Enter value: ";
                    cin >> data;
                    list2.create(data);
                }
                list1.concatenate(list2);
                cout << "Lists concatenated.\n";
                break;
            case 6:
                cout << "Current List: ";
                list1.display();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

}