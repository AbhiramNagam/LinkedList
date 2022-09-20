#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node *next;
};

struct node*head=NULL,*tail=NULL;

void searchInList(int value){
    struct node *p=head;
    if(p==NULL){
        printf("There are no elements in the linked list.");
        return;
    }
    printf("Found at indices : ");
    int i=0,count=0;
    while (p!=NULL){
        if(p->data==value){
            printf("%d ",i);
            count++;
        }
        p=p->next;
        i+=1;
    }
    if(count!=0)
        return;
    else
        printf("Element not found in the list");
    
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
    int value;
    printf("Enter a number to find its location : ");
    scanf("%d",&value);
    searchInList(value);
    
    return 0;
}
