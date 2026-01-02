#include <stdio.h>
#include <stdlib.h>
typedef struct element{
    int value;
    struct element* next;
}element;
typedef struct pile{
    int taille;
    element* sommet;
}pile;
void cree(pile* p){
    p->sommet = NULL;
    p->taille = 0;
}
int empiler(pile* p, int v){
    element* newl = malloc(sizeof(element));
    if(newl == NULL){
        return -1;
    }else{
        newl->value = v;
        newl->next = p->sommet;
        p->sommet = newl;
        p->taille++;
        return 0;
    }
}
int  depile(pile* p){
    if(p->taille == 0){
        printf("the stack is empty\n");
        return -1;
    }else{
        element* tmp = p->sommet;
        p->sommet = p->sommet->next;
        free(tmp);
        p->taille--;
        return 0;
    }
}
void Display(pile* p){
    element* tmp = p->sommet;

        for(int i = p->taille; i > 0;i--){
            printf("| %d |\n  ^\n",tmp->value);
            tmp = tmp->next;
        }
        printf("\n");
    
}
int main(){
    pile* p;
    cree(p);
    //empiler(p,5);
   // empiler(p,6);
    //empiler(p,7);
 //   Display(p);
    depile(p);
    Display(p);
   return 0;
}