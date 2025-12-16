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
//detect loop
bool detectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
//find starting point of loop
Node* detectStartingLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
//find length of loop
int lengthLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            fast = fast->next;
            int count = 1;
            while(slow!=fast){
                count++;
                fast = fast->next;
            }
            return count;
        }
    }
    return 0;
}
void print(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
     vector<int> arr = {4,6,1,24};
     Node* head = converArrToLL(arr);
}