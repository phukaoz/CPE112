/*
    Tanapat Namsomboon
    66070501022
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void push_back(int val){
    struct node* tmp = malloc(sizeof(struct node));
    tmp->val = val;
    tmp->next = NULL;
    if(head == NULL){
        head = tmp;
        tail = tmp;
    }else{
        tail->next = tmp;
        tail = tmp;
    }
}

void push_front(int val){
    struct node* tmp = malloc(sizeof(struct node));
    tmp->val = val;
    tmp->next = NULL;
    if(head == NULL){
        head = tmp;
        tail = tmp;
    }else{
        tmp->next = head;
        head = tmp;
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    int valid = 1;
    if(n <= 0){
        valid = 0;
    }
    int q;
    scanf("%d",&q);
    if(q != 1 && q != 2){
        valid = 0;
    }
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        if(q==1){
            push_front(tmp);
        }else{
            push_back(tmp);
        }
    }
    if(!valid){
        printf("Invalid");
        return 0;
    }
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
    return 0;
}