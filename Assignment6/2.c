/*
    ธนภัทร นามสมบูรณ์
    66070501022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000];
char stk[1000][1000];
int top = -1;

int op(char c){
    switch (c) {
        case '+':
        case '-':
        case '/':
        case '*':
            return 1;
    }0
    return 0;
}
void push(char var[]){
    strcpy(stk[++top],var);
}
void pop(){
    top--;
}
int main(){
    scanf("%s",s);
    for(int i=strlen(s)-1;i>=0;i--){
        if(op(s[i])){
            char num1[1000],num2[1000];
            strcpy(num1,stk[top]);
            pop();
            strcpy(num2,stk[top]);
            pop();
            char new[1000] = "";
            strcat(new,num1);
            strcat(new,num2);
            char neww[2];
            neww[1] = '\0';
            neww[0] = s[i];
            strcat(new,neww);
            push(new);
        }else{
            char new[2];
            new[1] = '\0';
            new[0] = s[i];
            push(new);
        }
    }
    printf("%s",stk[top]);
}