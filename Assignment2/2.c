/*
	tanapat namsomboon
	66070501022
*/
#include <stdio.h>
#include <stdlib.h>

#define endl printf("\n")
#define max(a,b) ((a > b) ? a : b)

int main(int argc,char** argv){
	int n;
	scanf("%d",&n);
	int v[n];
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	int cnt = 0;
	int len = 0;
	int nxt = 0;
	for(int i=0;i<n;i++){
		len = max(v[i] + i, len);
		if(i == nxt){
			if(i >= len){
				printf("Not Possible");
				break;
			}
			cnt++;
			nxt = len;
			if(len >= n-1){
				printf("%d",cnt);
				break;
			}
		}
	}
	return 0;
}