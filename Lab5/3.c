#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <string.h>

typedef struct {
    char ch;
    int num;
    int prior;
}c;

#define type c

int compare(const type *a, const type *b){
    if(a->prior == b->prior){
        return a->num < b->num;
    }
    return a->prior > b->prior;
}

typedef struct{
    size_t size;
    size_t capacity;
    type *array;
}priority_queue;

priority_queue* priority_queue_create(){
    priority_queue* new_queue = (priority_queue*)malloc(sizeof(priority_queue));
    new_queue->capacity = 8;
    new_queue->array = (type*)malloc(sizeof(type) * new_queue->capacity);
    new_queue->size = 0;
    return new_queue;
}

void priority_queue_free(priority_queue* queue){
    free(queue->array);
    free(queue);
}

void push(priority_queue* queue, type value){
    if(queue->size >= queue->capacity){
        queue->capacity = queue->capacity << 1; //double capacity
        queue->array = (type*)realloc(queue->array, queue->capacity*sizeof(type));
    }
    queue->array[queue->size++] = value;
    size_t index = queue->size-1;
    while(index > 0 && compare(&(queue->array[index]),&(queue->array[(index-1)/2]))){
        type temp = queue->array[index];
        queue->array[index] = queue->array[(index-1)/2];
        queue->array[(index-1)/2] = temp;
        index = (index-1)/2;
    }
}

int empty(priority_queue* queue){
    return (queue->size == 0);
}

void pop(priority_queue* queue){
    if(empty(queue)){
        fprintf(stderr,"Can't pop, priority_queue is empty.");
        exit(EXIT_FAILURE);
    }
    queue->size--;
    queue->array[0] = queue->array[queue->size];
    type tmp = queue->array[0];
    size_t idx = 0;
    size_t c;
    while((c = 2*idx+1) < queue->size){
        if(c+1 < queue->size && !compare(&(queue->array[c]),&(queue->array[c+1]))){
            c++;
        }
        if(!compare(&(queue->array[c]),&tmp)){
            break;
        }
        queue->array[idx] = queue->array[c];
        idx = c;
    }
    queue->array[idx] = tmp;
}

type top(priority_queue* queue){
    return queue->array[0];
}


int main(){
    priority_queue* pq = priority_queue_create();
    char in[10000];
    fgets(in,10000,stdin);
    for(int i=0;i<strlen(in)-1;i++){
        char buffer = in[i];
        c new;
        if((buffer >= 'a' && buffer <= 'z') || (buffer >= 'A' && buffer <= 'Z')){
            if(buffer == 'a' || buffer == 'e' || buffer == 'i' || buffer == 'o' || buffer == 'u' || buffer == 'A' || buffer == 'E' || buffer == 'I' || buffer == 'O' || buffer == 'U'){
                new.prior = 3;
            }else{
                new.prior = 1;
            }
        }else{
            new.prior = 2;
        }
        new.num = i;
        new.ch = buffer;
        push(pq,new);
    }
    while(!empty(pq)){
        printf("%c",top(pq).ch);
        pop(pq);
    }
}