/*
	tanapat namsomboon
	66070501022
*/
#include <stdio.h>
#include <stdlib.h>

#define endl printf("\n")

int main(int argc,char** argv){
	int n1,m1;
	scanf("%d %d",&n1,&m1);
	int A[n1][m1];
	for(int i=0;i<n1;i++){
		for(int j=0;j<m1;j++){
			scanf("%d",&A[i][j]);
		}
	}
	
	int n2,m2;
	scanf("%d %d",&n2,&m2);
	int B[n2][m2];
	for(int i=0;i<n2;i++){
		for(int j=0;j<m2;j++){
			scanf("%d",&B[i][j]);
		}
	}
	
	int C[n1][m2];
	for(int i=0;i<n1;i++){
		for(int j=0;j<m2;j++){
			C[i][j] = 0;
		}
	}
	if(m1 != n2){
		printf("Not Compatible");
		return 0;
	}
	for(int i = 0;i < n1;i++){
		for(int k=0;k < m1;k++){
			for(int j=0;j <m2;j++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	for(int i=0;i<n1;i++){
		for(int j=0;j<m2;j++){
			printf("%d ",C[i][j]);
		}
		endl;
	}
	return 0;
}