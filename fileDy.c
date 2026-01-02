#include <stdio.h>
#include <stdlib.h>
typedef struct element{
    int value;
    struct element* next;
}element;
typedef struct file{
    int taille;
    element* head;
    element* tail;
}file;
void cree(file* f){
    f->taille = 0;
    f->head = NULL;
    f->tail = NULL;
}
int enfile(file* f,int v){
    element* newl =(element*)malloc(sizeof(element));
    if(f->head == NULL && f->tail == NULL  ){
        newl->value = v;
        f->tail = newl;
        f->head = newl;
        f->taille++;
        return 0;
    }else{
        newl->value = v;
        f->tail->next = newl;
        newl->next = NULL;
        f->tail = newl ;
        f->taille++;
        return 1;
    }
}
int defile(file* f){
    if(f->head == NULL && f->tail == NULL){
        printf("the queque is empty\n");
        return 0;
    }else{
        element* tmp = f->head;
        f->head = f->head->next;
        free(tmp);
        return 1;
    }
}
void Display(file* f){
    if(f->head == NULL && f->tail == NULL){
        printf("the queque is empty\n");
    }else{
        element* tmp = f->head;
        printf("head <-");
        while(tmp != NULL){
            printf("| %d | <-",tmp->value);
            tmp = tmp->next;
        }
        printf("tail\n");
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