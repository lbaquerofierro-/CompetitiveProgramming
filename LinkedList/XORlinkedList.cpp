#include <iostream>

//Implement memory efficient double linked list
//by using xor of the previous and next nodes as 
//additional field of a node.

using namespace std;

struct Node{
public:
    int data;
    Node *pxorn;
    Node(int v){
        data = v;
        pxorn = nullptr;
    }
};

Node *XOR(Node* prev, Node* next){
    return(Node*)((uintptr_t)(prev)^(uintptr_t)(next));
}

class Dll{
private:
    Node *head = nullptr;
public:
    void insertAfter(int v){
        Node* prev = nullptr, *curr = nullptr, *next = nullptr;
        Node* newNode = new Node(v);
        curr = head;

        if(head == nullptr){
            head = newNode;
            newNode->pxorn = XOR(prev, next);
        }else{
            while(curr->pxorn != prev) {
                next = XOR(prev, curr->pxorn);
                prev = curr;
                curr = next;
            }

            newNode->pxorn = XOR(curr, nullptr);
            curr->pxorn = XOR(prev, newNode); // newNode is "next"
        }
    }

    void print(){
        Node* curr = head;
        Node* prev = nullptr;
        Node *next = nullptr;
        while(curr){
            cout << curr->data << " ";
            next = XOR(prev, curr->pxorn);
            prev = curr;
            curr = next;
        }
    }
};

int main(){
    Dll *list = new Dll;
    list->insertAfter(1);
    list->insertAfter(2);
    list->insertAfter(3);
    list->insertAfter(4);
    list->insertAfter(5);
    list->insertAfter(5);
    list->insertAfter(10);
    list->insertAfter(25);
    list->print();

    return 0;
}


