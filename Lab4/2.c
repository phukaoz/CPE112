#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int val;
    struct node* next;
}node;

node* head = NULL;

char buffer[100000] = "";

void push(int val){
    node* new = malloc(sizeof(node));
    new->val = val;
    new->next = NULL;
    if(head == NULL){
        head = new;
    }else{
        new->next = head;
        head = new;
    }
}

void pop(){
    if(head == NULL){
        char tmp[100];
        printf("empty\n");
        
        return;
    }
    
    node* ptr = head;
    char tmp[100];
    printf("%d\n", ptr->val);
    
    head = head->next;
    free(ptr);
}

int top(){
    if(head == NULL){
        return -1;
    }
    return head->val;
}

int empty(){
    return (head == NULL);
}
int main(void){
    while(1){
        char q;
        scanf("%c",&q);
        switch(q){
            case 'p':
                int val;
                scanf("%d",&val);
                push(val);
                break;
                
            case 'e':
                char tmp[100];
                printf("%d\n",empty());
                
                break;
                
            case 'o':
                pop();
                break;
                
            case 't':
                if(!empty()){
                    char tmp[100];
                    printf("%d\n",top());
                    
                }else{
                    printf("empty\n");
                    
                }
                break;
                
            case 'q':
                return 0;
                break;
                
            default:
                break;
        }
    }
}