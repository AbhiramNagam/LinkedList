#include "stdio.h"
#include "stdlib.h"

void addNode(int);
void printList();
void inserAtEnd(int);
void insertAtIndex(int,int);
void insertAtBeginning(int);
int countOfElements();

struct node{
    int data;
    struct node *next;
};

struct node*head=NULL,*tail=NULL;

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

void printList(){
    printf("------------------------------------------------\n");
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

void inserAtEnd(int value){
    addNode(value);
}

void insertAtBeginning(int value){
    struct node *p=(struct node*) malloc(sizeof(struct node));
    p->data=value;
    p->next=head;
    head=p;
}
void insertAtIndex(int value,int index){
    struct node *p=head;
    struct node *new_node=(struct node*) malloc(sizeof(struct node));
    if((index+1)>countOfElements()){
        printf("Enter a valid position \n ");
        return;
    }
    else if(index==0){
        new_node->data=value;
        new_node->next=head;
        head=new_node;
        return;
    }
    
    int i=0;
    while (i!=index-1){
        p=p->next;
        i++;
    }
    
    new_node->next=p->next;
    p->next=new_node;
    new_node->data=value;
    
    printf("\n");
}
int countOfElements(){
    struct node *p=head;
    int count=0;
    while (p!=NULL){
        count++;
        p=p->next;
    }
    return count;
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
    
    int insert_num,position;
    int choice;
    printf("------------------------------------------------\n");
    printf("1: To Add Element at the beginning of the list\n");
    printf("2: To Add Element at an index in the list\n");
    printf("3: To Add Element at the end of the lits\n");
    printf("------------------------------------------------\n");
    
    printf("Enter your choice : ");
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter the element to add to the list : ");
        scanf("%d",&insert_num);
        insertAtBeginning(insert_num);
    }
    else if(choice==2){
        printf("Enter the element and position to insert element : ");
        scanf("%d %d",&insert_num,&position);
        insertAtIndex(insert_num,position-1);
    }
    else if(choice==3){
        printf("Enter the element to add to the list : ");
        scanf("%d",&insert_num);
        inserAtEnd(insert_num);
    }

    printList();
    
    return 0;
} 
