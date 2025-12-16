#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1,Node* next1, Node* back1){
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
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
//Brute Force Method
Node* reverseDLLBrute(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
//Optimal Method
Node* reverseDLLOptimal(Node*head){
    Node* temp = NULL;
    Node* current = head;
    while(current!=NULL){
        temp = current->back;
        current->back = current->next;
        current->next = temp;

        current = current->back;
    }
    return temp->back;
}
int main(){
    Node* head = new Node(6);
    head->next = new Node(4);
    head->next->next = new Node(12);
    Node* rev = reverseDLLBrute(head);
    print(rev);
}