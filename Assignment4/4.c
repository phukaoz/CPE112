/*
    Tanapat Namsomboon
    66070501022
*/
#include <stdio.h>
#include <string.h>

char stack[1001];
int size = 0;

void push(char val){
    stack[size++] = val;
}
void pop(){
    size--;
}
char top(){
    return stack[size-1];
}
int prio(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int main(void){
    char s[1001];
    scanf("%s",s);
    char t[1001];
    int len = 0;
    int n = strlen(s);
    for(int i=0;i<n;i++){
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            t[len++] = s[i];
        }else if (s[i] == '(') {
            push(s[i]);
        }else if(s[i] == ')'){
            while(size > 0 && top() != '('){
                t[len++] = top();
                pop();
            }
            pop();
        }else{
            while(size > 0 && prio(s[i]) < prio(top()) || prio(s[i]) == prio(top()) && s[i] != '^'){
                t[len++] = top();
                pop();
            }
            push(s[i]);
        }
    }
    while(size >= 0){
        t[len++] = top();
        pop();
    }
    t[len] = '\0';
    printf("%s",t);
}