/*
	tanapat namsomboon
	66070501022
*/
#include <stdio.h>
#include <stdlib.h>

#define endl printf("\n")

int main(int argc,char** argv){
	int c,r;
	scanf("%d %d",&c,&r);
	int mat[r][c];
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf("%d",&mat[i][j]); 
		}
	}
	int sym = 1;
	int skew = 1;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(mat[i][j] != mat[j][i]){
				sym = 0;
				if(mat[i][j] != -mat[j][i]){
					skew = 0;
				}
			}
		}
	}
	if(sym){
		printf("The matrix is symmetric");
	}else if(skew){
		printf("The matrix is skew-symmetric");
	}else{
		printf("None");
	}
	
	return 0;
}