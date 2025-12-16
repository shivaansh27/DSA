#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* converArrToLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
//Brute force
void middleBrute(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=nullptr){
        count++;
        temp = temp->next;
    }
    int middle = (count/2) + 1;
    temp = head;
    while(temp!=nullptr){
        middle--;
        if(middle==0){
            break;
        }
    temp = temp->next;
    }
    cout<<temp->data; 
}
//Optimal
Node* middleOptimal(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main(){
     vector<int> arr = {4,6,1,24};
     Node* head = converArrToLL(arr);
}