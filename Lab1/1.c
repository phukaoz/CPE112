/*
	tanapat namsomboon
	66070501022
*/
#include <stdio.h>

int main(int argc,char** argv){
	int n;
	scanf("%d",&n);
	int j = 0;
	int res[n];
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		if(j==0){
			res[j] = tmp;
			j++;
		}else{
			if(res[j-1] != tmp){
				res[j] = tmp;
				j++;
			}
		}
	}
	printf("%d\n",j);
	for(int i=0;i<j;i++){
		printf("%d ",res[i]);
	}
	return 0;
}