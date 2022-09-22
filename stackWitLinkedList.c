#include "stdio.h"
#include "stdlib.h"
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*tail=NULL,*to_pop=NULL;
void push(){
    struct node *new_node=(struct node*) malloc(sizeof(struct node));
    int n;
    printf("Enter the element to be added to the stack : ");
    scanf("%d",&n);
    new_node->data=n;
    to_pop=tail;
    if(head==NULL){
        head=new_node;
        tail=new_node;
    }
    else{
        tail->next=new_node;
        new_node->next==NULL;
        tail=new_node;
    }
}
void pop(){
    to_pop->next=NULL;
}
void printList(){
    struct node *p=head;
    if(p==NULL){
        printf("There are no elements in the linked list.");
    }
    printf("Elements in the linked list are : ");
    while (p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    int choice;
    while (1==1){
        printf("Choose from the following\n");
        printf("1 : push\n");
        printf("2 : pop\n");
        printf("3 : displayStack\n");
        printf("4 : To Quit\n");
        scanf("%d",&choice);
        if(choice==1)
            push();
        else if(choice==2)
            pop();
        else if(choice==3)
            printList();
        else if(choice==4)
            break;
        else
            printf("Enter a valid input");
        printf("-------------------------------\n");
    }
}
