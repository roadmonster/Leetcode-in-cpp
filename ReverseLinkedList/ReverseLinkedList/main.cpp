//
//  main.cpp
//  ReverseLinkedList
//
//  Created by HAO LI on 4/7/21.
//

#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

struct LinkedList{
    struct Node* head;
    LinkedList(){
        head = NULL;
    }
    
    void push(int data){
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    
    void print(){
        Node* curr = head;
        while(curr){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    
    void reverseList(){
        Node* prev = NULL, *curr = head, *nextNode = NULL;
        while (curr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;
        
        
        
    }
};



int main(int argc, const char * argv[]) {
    LinkedList ll;
    ll.push(20);
    ll.push(21);
    ll.push(4);
    ll.push(15);
    ll.push(85);
    
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverseList();
 
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}
