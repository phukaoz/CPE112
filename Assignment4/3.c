#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int valid(char c){
    return c == '{' || c == '}' || c == '(' || c == ')' || c == '[' || c == ']';
}

int main(void){
    char stk[1000];
    int size = 0;
    char s[1001];
    scanf("%s",s);
    int n = strlen(s);
    for(int i=0;i<n;i++){
        if(!valid(s[i])){
            continue;
        }
        if(!size){
            stk[size] = s[i];
            size++;
        }else{
            if(s[i] - stk[size-1] > 2 || s[i] - stk[size-1] < 1){
                stk[size] = s[i];
                size++;
            }else{
                size--;
            }
        }
    }
    printf(size == 0 ? "The string is balanced" : "The string is not balanced");
}