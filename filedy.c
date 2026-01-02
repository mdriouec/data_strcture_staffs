#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int value;
    struct node* next;
}node;
typedef struct file{
    int taille;
    struct node* head;
    struct node* tail;
}file;
void cree(file* f){
     f->taille = 0;
     f->head =  NULL;
     f->tail = NULL;
}
int enfile(file* f, int v){
    node* newl =(node*)malloc(sizeof(node));
    if(f->tail == NULL && f->head == NULL){
        newl->value = v;
        newl->next = NULL;
        f->tail = newl;
        f->head = newl;
        f->taille++;
        return 0;
    }else{
        newl->value = v;
        newl->next = NULL;
        f->tail->next = newl;
        f->tail = newl;
        f->taille++;
        return 1;
    }
}
int defile(file *f){
    if ( f->tail == NULL && f->head == NULL){
        printf("the queque is empty");
        return -1;
    }else{
        node* tmp = f->head;
        f->head = f->head->next;
        free(tmp);

        return 0;
    }
}
void display(file* f){
    if(f->taille == 0 && f->tail == NULL && f->head == NULL){
        printf("the queque is empty");
    }else{
        node* tmp = f->head;
        printf("head");
        while (tmp != NULL ){
            printf("<| %d |",tmp->value);
            tmp = tmp->next;
        }printf("<tail");
    }printf("\n");
}
int main(){
    file* f;
    cree(f);
    enfile(f,1);
    enfile(f,2);
    enfile(f,3);
    enfile(f,4);
    display(f);
    defile(f);
    display(f);
}