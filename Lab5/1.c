#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct item{
    char name[1000];
    char artist[1000];
    int time;
}item;

item queue[100000];
int l = 0;
int r = 0;

void add(item val){
    queue[r] = val;
    r++; 
}

void play(){
    if(l == r){
        printf("No songs in the playlist\n");
        return;
    }
    printf("Now playing: %s by %s\n",queue[l].name,queue[l].artist);
    l++;
}

void sum(){
    printf("Songs in the playlist:\n");
    if(l == r){
        printf("No songs in the playlist\n");
        return;
    }
    int total = 0;
    //printf("l == %d, r == %d\n",l,r);
    while(l < r){
        printf("%s by %s %d\n",queue[l].name,queue[l].artist,queue[l].time);
        total+=queue[l].time;
        l++;
    }
    printf("Remaining Time: %d",total);
}

void clear (void){
    while ( getchar() != '\n' );
}

void readline(char* buffer){
    int i = 0;
    char c;
    while(1){
        c = getc(stdin);
        if(c == '\n'){
            buffer[i] = '\0';
            //printf("buffer = %s\n",buffer);
            return;
        }else{
            buffer[i] = c;
        }
        i++;
    }
}

int main(void){
    char buffer[1000];
    char q[1000];
    while(1){
        scanf("%s",q);
        if(strcmp(q,"add") == 0){
            item new;
            clear();
            readline(buffer);
            strcpy(new.name,buffer);
            readline(buffer);
            strcpy(new.artist,buffer);
            int time;
            scanf("%d",&time);
            new.time = time;
            //printf("time = %d\n",time);
            add(new);
        }else if(strcmp(q,"play") == 0){
            play();
        }else{
            sum();
            break;
        }
    }
}