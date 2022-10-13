#include "stdio.h"
#define size 5

int arr[size];
int front=-1;
int rear=-1;

void enqueue(){
    printf("-------------------------------\n");
    int n;
    if(rear==size){
        printf("Overflow!\n");
        return;
    }
    if(front==-1){
        front=0;
        rear=0;
    }
    printf("Enter a number to Enqueue : ");
    scanf("%d",&n);
    arr[rear]=n;
    rear++;
}
void dequeue(){
    if(front==-1){
        printf("-------------------------------\n");
        printf("Underflow\n");
    }
    else if(front==rear){
        printf("-------------------------------\n");
        printf("There are no elements in queue\n");
    }
    else{
        front++;
    }
}
void printQueue(){
    printf("-------------------------------\n");
    printf("Elements in queue are  : ");
    for(int i=front;i<rear;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int choice,n;
    while (1==1){
        printf("Choose from the following\n");
        printf("1 : Enqueue\n");
        printf("2 : Dequeue\n");
        printf("3 : displayQueue\n");
        printf("4 : To Quit\n");
        scanf("%d",&choice);
        if(choice==1){
            enqueue();
        }
        else if(choice==2)
            dequeue();
        else if(choice==3)
            printQueue();
        else if(choice==4)
            break;
        else
            printf("Enter a valid input\n");
        printf("-------------------------------\n");
    }
    return 0;
}
