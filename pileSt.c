#include <stdio.h>
               
#define TAILLE 10
typedef struct pile{
    int value[TAILLE];
    int  sommet;
}pile;
void cree(pile* p){
    p->sommet = 0;
}
int empiler(pile* p,int v){
    if(p->sommet != TAILLE){
        p->value[p->sommet] = v;
        p->sommet++;
        return 1;
    }else{
        printf("the pile is full\n");
        return 0;
    }
}
int depile(pile* p){
    if(p->sommet != 0){
        p->sommet--;
        return p->value[p->sommet];
    }else{
        printf("the stack is empty\n");
        return -1;
    }
}
void Display(pile* p){
    if(p->sommet != 0){
        for(int i=p->sommet-1 ; i >= 0 ; i--){
        printf("| %d  | \n", p->value[i]);
       
      }
    }
    printf("\n");
}
int main(){
    pile* p; 
  cree(p);
  empiler(p,5);
  empiler(p,6);
  empiler(p,7);
  empiler(p,8);
  Display(p);
  depile(p);
  Display(p);
  depile(p);
  Display(p);
  
}