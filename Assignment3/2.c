#include <stdio.h>

int cnt = 0;

int main(void){
    int n,k;
    scanf("%d %d",&n,&k);
    int v[n];
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    int ans = 0;
    int i = 1;
    while(i <= n){
        ans = (ans+k) % i;
        i++;
    }
    printf("%d",v[ans]);
    return 0;
}