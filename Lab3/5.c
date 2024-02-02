/*
    Tanapat Namsomboon
    66070501022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int val;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;
int size;
int k = 0;
int search[100000];

void ADD(int val){
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
    tail->next = head;
    head->prev = tail;
}

void DEL(int tar){
    struct node* ptr = head;
    if(ptr == NULL){
        return;
    }
    while(1){
        if(ptr->val == tar){
            struct node* p1 = ptr->prev;
            struct node* p2 = ptr->next;
            if(size == 1){
                head = tail = NULL;
                size = 0;
                free(ptr);
                return;
            }
            if(ptr != tail){
                p2->prev = p1;
            }else{
                tail = p1;
                head->prev = tail;
            }
            if(ptr != head){
                p1->next = p2;
            }else{
                head = p2;
                tail->next = head;
            }
            free(ptr);
            size--;
            return;
        }
        if(ptr == tail){
            break;
        }
        ptr = ptr->next;
    }
}

int main(void){
    size = 0;
    while(1){
        char mode;
        int val;
        scanf(" %c",&mode);
        if(mode == 'E'){
            break;
        }else if(mode == 'I'){
            scanf("%d",&val);
            ADD(val);
            size++;
        }else{
            scanf("%d",&val);
            DEL(val);
        }
    }
    if(size == 0){
        printf("Empty");
        return 0;
    }
    while(1){
        printf("%d ",head->val);
        if(head == tail)break;
        head = head->next;   
    }
    return 0;
}