#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head=NULL,*tail=NULL;

int getLength(){
    if(head==NULL)//For empty linked list
        return -1;
    struct Node *temp=head;
    int cnt=0;
    do{
        cnt++;
        temp=temp->next;
    }while(temp!=head);
    return cnt;
}

void insertAtEnd(int x){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        tail=head;
    }
    else{
        newNode->next=tail->next;
        tail->next=newNode;
        tail=newNode;
    }
}

void insertAtFront(int x){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        tail=head;
        return;
    }
    newNode->next=head;
    struct Node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    head=newNode;
}

void insertAt(int x,int ind){
    if(ind<1 || ind>getLength()+1){
        printf("Invalid Index\n");
        return;
    }
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        tail=head;
        return;
    }
    if(ind==1){
        newNode->next=head;
        struct Node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        head=newNode;
    }
    else{
        struct Node *temp=head,*after=NULL;
        int k=ind-2;
        while(k--){
            temp=temp->next;
        }
        after=temp->next;
        temp->next=newNode;
        newNode->next=after;
        if(ind==getLength()+1)
            tail=newNode;
    }
}

void display(){
    struct Node *temp=head;
    if(temp==NULL){
        printf("Empty Linked List\n");
        return;
    }
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}

void displayRecur(struct Node *temp){
    static int pos=0;/*If we use simple variable then at each calling time the pos
    value will become 0 due to which the base condition will never terminates*/
    if(temp!=head || pos==0){
        pos=1;
        printf("%d ",temp->data);
        displayRecur(temp->next);
    }
    pos=0;/*For another use of this function,if not done then value of
    pos always remains 1 and base condition will never be satisfied again*/
}

void deleteNode(int ind){
    if(ind==1){
        struct Node *temp=head,*cont=head;
        int x=head->data;
        while(temp->next!=head)
            temp=temp->next;
        if(temp==head){
            free(head);
            head=NULL;
            printf("%d is deleted successfully\n",x);
            return;
        }
        head=head->next;
        temp->next=head;
        free(cont);
        printf("%d is deleted successfully\n",x);
    }
    else{
        struct Node *temp=head,*prev=NULL;
        int ctr=1;
        while(temp){
            if(ctr==ind)
                break;
            ctr++;
            prev=temp;
            temp=temp->next;
        }
        int x=temp->data;
        prev->next=temp->next;
        free(temp);
        if(ind==getLength())
            tail=prev;
        printf("%d is deleted successfully\n",x);
    }
}


int main(){
    printf("Enter elements for Linked List:- \n");
    for(int i=0;i<5;i++){
        int num;
        scanf("%d",&num);
        insertAtEnd(num);
    }
    printf("Linked List Elements:-\n");
    displayRecur(head);
    printf("\n");
    deleteNode(3);
    printf("Linked List Elements:-\n");
    display();
    return 0;
}
