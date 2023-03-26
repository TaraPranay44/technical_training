#include <iostream>

using namespace std;


class Node{
  public:
  int data;
  Node* next;
  
  
  //constructor
  Node(int data){
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

void insertAtHead(Node* &head,int data){
    Node*ptr = new Node(data);
    ptr->next = head;
    head = ptr;
}
 
void insertAtTail(Node* & tail, int data){
    Node*ptr = new Node(data);
    tail->next = ptr;
    tail = tail->next;
}    

void insertAtPosition(Node* &head,Node* &tail,int position,int data){
    
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

Node* reverse(Node*head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(Node* &head,Node* &tail,int value){
        Node*ptr = new Node(value);
        if(head == NULL){
            head = ptr;
            tail = ptr;
            return;
        }else{
            tail->next = ptr;
            tail = ptr;
        }
    }

    Node* add(Node* &l1, Node* &l2){
        int carry = 0;

        Node* ansHead = NULL;
        Node* ansTail = NULL;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int val1 = 0;
            if(l1 != NULL) val1 = l1->data;
            int val2 = 0;
            if(l2 != NULL) val2 = l2->data;
            
            int sum = carry + val1 +val2;
            
            int digit = sum % 10;
            
            insertAtTail(ansHead,ansTail,digit);
            
            carry = sum/10;
            
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        

        return ansHead;
    }

Node* sumOfLL(Node* l1,Node* l2){
        l1 = reverse(l1);
        l2 = reverse(l2);

        Node* ans = add(l1,l2);
        ans = reverse(ans);
        return ans;
}

Node* sumOfLLwithoutReverse(Node* l1,Node*l2){
        Node* dummy = new Node(-1);
        Node*temp = dummy;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL || carry != 0){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->data;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->data;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            
            Node* newNode = new Node(sum % 10);
            temp -> next = newNode;
            temp = temp->next;
        }
        return dummy->next;
}

int main()
{
    
    Node* node1 = new Node(5);
    
    Node * head1 = node1;
    Node * tail1 = node1;
    
    insertAtTail(tail1,1);
    insertAtTail(tail1,7);
    
    cout<< "first linked list : "; 
    linkedListTraversal(head1);
    
    Node* node2 = new Node(2);
    
    Node* head2 = node2;
    Node* tail2 = node2;
    
    insertAtTail(tail2,9);
    insertAtTail(tail2,5);
    
    cout<< "second linked list : "; 
    linkedListTraversal(head2);
    cout<<endl;
    
    
    Node* ans = sumOfLL(head1,head2);
    // Node* ans = sumOfLLwithoutReverse(head1,head2);
    
    cout<<"Sum of two linked lists: ";
    linkedListTraversal(ans);
   
    
    
    
    
    return 0;
}
