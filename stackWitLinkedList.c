#include "stdio.h"
#include "stdlib.h"
struct node{
    int data;
    struct node  *next;
};
struct node *head=NULL,*tail=NULL;
void push(){
    struct node *p=(struct node*) malloc(sizeof(struct node));
    
    int n;
    printf("Enter the element to be added to the stack : ");
    scanf("%d",&n);
    p->data=n;
    if(head==NULL){
        p->next=NULL;
        tail=p;
        head=p;
    }
    else{
        p->next=head;
        head=p;
    }
}
void pop(){
    if(head==NULL){
        printf("########## Stack Underflow ##########");
    }
    struct node *del=(struct node*) malloc(sizeof(struct node));
    del=head;
    head=head->next;
    //head->next=NULL;
    free(del);
}
void printList(){
    printf("Elements in the stack are : ");
    struct node *p=head;
    while(p!=NULL){
        printf("%d-->",p->data);
        p=p->next;
        if(p==NULL)
            printf("NULL");
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
