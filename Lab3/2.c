/*
    Tanapat Namsomboon
    66070501022
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;

void push_back(int val){
    struct node* tmp = malloc(sizeof(struct node));
    tmp->val = val;
    tmp->next = NULL;
    tmp->prev = NULL;
    if(head == NULL){
        head = tmp;
        tail = tmp;
    }else{
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
    }
}

void A(int val, int tar){
    struct node* p1 = head;
    struct node* p2;
    struct node* tmp = malloc(sizeof(struct node));
    tmp->val = val;
    tmp->next = NULL;
    tmp->prev = NULL;
    if(head == NULL){
        head = tmp;
        return;
    }
    while(p1 != NULL){
        if(p1->val == tar){
            p2 = p1->next;
            if(p2 != NULL){
                p2->prev = tmp;
                tmp->next = p2;
            }
            p1->next = tmp;
            tmp->prev = p1;
            break;
        }
        p1 = p1->next;
    }
}

void B(int val, int tar){
    struct node* p1 = head;
    struct node* p2;
    struct node* tmp = malloc(sizeof(struct node));
    tmp->val = val;
    tmp->prev = NULL;
    tmp->next = NULL;
    if(head == NULL){
        head = tmp;
        return;
    }
    while(p1 != NULL){
        if(p1->val == tar){
            p2 = p1->prev;
            if(p2 != NULL){
                p2->next = tmp;
                tmp->prev = p2;
            }else{
                head = tmp;
            }
            p1->prev = tmp;
            tmp->next = p1;
            break;
        }
        p1 = p1->next;
    }
}


int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        push_back(tmp);
    }
    while(1){
        char mode;
        scanf(" %c",&mode);
        if(mode == 'E'){
            break;
        }
        int tar,val;
        scanf("%d %d",&tar,&val);
        if(mode == 'A'){
            A(val,tar);
        }else{
            B(val,tar);
        }
    }
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
    return 0;
}