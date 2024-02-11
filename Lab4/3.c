/*
    Tanapat Namsomboon
    66070501022
*/
#include <stdio.h>

int cnt = 0;
void rec(int n,char from, char to, char other){
    cnt++;
    if(n==1){
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    rec(n-1, from, other, to);
    printf("Move disk %d from %c to %c\n",n, from, to);
    rec(n-1, other, to, from);
}

int main(void){
    int n;
    scanf("%d",&n);
    rec(n,'A','C','B');
    printf("Total moves: %d",cnt);
}