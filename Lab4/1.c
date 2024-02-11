/*
    Tanapat Namsomboon
    66070501022
*/
#include <stdio.h>
#include <stdlib.h>

int size=0;
int cap;
int* stack;

void push(int val){
    if(size == cap){
        printf("Stack Overflow.");
        exit(0);
    }
    stack[size++] = val;
}

void pop(){
    if(size == 0){
        printf("Stack Underflow.");
        exit(0);
    }
    size--;
}

int isEmpty(){
    return size <= 0;
}

void show(){
    if(size == 0){
        printf("Stack is empty.");
        exit(0);
    }
    while(!isEmpty()){
        printf("%d\n",stack[--size]);
    }
}

int main(void){
    scanf("%d",&cap);
    if(cap <= 0){
        printf("Please enter a positive number.");
        return 0;
    }
    stack = (int*)malloc(sizeof(int) * cap);
    while(1){
        int q;
        scanf("%d",&q);
        switch (q)
        {
        case 1:
            int val;
            scanf("%d",&val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            return 0;
        case 4:
            printf("Exiting...");
            return 0;

        default:
            printf("Invalid choice.");
            return 0;
        }
    }
}