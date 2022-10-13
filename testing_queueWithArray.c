#include "stdio.h"
#define arr_size 5

int arr[arr_size];
int front=-1;
int rear=-1;

void printQueue(){
    if(rear==-1){
        printf("Queue is empty");
        return;
    }
    for(int i=front;i<rear;i++){
        printf("%d ",arr[i]);
    }
}
void enqueue(int n){
    if(rear==arr_size-1){
        printf("Overflow\n");
        return;
    }
    else{
        if(front==-1){
            front++;
        }
        rear+=1;
        arr[rear]=n;
    }
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printQueue();
    return 0;
}
