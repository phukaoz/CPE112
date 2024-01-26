/*
	tanapat namsomboon
	66070501022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define endl printf("\n")

typedef struct{
	char name[101];
	float score;
} student;

int main(int argc,char** argv){
	int n;
	scanf("%d",&n);
	student v[n];
	student smax = {"",0.0f};
	student smin = {"",100.0f};
	float sum = 0.0f;
	for(int i=0;i<n;i++){
		scanf("%s %f",v[i].name,&v[i].score);
		sum += v[i].score;
		if(smax.score < v[i].score){
			smax.score = v[i].score;
			strcpy(smax.name,v[i].name);
		}
		if(smin.score > v[i].score){
			smin.score = v[i].score;
			strcpy(smin.name,v[i].name);
		}
	}
	float mean = sum/n;
	sum = 0.0f;
	for(int i=0;i<n;i++){
		sum += (v[i].score-mean) * (v[i].score-mean);
	}
	float sd = sqrt(sum/n);
	printf("%.2f %.2f %s %s",mean,sd,smax.name,smin.name); 
	return 0;
}