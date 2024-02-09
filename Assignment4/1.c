#include <stdio.h>

int main(void){
    long long int n;
    int x;
    scanf("%lld %d",&n,&x);
    if(x < 2 || x > 36){
        printf("invalid");
        return 0;
    }
    char out[65];
    int len = 0;
    while(n > 0){
        int digit = n%x;
        char new;
        if(digit >= 0 && digit <= 9){
            new = (char)(digit + '0');
        }else{
            new = (char)(digit - 10 + 'A');
        }
        n/=x;
        out[len] = new;
        len++;
    }
    for(int i=len-1;i>=0;i--){
        printf("%c",out[i]);
    }
}