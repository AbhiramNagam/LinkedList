#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node *next;
};

struct node*head=NULL,*tail=NULL;

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

int main(){
    int n,temp_num;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&temp_num);
        addNode(temp_num);
        
    }
    
    printList();
    
    
    
    return 0;
}
