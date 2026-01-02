#include <stdio.h>
#define TAILLE 10
typedef struct file{
    int value[TAILLE];
    int head,tail;
}file;
void cree(file* f){
    f->tail = 0;
    f->head = 0;
}
int enfile(file* f, int v){
    if(f->tail == 0 && f->head == 0 ){
        f->value[f->head] = f->value[f->tail] = v;
        f->tail++;
        return 1;
    }else{
       f->value[f->tail] = v;
       f->tail++;
       return 0;
    }
}
int defile(file* f){
    if(f->tail == 0 && f->head == 0){
        printf("the queque is emfty");
        return 1;
    }else{
        f->value[f->head] = f->value[f->head -1];
        f->head++;
        return 0;
    }
}
void display(file* f){
    if(f->head == 0 && f->tail == 0){
        printf("the stack is empty");
    }else{
        printf("tail>");
        for(int i = f->tail-1; i>=f->head;i--){
            printf("| %d |>", f->value[i]);
        }printf("head");
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