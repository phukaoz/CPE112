/*
	tanapat namsomboon
	66070501022
*/
#include <stdio.h>
#include <stdlib.h>

#define endl printf("\n")

int diri[4] = {0, 1, 0, -1};
int dirj[4] = {1, 0, -1, 0};

int main(int argc,char** argv){
	int r,c;
	scanf("%d %d",&r,&c);
	int f[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			f[i][j] = 0;
		}
	}
	int mat[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	int pos[2] = {0,0};
	int dir = 0;
	for(int i=0;i<r*c;i++){
		printf("%d ",mat[pos[0]][pos[1]]);
		f[pos[0]][pos[1]] = 1;
		int npos[2] = {pos[0] + diri[dir], pos[1] + dirj[dir]};
		if(npos[0] >= 0 && npos[0] < r && npos[1] >= 0 && npos[1] < c && !f[npos[0]][npos[1]]){
			pos[0] = npos[0];
			pos[1] = npos[1];
		}else{
			dir = (dir + 1)%4;
			pos[0] += diri[dir];
			pos[1] += dirj[dir];
		}
	}
	return 0;
}