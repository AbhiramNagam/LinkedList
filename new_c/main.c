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

void deleteIndex(int index){
    struct node *p=head,*t;
    if(index==0){
        head=head->next;
        free(p);
        
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        struct node *del=p->next;
        p->next=p->next->next;
        free(del);
    }
    
}


//Function Only deletes the first occurence.
int deleteFromList(int n,int deleteMultiple){
    int is_deleted=0;
    struct node *p=head;
    while (p!=NULL){
        if(p->data==n){
            head=p->next;
            free(p);                
            is_deleted=1;
            if(deleteMultiple==0)
                break;
            
        }
        else if(p->next->data==n){
            struct node *del=p->next;
            p->next=p->next->next;
            free(del);
            is_deleted=1;
            if(deleteMultiple==0)
                break;
        }
        p=p->next;
    }
    return is_deleted;
    
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
    printf("Where do u want to delete the node ? \n");
    printf("Enter 1: To Delete node at the beginning  \n");
    printf("Enter 2: To Delete node at the end \n");
    printf("Enter 3 : To Delte node at the middle \n");
	printf("Enter 4 : To Delete node at a position \n");
	int indexToDelete;
    scanf("%d",&indexToDelete);
    if(indexToDelete==1)
    	deleteIndex(0);
    else if(indexToDelete==2)
    	deleteIndex(n-1);
    else if(indexToDelete==3)
    	deleteIndex(n/2);
    else if(indexToDelete==4){
    	int posToDelete;
		printf("Enter the positon to delete : ");
    	scanf("%d",&posToDelete);
    	deleteIndex(posToDelete-1);
	}
	else{
		printf("Invalid input.");
	}
    
//    int is_deleted;
//    int deleteNumber;
//    printf("Enter the number to be deleted from the list : ");
//    scanf("%d",&deleteNumber);
//    is_deleted=deleteFromList(deleteNumber,0);
//    if(is_deleted==1)
//        printf("Element deleted from the list.\n");
//    else
//        printf("Element is not found in the list.\n");
//    
    printList();
    
    return 0;
}   
