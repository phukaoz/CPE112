/*
	tanapat namsomboon
	66070501022
*/

#include <stdio.h>
#include <stdlib.h>

void cout(int* arr,int sz){
    int mx = *arr;
    int mn = *arr;
    int mxpos = 0;
    int mnpos = 0;
    for(int i=1;i<sz;i++){
        if(mx < *(arr+i)){
            mx = *(arr+i);
            mxpos = i;
        }
        if(mn > *(arr+i)){
            mn = *(arr+i);
            mnpos = i;
        }
    }
    printf("%d %d\n%d %d",mx,mxpos,mn,mnpos);
}

int main(){
    int n;
    scanf("%d",&n);
    int* vec = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",vec+i);
    }
    cout(vec,n);
    return 0;
}