#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;
Node *head = nullptr, *last = nullptr;


Node *createNode(int data) {
    Node *temp = new Node;
    if(temp == NULL) {
        cout<< "Failed to create Node" << endl;
        exit(1);
    }
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

void insertFront(int data) {
    Node *temp = createNode(data);
    if(head == nullptr) {
        head = last = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void insertBack(int data) {
    Node *temp = createNode(data);
    if(head==nullptr) {
        head = last = temp;
    } else {
        last->next = temp;
        last = temp;
    }
}

void insertAt(int position, int data) {
    if(position == 1) {
        insertFront(data);        
    } else {
        Node *temp = head;
        for(int i = 1; i<position-1; i++) {
            if(temp == nullptr) {
                cout<< "Position Out of Bounds!!!" << endl;
                exit(1);
            }
            temp = temp->next;
        }   
    }
}

void removeFront() {
    if(head == nullptr && last == nullptr) {
        cout << "The list is already empty!" << endl;
        exit(1);
    }
    head = nullptr;
}

void removeAt(int position) {

}


int main() {

    return 0;
}