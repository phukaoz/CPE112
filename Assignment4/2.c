/*
    Tanapat Namsomboon
    66070501022
*/
#include <stdio.h>
#include <string.h>

int main(){
    char buffer[100];
    scanf("%s",buffer);
    int l = 0, r = strlen(buffer)-1;
    while(l < r){
        if(buffer[l] != buffer[r]){
            printf("no");
            return 0;
        }
        l++;r--;
    }
    
    printf("yes");
}