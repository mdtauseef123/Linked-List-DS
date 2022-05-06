#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL,*tail=NULL,*head2=NULL,*tail2=NULL,*head3=NULL;

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

void insertAtEnd2(int val){
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=val;
    temp->next=NULL;
    if(head2==NULL){
        head2=temp;
        tail2=temp;
    }
    else{
        tail2->next=temp;
        tail2=temp;
    }
}

void insertAtFront(int val){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=head;
    head=newNode;
}


void display(struct Node *p){
    struct Node *temp=p;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}



void displayRecur(struct Node *temp){
    if(temp!=NULL){
        printf("%d ",temp->data);
        displayRecur(temp->next);
    }
    return;//Coming out from the function
}

int length(struct Node *temp){
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}

int lengthRecur(struct Node *temp){
    if(temp!=NULL){
        return (1+lengthRecur(temp->next));
    }
    return 0;
}

int sumListRecur(struct Node *temp){
    if(temp!=0)
        return (temp->data+sumListRecur(temp->next));
    return 0;
}

int findMax(struct Node *temp){
    int bno=temp->data;
    while(temp!=NULL){
        if(temp->data>bno)
            bno=temp->data;
        temp=temp->next;
    }
    return bno;
}

int findMaxRecur(struct Node *temp){
    if(temp==NULL)
        return -1;
    int call=findMaxRecur(temp->next);
    if(call>temp->data)
        return call;
    else
        return temp->data;
}

int findMin(struct Node *temp){
    int sno=temp->data;
    while(temp!=NULL){
        if(temp->data<sno)
            sno=temp->data;
        temp=temp->next;
    }
    return sno;
}
int findMinRecur(struct Node *temp){
    if(temp==NULL)
        return 1000;
    int call=findMinRecur(temp->next);
    if(call<temp->data)
        return call;
    else
        return temp->data;
}

int linearSearch(struct Node *temp,int sno){
    struct Node *prev=NULL;
    while(temp!=NULL){
        if(temp->data==sno){
            if(prev!=NULL){
                prev->next=temp->next;
                temp->next=head;
                head=temp;
            }
            return 1;
        }
        prev=temp;
        temp=temp->next;
    }
    return 0;
}


int linearSearchRecur(struct Node *temp,int sno){
    if(temp==NULL)
        return -1;
    if(temp->data==sno)
        return 1;
    return linearSearchRecur(temp->next,sno);
}

void insertAt(int val,int pos){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if(pos==1){
        newNode->next=head;
        head=newNode;
    }
    else{
        struct Node *temp=head;
        int k=pos-2;
        while(k-- && temp->next!=NULL){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        if(pos>=length(head)+1)
            tail=newNode;
    }
}

void insertInSorted(int x){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    struct Node *temp=head,*prev=NULL;
    while(temp){
        if(temp->data>x)
            break;
        prev=temp;
        temp=temp->next;
    }
    if(prev!=NULL && temp!=NULL){//For all nodes except first and last node
     prev->next=newNode;
     newNode->next=temp;
    }
    else if(prev==NULL){//For first node maintaining head pointer
        newNode->next=head;
        head=newNode;
    }
    else if(temp==NULL){//For last node maintaining tail pointer
        prev->next=newNode;
        newNode->next=temp;
        tail=newNode;
    }
}
void deleteNode(int pos){
    if(pos==1){
        struct Node *temp=head;
        head=head->next;
        int x=temp->data;
        free(temp);
        printf("%d is deleted successfully\n",x);
        return;
    }
    struct Node *temp=head,*prev=NULL;
    int ctr=1;
    while(temp){
        if(ctr==pos)
            break;
        ctr++;
        prev=temp;
        temp=temp->next;
    }
    int x=temp->data;
    prev->next=temp->next;
    free(temp);
    printf("%d is deleted successfully\n",x);
}

int isSorted(){
    struct Node *temp=head;
    int val=-65536;
    while(temp!=NULL){
        if(temp->data<val)
            return 0;
        val=temp->data;
        temp=temp->next;
    }
    return 1;
}

void reverseList(struct Node *temp,struct Node *prev){
    if(temp!=NULL){
        reverseList(temp->next,temp);
        temp->next=prev;
    }
    else
        head=prev;
}

void conacatenateList(struct Node *head1,struct Node *head2){
    struct Node *temp=head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    head2=NULL;
}

void mergeList(struct Node *p,struct Node *q){
    struct Node *last=NULL;
    if(p->data<q->data){
        head3=last=p;
        p=p->next;
        last->next=NULL;
    }
    else if(p->data>q->data){
        head3=last=q;
        q=q->next;
        last->next=NULL;
    }
    while(p!=NULL && q!=NULL){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL)
        last->next=p;
    if(q!=NULL)
        last->next=q;
}

int main(){
    printf("Enter values for first linked list:- \n");
    int arr[5]={1,3,5,7,9};
    int brr[5]={2,4,6,8,10};
    for(int i=0;i<5;i++){
        insertAtEnd(arr[i]);
    }
    printf("Enter values for second linked list:- \n");
    for(int i=0;i<5;i++){
//        int num;
//        scanf("%d",&num);
        insertAtEnd2(brr[i]);
    }
    display(head);
    display(head2);
    //conacatenateList(head,head2);
    mergeList(head,head2);
    printf("Merged List:- \n");
    display(head3);
    display(head2);
//    reverseList(head,NULL);
//    display();
//    printf("Number of Nodes:- %d\n",lengthRecur(head));
//    printf("Sum of list is:- %d\n",sumListRecur(head));
//    printf("Maximum element of list is:- %d\n",findMaxRecur(head));
//    printf("Minimum element of list is:- %d\n",findMin(head));
//    //printf("Found:- %d\n",linearSearch(head,4));
//    insertAt(54,8);
//    insertAt(25,2);
//    display();
//    printf("Found:- %d\n",tail->data);


    return 0;
}
