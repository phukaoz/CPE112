#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}node;

node* head = NULL;
node* tail = NULL;

void push(int val){
    node* new = malloc(sizeof(node));
    new->value = val;
    new->next = NULL;
    if(head == NULL){
        head = new;
        tail = new;
    }else{
        tail->next = new;
        tail = new;
    }
}

int main(void){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        push(tmp);
    }
    tail->next = head;
    int cnt = 1;
    int remain = n;
    node* ptr = head;
    node* prev = tail;
    node* next;
    while(remain > 1){
        next = ptr->next;
        if(cnt < k){
            cnt++;
        }else{
            cnt = 1;
            prev->next = next;
            remain--;
            free(ptr);
        }
        prev = ptr;
        ptr = next;
    }
    printf("%d",ptr->value);
}