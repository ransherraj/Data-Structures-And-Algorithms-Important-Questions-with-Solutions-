#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* next;
};

node* newnode(int key){
    node* temp = new node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void reversenode(node **head){
    node *cur = (*head);
    node *pre = NULL;
    node *nxt;
    
    while(cur!=NULL){
        nxt= cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;  
    } 
    *(head) = pre;
}

void printnode(node* head){
    
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}


int main() {
    
    node* head = newnode(1);
    head->next = newnode(6);
    head->next->next = newnode(8);
    head->next->next->next = newnode(7);
    head->next->next->next->next = newnode(7);
    reversenode(&head);
    printnode(head);
    return 0;
}
