#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class LinkedList{
private:
    Node *head,*tail;
public:
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    LinkedList(int n){
        head=NULL;
        tail=NULL;
        cout<<"Enter "<<n<<" data:- \n";
        int num;
        Node *newNode;
        for(int i=0;i<n;i++){
            cin>>num;
            newNode=new Node;
            newNode->data=num;
            newNode->next=NULL;
            if(head==NULL){
                head=tail=newNode;
            }
            else{
                tail->next=newNode;
                tail=newNode;
            }
        }
    }
    void displayList(void);
    void lengthOfList(void);
    void insertAtFront(void);
    void insertAtEnd(void);
    ~LinkedList();
};

void LinkedList::displayList(void){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void LinkedList::lengthOfList(void){
    Node *temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    cout<<"Length of list is:- "<<cnt<<endl;
}

LinkedList::~LinkedList(){
    Node *temp=head;
    while(head!=NULL){
        head=head->next;
        delete temp;
        temp=head;
    }
    cout<<"Destructor is called"<<endl;
}

int main(){
    LinkedList obj(5);
    obj.displayList();
    obj.lengthOfList();
    return 0;
}
