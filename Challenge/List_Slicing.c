/*
	tanapat namsomboon
	66070501022
*/
#include <stdio.h>
#define readint(x) scanf("%d",&(x))


int main(){
    int n;
    readint(n);
    int arr[n];
    for(int i=0;i<n;i++){
        readint(arr[i]);
    }
    int l,r;
    long long int s;
    readint(l);
    readint(r);
    scanf("%lld",&s);
    if(l < -n){
        l = -n;
    }else if(l > n-1){
        l = n-1;
    }
    if(r < -n-1){
        r = -n-1;
    }else if(r > n){
        r = n;
    }
    if(l < 0){
        l = n+l;
    }
    if(r < 0){
        r = n+r;
    }
    int valid = 0;
    if(l < r){
        if(s > 0){
            for(int i=l;i<r;i+=s){
                valid = 1;
                printf("%d ",arr[i]);
            }
        }
    }else{
        if(s < 0){
            for(int i=l;i>r;i+=s){
                valid = 1;
                printf("%d ",arr[i]);
            }
        }
    }
    if(!valid){
        printf("empty");
    }
    return 0;

}