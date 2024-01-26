#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    
    int q;
    scanf("%d",&q);
    if(q == 0){
        for(int i=0;i<n;i+=2){
            printf("%d ",*(arr+i));
        }
    }else{
        if(n == 1)printf("none");
        for(int i=1;i<n;i+=2){
            printf("%d ",*(arr+i));
        }
    }
    return 0;
}