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
int size;

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

void F(){
    if(head == NULL){
        return;
    }
    if(size == 1){
        free(head);
        tail = NULL;
        head = NULL;
        size = 0;
        return;
    }
    struct node* ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    size--;
}

void L(){
    if(head == NULL){
        return;
    }
    if(size == 1){
        free(head);
        tail = NULL;
        head = NULL;
        size = 0;
        return;
    }
    struct node* ptr = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(ptr);
    size--;
}

void N(int tar){
    struct node* ptr = head;
    while(ptr != NULL){
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
            }
            if(ptr != head){
                p1->next = p2;
            }else{
                head = p2;
            }
            free(ptr);
            size--;
            return;
        }
        ptr = ptr->next;
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
    size = n;
    while(1){
        char mode;
        scanf(" %c",&mode);
        if(mode == 'E'){
            break;
        }
        if(mode == 'F'){
            F();
        }else if(mode == 'L'){
            L();
        }else{
            int tar;
            scanf("%d",&tar);
            N(tar);
        }
    }
    if(size == 0){
        printf("none");
    }
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
    return 0;
}