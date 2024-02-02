#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//here
typedef struct ListNode
{
int val;
struct ListNode *next;
} ListNode;

ListNode* head = NULL;
ListNode* tail = NULL;

void push(int val){
    ListNode* tmp = malloc(sizeof(ListNode));
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

int main(void){
    char buffer[10];
    while(1){
        scanf("%s",buffer);
        if(strcmp(buffer,"END") == 0){
            break;
        }
        int value = atoi(buffer);
        push(value);
    }
    int l,r;
    scanf("%d %d",&l,&r);
    int i=1;
    ListNode* ptr = head;
    ListNode* prev = NULL;
    ListNode* next;
    ListNode* before=NULL;
    ListNode* first;
    while(i<l){
        before = ptr;
        ptr = ptr->next;
        i++;
    }
    first = ptr;
    prev = first;
    ptr = ptr->next;
    for(int j=1;j<=r-l;j++){
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    first->next = ptr;
    if(before == NULL){
        head = prev;
    }else{
        before->next = prev;
    }
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
}