/*
	tanapat namsomboon
	66070501022
*/

#include <stdio.h>


#define nl printf("\n");

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	int p,q;
	scanf("%d",&p);
	int A[p];
	for(int i=0;i<p;i++){
		scanf("%d",&A[i]);
	}
	scanf("%d",&q);
	int B[q];
	for(int i=0;i<q;i++){
		scanf("%d",&B[i]);
	}
	int first = 1;
	int prev = 0;
	int sizeA = 0;
	int sizeB = 0;
	int SA[p];
	int SB[q];
	int cnt = 0;
	for(int i=0;i<p;i++){
		if(A[i] > n || A[i] < m)continue;
		if(!first){
			if(A[i] == prev)continue;
		}
		printf("%d " ,A[i]);
		cnt++;
		SA[sizeA] = A[i];
		sizeA++;
		prev = A[i];
		first = 0;
	}
	if(cnt == 0){
		printf("empty");
	}
	nl;
	first = 1;
	prev = 0;
	cnt = 0;
	for(int i=0;i<q;i++){
		if(B[i] > n || B[i] < m)continue;
		if(!first){
			if(B[i] == prev)continue;
		}
		printf("%d ",B[i]);cnt++;
		SB[sizeB] = B[i];
		sizeB++;
		prev = B[i];
		first = 0;
	}
	if(cnt == 0){
		printf("empty");
	}
	nl;
	first = 1;
	prev = 0;
	int l = 0;
	int r = 0;
	cnt = 0;
	while(1){
		if(l >= sizeA){
			for(int i=r;i<sizeB;i++){
				printf("%d ",SB[i]);cnt++;
			}
			break;
		}
		if(r >= sizeB){
			for(int i=l;i<sizeA;i++){
				printf("%d ",SA[i]);cnt++;
			}
			break;
		}
		if(SA[l] < SB[r]){
			if(!first && SA[l] == prev){
				l++;
				continue;
			}
			printf("%d ",SA[l]);cnt++;
			prev = SA[l];
			l++;
		}else if(SA[l] > SB[r]){
			if(!first && B[r] == prev){
				r++;
				continue;
			}
			printf("%d ",SB[r]);cnt++;
			prev = SB[r];
			r++;
		}else{
			printf("%d ",SA[l]);cnt++;
			prev = SA[l];	
			l++;
			r++;
		}
		first = 0;
	}
	if(cnt == 0){
		printf("empty");
	}
	nl;
	l = 0;
	r = 0;
	cnt = 0;
	while(l < sizeA && r < sizeB){
		if(SA[l] < SB[r]){
			l++;
		}else if(SA[l] > SB[r]){
			r++;
		}else{
			printf("%d ",SA[l]);cnt++;
			l++;r++;
		}
	}
	if(cnt == 0){
		printf("empty");
	}
	nl;
	l=0;
	r=0;
	cnt = 0;
	while(1){
		if(l >= sizeA){
			break;
		}
		if(r >= sizeB){
			for(int i=l;i<sizeA;i++){
				printf("%d ",SA[i]);cnt++;
			}
			break;
		}
		if(SA[l] < SB[r]){
			printf("%d ",SA[l]);cnt++;
			l++;
		}else if(SA[l] > SB[r]){
			r++;
		}else{
			l++;
			r++;
		}
	}
	if(cnt == 0){
		printf("empty");
	}
	nl;
	l=0;
	r=0;
	cnt = 0;
	while(1){
		if(l >= sizeB){
			break;
		}
		if(r >= sizeA){
			for(int i=l;i<sizeB;i++){
				printf("%d ",SB[i]);cnt++;
			}
			break;
		}
		if(SB[l] < SA[r]){
			printf("%d ",SB[l]);
			cnt++;
			l++;
		}else if(SB[l] > SA[r]){
			r++;
		}else{
			l++;
			r++;
		}
	}
	if(cnt == 0){
		printf("empty");
	}
	nl;
	l = 0;
	cnt = 0;
	while(l<sizeA && SA[l] < m){
		l++;
	}
	for(int i=m;i<=n;i++){
		if(sizeA > 0 && i == SA[l]){
			l++;
		}else{
			printf("%d ",i);
			cnt++;
		}
	}
	if(cnt == 0){
		printf("empty");
	}
	nl;
	l = 0;
	cnt =0;
	while(l<sizeB && SB[l] < m){
		l++;
	}
	for(int i=m;i<=n;i++){
		if(sizeB > 0 && i == SB[l]){
			l++;
		}else{
			printf("%d ",i);
			cnt++;
		}
	}
	if(cnt == 0){
		printf("empty");
	}
	return 0;
}