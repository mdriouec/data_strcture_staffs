#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}node;
typedef struct pile{
      int taille;
      struct node* sommet;
}pile;
void cree(pile *p){
    p->taille = 0;
    p->sommet = NULL;
}
int empiler(pile* p, int v){
    node* newl = malloc(sizeof(node));
    
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
int depile(pile *p){
    if (p->taille == 0){
        printf("the stack is empty");
        return -1;
    }else{
        node *tmp = p->sommet;
        p->sommet  = p->sommet->next;
        free(tmp);
        p->taille--;
        return 0;
    }
}
void Display(pile* p){
    if(p->taille == 0 ){
        printf("the stack is empty");
    }else{
        node* tmp = p->sommet;
        for(int i = p->taille; i > 0;i--){
            printf("| %d |\n  ^\n",tmp->value);
    tmp = tmp->next;
}
printf("\n");
    }
}
int main(){
    pile* p;
    cree(p);
    empiler(p,1);
    empiler(p,2);
    empiler(p,3);
    empiler(p,4);
    Display(p);
    depile(p);
    Display(p);
}