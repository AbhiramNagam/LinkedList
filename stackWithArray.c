#include "stdio.h"
//int size=5;
int top=-1;
int arr[5];
void push(){
    //size-1
    if(top==5-1)
        printf("========== stack overflow ==========\n");
    else{
        int n;
        printf("Enter the element to be added to the stack : ");
        scanf("%d",&n);
        top++;
        arr[top]=n;
        //printf("top = %d",top);
    }
    printf("\n");
}
void displayStack(){
    if(top==-1)
        printf("There are no elements in the stack ");
    else{
        printf("Elements in the stack are : ");
        for(int i=0;i<=top;i++)
            printf("%d ",arr[i]);
    }
    printf("\n");
}
void pop(){
    if(top==-1)
        printf("========== Stack underflow ==========\n");
    else{
        printf("Popped element is : %d",arr[top]);
        top--;
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
            displayStack();
        else if(choice==4)
            break;
        else
            printf("Enter a valid input");
        printf("-------------------------------\n");
    }
}

