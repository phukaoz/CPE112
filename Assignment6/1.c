/*
    ธนภัทร นามสมบูรณ์
    66070501022
*/
#include <stdio.h>
#include <stdlib.h>

int tree[10000];
int n=0;

int sum(int node){
    if(node >= n){
        return 0;
    }
    return sum(node*2 + 1) + sum(node*2 + 2) + tree[node];
}
int check(int node){
    if(node >= n || (node*2+1 >= n && node*2+2 >= n)){
        return 1;
    }
    int lsum = sum(node*2 + 1);
    int rsum = sum(node*2 + 2);
    if((tree[node] == lsum+rsum) && check(node*2+1) && check(node*2+2)){
        return 1;
    }
    return 0;
}

int main(){
    while(1){
        int tmp;
        scanf("%d",&tmp);
        if(tmp != -1001){
            tree[n] = tmp;
        }else{
            break;
        }
        n++;
    }
    printf(check(0) ? "True":"False");
}