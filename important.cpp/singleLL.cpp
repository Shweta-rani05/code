#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
    private:
    Node* head;

    public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteNode(int val) {
        if (head == nullptr) return;

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->data != val) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) return;

        previous->next = current->next;
        delete current;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList sll;

    sll.insertAtEnd(10);
    sll.insertAtEnd(20);
    sll.insertAtEnd(30);

    cout << "Linked list: ";
    sll.printList();

    sll.deleteNode(20);
    cout << "After deleting 20, linked list: ";
    sll.printList();

    return 0;
}
