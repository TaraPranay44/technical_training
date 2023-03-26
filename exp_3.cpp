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
        cout<<ptr->data<<" -> ";
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

bool isPalindrome(Node* list){
    string name = "";
    Node*ptr = list;
    while(ptr != NULL){
        name += ptr->data;
        ptr = ptr->next;
    }
    
    int n = name.length();
    int lo = 0;
    int hi = n-1;
    
    while(lo <= hi){
        if(name[lo] != name[hi]) return false;
        lo++;
        hi--;
    }
    return true;
}

int main()
{
    Node* node1 = new Node('A');
    
    Node* head = node1;
    Node* tail = node1;
    
    insertAtTail(tail,'I');
    insertAtTail(tail,'L');
    insertAtTail(tail,'I');
    insertAtTail(tail,'A');
    
    cout<< "name is :  ";
    linkedListTraversal(head);
    
    cout<<endl;
    
    isPalindrome(head) ? cout<<"given name is a PALINDROME" : cout<<"given name is NOT a PALINDROME";
    
    cout<<endl<<endl;
    
    Node* node2 = new Node('P');
    
    Node* head2 = node2;
    Node* tail2 = node2;
    
    insertAtTail(tail2,'R');
    insertAtTail(tail2,'A');
    insertAtTail(tail2,'N');
    insertAtTail(tail2,'A');
    insertAtTail(tail2,'Y');
    
    cout<< "name is :  ";
    linkedListTraversal(head2);
    
    cout<<endl;
    
    isPalindrome(head2) ? cout<<"given name is a PALINDROME" : cout<<"given name is NOT a PALINDROME";
    
    
    

    return 0;
}
