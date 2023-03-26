#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node*prev;
    Node*next;
    
    //constructor -> used to assign data to new node
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    
    //destructor -> used to delete a node
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory got emptied for node with data : "<<val<<endl;
    }
};

void print(Node* &tail){
    
    if(tail == NULL){
        cout<<"now list is empty "<<endl;
        return;
    }
    Node* ptr = tail;
    do{
        cout<<tail->data << " ";
        tail = tail->next;
    }while(tail != ptr);
    cout<<endl;
}

void insertNode(Node* &tail,int element, int data){
    //empty list
    if(tail == NULL){
        Node*ptr = new Node(data);
        tail = ptr;
        ptr->next = ptr;
    }else{
        //non-empty list 
        Node * curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        
        Node*ptr = new Node(data);
        ptr -> next = curr->next;
        curr -> next = ptr;
        
        
    }
}

void deleteNode(Node* &tail,int value){
    //empty list
    if(tail == NULL){
        cout<<"list is empty"<<endl;
        return;
    }else{
        Node*prev = tail;
        Node*curr = prev->next;
        
        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }
        
        prev -> next = curr -> next;
        // 1 node list 
        if(curr == prev){
            tail = NULL;
        }
        //>=2 Node list 
        if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

int main()
{
    Node* tail = NULL;
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,5);
    print(tail);
    insertNode(tail,5,7);
    print(tail);
    insertNode(tail,7,9);
    print(tail);
    insertNode(tail,5,6);
    print(tail);
    insertNode(tail,6,100);
    print(tail);
    insertNode(tail,9,200);
    print(tail);
    insertNode(tail,100,300);
    print(tail);
    
    deleteNode(tail,100);
    print(tail);
    deleteNode(tail,200);
    print(tail);
    deleteNode(tail,300);
    print(tail);
    deleteNode(tail,3);
    print(tail);
    deleteNode(tail,5);
    print(tail);
    deleteNode(tail,6);
    print(tail);
    deleteNode(tail,7);
    print(tail);
    deleteNode(tail,9);
    print(tail);
    
    return 0;
}
