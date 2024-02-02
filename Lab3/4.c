/*
    Tanapat Namsomboon
    66070501022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MIN -999999
#define INT_MAX 999999

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
    size++;
}

void DEL(int tar){
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

void SCH(int tar){
    struct node* ptr = head;
    while(ptr != NULL){
        if(ptr->val == tar){
            if(ptr->prev == NULL){
                search[k] = INT_MIN;
            }else{
                search[k] = ptr->prev->val;
            } 
            k++;
            if(ptr->next == NULL){
                search[k] = INT_MIN;
            }else{
                search[k] = ptr->next->val;
            }
            k++;
            return;
        }
        ptr = ptr->next;
    }
    search[k] = INT_MAX;
    k+=2;
}

int main(void){
    size = 0;
    while(1){
        char mode[4];
        int val;
        scanf("%s",mode);
        if(strcmp(mode,"END") == 0){
            break;
        }else if(strcmp(mode,"ADD") == 0){
            scanf("%d",&val);
            ADD(val);
            
        }else if(strcmp(mode,"DEL") == 0){
            scanf("%d",&val);
            DEL(val);
        }else{
            scanf("%d",&val);
            SCH(val);
        }
    }
    for(int j=0;j<k;j++){
        if(search[j] == INT_MIN){
            printf("NULL");
        }else if(search[j] == INT_MAX){
            printf("none");
            j++;
        }else{
            printf("%d",search[j]);
        }
        if(j&1){
            printf("\n");
        }else{
            printf(" ");
        }
    }
    if(size == 0){
        printf("none");
    }
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
    if(size == 0){
        printf("none");
    }
    while(tail != NULL){
        printf("%d ",tail->val);
        tail = tail->prev;
    }
    return 0;
}