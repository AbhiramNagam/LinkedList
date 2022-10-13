#include "stdio.h"
#define size 5
int top=-1;
int arr[size];
void push(){
    printf("-------------------------------\n");
    if(top==size-1)
        printf("========== stack overflow ==========\n");
    else{
        int n;
        printf("Enter the element to be added to the stack : ");
        scanf("%d",&n);
        top++;
        arr[top]=n;
    }
}
void displayStack(){
    printf("-------------------------------\n");
    if(top==-1)
        printf("There are no elements in the stack.");
    else{
        printf("Elements in the stack are : ");
        for(int i=top;i>=0;i--)
            printf("%d-->",arr[i]);
        printf("NULL");
    }
    printf("\n");
}
void pop(){
    printf("-------------------------------\n");
    if(top==-1)
        printf("========== Stack underflow ==========\n");
    else{
        printf("Popped element is : %d",arr[top]);
        top--;
    }
    printf("\n");
}
void print_topElement(){
    printf("-------------------------------\n");
    if(top==-1){
        printf("Stack is empty.\n");
        return;
    }
    printf("Top Element is : %d\n",arr[top]);
}
void status(){
    printf("-------------------------------\n");
    if(top==-1){
        printf("Stack is empty!\n");
    }
    else if(top==size-1)
        printf("Stack is Full!\n");
    else{
        printf("Stack is neither Empty, nor Full.\nStack currently have %d elements.\n",top+1);
    }
}
void displayStackCount(){
    printf("-------------------------------\n");
    printf("Number of Elements in the stack are : %d.\n",top+1);
}
void destroyStack(){
    printf("-------------------------------\n");
    for(int i=0;i<=top;i++){
        arr[i]=0;
    }
    top=-1;
    printf("Stack Destroyed!\n");
}
int main(){
    int choice;
    while (1==1){
        printf("\n 0 - To Quit");
        printf("\n 1 - Push");
        printf("\n 2 - Pop");
        printf("\n 3 - Top");
        printf("\n 4 - Status");
        printf("\n 5 - Display");
        printf("\n 6 - Stack Count");
        printf("\n 7 - Destroy stack");
        printf("\n 8 - Destroy stack and Quit");
        printf("\n");
        scanf("%d",&choice);
        if(choice==0)
            break;
        if(choice==1)
            push();
        else if(choice==2)
            pop();
        else if(choice==3)
            print_topElement();
        else if(choice==4)
            status();
        else if(choice==5)
            displayStack();
        else if(choice==6)
            displayStackCount();
        else if(choice==7)
            destroyStack();
        else if(choice==8){
            destroyStack();
            break;
        }
        else
            printf("Enter a valid input\n");
        printf("-------------------------------\n");
    }
    return 0;
}
