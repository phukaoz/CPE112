#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int ID;
    int score;
}student;

struct node{
    student val;
    struct node* next;
};

struct node* head = NULL;

void push(int id,int scr){
    struct node* tmp = malloc(sizeof(struct node));
    student s = {.ID = id, .score = scr};
    tmp->val =s;
    tmp->next = NULL;
    if(head == NULL){
        head = tmp;
        return;
    }
    tmp->next = head;
    head = tmp;
}

//is it ok?
void swap(struct node* a, struct node* b){
    student tmp = a->val;
    a->val = b->val;
    b->val = tmp;
}

int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int id,score;
        scanf("%d %d",&id,&score);
        push(id,score);
    }
    int mode;
    scanf("%d",&mode);
    for(int i=0;i<n;i++){
        struct node* p1 = head;
        while(p1 != NULL){
            struct node* p2 = p1->next;
            if(mode == 1){
                if(p2 != NULL && p1->val.score > p2->val.score){
                    swap(p1,p2);
                }
            }else{
                if(p2 != NULL && p1->val.ID > p2->val.ID){
                    swap(p1,p2);
                }
            }
            p1 = p1->next;
        }
    }
    while(head != NULL){
        printf("%d ",head->val.score);
        head = head->next;
    }
    return 0;
}