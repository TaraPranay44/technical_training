#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node{
  public:
  char data;
  Node* next;
  
  
  //constructor
  Node(char data){
      this->data = data;
      this->next = NULL;
  }
  
  //destructor
  ~Node(){
      int value = this->data;
      //free memory
      if(this->next !=NULL){
          delete next;
          this->next = NULL;
      }
      cout<< " memor is free for node woth value "<<data<<endl;
  }
  
};


void linkedListTraversal(Node* &head){
    Node*ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<"-> ";
        ptr = ptr->next;
    }cout<<"NULL";
    cout<<endl;
}

void insertAtHead(Node* &head,char data){
    Node*ptr = new Node(data);
    ptr->next = head;
    head = ptr;
}
 
void insertAtTail(Node* & tail, char data){
    Node*ptr = new Node(data);
    tail->next = ptr;
    tail = tail->next;
}    

void insertAtPosition(Node* &head,Node* &tail,int position,char data){
    
    if(position == 1){
        insertAtHead(head,data);
        return;
    }
    
    Node*ptr = head;
    int cnt = 1;
    while(cnt < position - 1){
        ptr = ptr->next;
        cnt++;
    }
    
    if(ptr->next == NULL){
        insertAtTail(tail,data);
        return;
    }
    
    Node* nodeToinsert = new Node(data);
    nodeToinsert->next = ptr->next;
    ptr->next = nodeToinsert;
}



void deleteNode(Node* &head,Node* &tail, int position){
    //delete head
    if(position == 1){
        Node*ptr = head;
        head = head->next;
        ptr->next = NULL;
        //free memory
        delete ptr;
    }else{
        //delete at tail or any other position 
        Node* prev = NULL;
        Node* curr = head;
        
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        if(curr->next == NULL){
            prev->next = NULL;
            tail = prev;
            curr->next = NULL;
            delete curr;
            
            return;
        }
        
        prev -> next = curr -> next;
        curr->next = NULL;
        delete curr;
    }
}

bool isfound(Node* list,char ch){
    Node* curr = list;
    
    while(curr != NULL){
        if(curr->data == ch){
            return true;
        }
        curr = curr->next;
    }
    return false;
    
}

int main()
{
    Node* node1 = new Node('T');
    
    Node* head = node1;
    Node* tail = node1;
    
    insertAtTail(tail,'a');
    insertAtTail(tail,'r');
    insertAtTail(tail,'a');
    insertAtTail(tail,' ');
    insertAtTail(tail,'p');
    insertAtTail(tail,'r');
    insertAtTail(tail,'a');
    insertAtTail(tail,'n');
    insertAtTail(tail,'a');
    insertAtTail(tail,'y');
    
    cout<< "name is :  ";
    linkedListTraversal(head);
    cout<<endl<<endl;
    
    char ch;
    cout<<"enter any character: "<<" ";
    cin>>ch;
    cout<<endl;
    cout<<"Lets check the name contains character "<<ch<<endl;
    cout<<endl;
    isfound(head,ch)?cout<<"Yes, the character you have entered is present in the list " : cout<<"No, the character you have entered is not present in the list ";
    
    
    
    

    return 0;
}
