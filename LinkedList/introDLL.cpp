#include<bits/stdc++.h>
using namespace std;
//Initializtion of DLL
class Node{
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1,Node* next1, Node* back1 ){
        data = data1;
        next = next1; 
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
//Conversion of Array to LL
Node* converArrToLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,mover);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}
//Deletion of head in LL
Node* deleteHead(Node* head){
    if(head == NULL || head->next == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    head -> back = nullptr;
    delete temp;
    return head;
};
//Deletion of tail in LL
Node* deleteTail(Node* head){
    if(head == NULL || head->next == nullptr){
        return nullptr;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;

}
//Deletion of Kth element in DLL
Node* deleteK(Node*head, int k){
    if(head == NULL) return NULL;   
    int count = 0;
    Node* temp = head;
    while(temp != NULL && count<k){
        count++;
        if(count == k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if(prev == NULL && front == NULL){
        return NULL;
    }
    else if(prev == NULL){
        return deleteHead(head);
    }
    else if(front == NULL){
        return deleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}
//Deletion of Node in DLL
void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front == NULL){
        prev->next = NULL;
        temp->back = NULL;
        delete temp;
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = NULL;
    delete temp;
}
//Insertion before head in DLL
Node* insertHead(Node* head,int k){
    Node* newNo = new Node(k,head,nullptr);
    head->back = newNo;
    return newNo;
}
//Insertion before tail
Node* insertionTail(Node*head, int k){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        Node* newNo = new Node(k,head,nullptr);
        head->back = newNo;
        return newNo;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNo = new Node(k,temp,prev);
    temp->back = newNo;
    prev->next = newNo;
    return head;
}
//Insertion at K place
Node* insertionK(Node* head, int k,int val){
    if(k==1){
        return insertHead(head,val);
    }
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        if(count == k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
//Insertion before a node
void InsertNode(Node* val, int k){
    Node* prev = val->back;
    Node* newNode = new Node(k,val,prev);
    prev->next = newNode;
    val->back = newNode;
}
//printing DLL
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {4,6,1,24};
    Node* head = converArrToLL(arr);
    Node* head1 = insertionK(head,4,21);
    print(head1);
}