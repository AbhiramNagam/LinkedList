#include "stdio.h"
#include "stdlib.h"
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;
void addNode(int data){
    struct node *new_node=(struct node*) malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
        tail=new_node;
    }
    else{
        tail->next=new_node;
        tail=new_node;
    }
}

void displayQueue(){
    printf("-------------------------------\n");
    struct node *p=head;
    if(p==NULL){
        printf("There are no elements in the linked list.\n");
        return;
    }
    printf("Elements in the linked list are : \n");
    while (p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void enqueue(int n){
    addNode(n);
}
void dequeue(){
    if(head==NULL)
        printf("Underflow!\n");
    else if(head==tail->next)
        printf("There are no elements in queue\n");
    else
        head=head->next;
}
int main(){
    int choice,n;
    while (1){
        printf("Choose from the following\n");
        printf("1 : Enqueue\n");
        printf("2 : Dequeue\n");
        printf("3 : displayQueue\n");
        printf("4 : To Quit\n");
        scanf("%d",&choice);
        if(choice==1){
            printf("-------------------------------\n");
            printf("Enter the value to enqueue : ");
            scanf("%d",&n);
            enqueue(n);
        }
        else if(choice==2)
            dequeue();
        else if(choice==3)
            displayQueue();
        else if(choice==4)
            break;
        else
            printf("Enter a valid input");
        printf("-------------------------------\n");
    }
}
