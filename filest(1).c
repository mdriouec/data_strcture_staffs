#include <stdio.h>
#define TAILLE 10
typedef struct file{
    int value[TAILLE];
    int head;
    int tail;
    int taille;
}file;
void cree(file* f){
    f->head = 0 ;
    f->tail = 0;
    f->taille = 0;
}
int enfile(file* f,int v){
       if(f->tail == 0 && f->head == 0 && f->taille == 0){
        f->value[f->tail] = v;
        f->taille++;
       }
     if(f->tail + 1 != TAILLE){
             f->value[f->tail] = v;
             f->tail++;
        f->taille++;  
        return 1;
    }else{
        printf("the file is full\n");
        return 0;
    }
}
int defile(file* f){
    if(f->tail == 0 && f->head == 0 && f->taille == 0){
        printf("the queque is empty");
        return 0;
    }else{
         //f->value[f->head] = f->value[f->head + 1];
         f->head++;
    
        return 1;
    }
}
void Display(file* f){
    if(f->taille != 0){
    printf("head->");
    for (int i = f->head; i < f->tail ; i++){
        printf("| %d |",f->value[i]);
    }printf("<-tail");
    printf("\n");}
    else{
        printf("the file is empty");
    }
}
int main(){
    file* f ;
    cree(f);
    enfile(f,5);
   enfile(f,6);
    enfile(f,7);
    enfile(f,8);
    Display(f);
    defile(f);
    Display(f);
    return 0;
}