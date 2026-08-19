#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1) : data(data1), next(nullptr) {}
};

void insertLL(Node* head, int pos, int data){
    Node* temp = head;
    int count = 0;
    Node* newNode = new Node(data);
    while(temp && count<=pos){
        if(count == pos){
            newNode->next = temp;
            temp->next = newNode;
        }
        count++;
        temp=temp->next;
    }
}

void showLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<< temp->data << " -> ";
        temp=temp->next;
    }
    cout<< "NULL" << endl;
}

int main(){
    vector<int> arr = {2,3,4,5};
    Node* y = new Node(arr[2], nullptr);
    Node* x = new Node(arr[3], nullptr);
    y->next=x;
    showLL(y);
    insertLL(y, 1, 8);
    showLL(y);
}