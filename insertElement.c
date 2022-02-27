#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL,*tail=NULL;

void insertAtEnd(int val){
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=val;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}

void insertAtFront(int val){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=head;
    head=newNode;
}

