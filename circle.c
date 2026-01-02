#include <stdio.h>
#include <stdlib.h>
typedef struct elt{
    int value;
    struct elt* next;
}elt;
elt* cree(int v){
     elt* newBox =(elt*)malloc(sizeof(elt));
     if(newBox == NULL){
        printf("allocation failed");
        exit(1);
     }
     newBox->value = v;
     newBox->next = newBox;
     return newBox;
}
elt* insertHead(elt* fin ,  int v){
     elt* l = cree(v);
     if( fin == NULL){
        fin = l;
     }else{
        l->next = fin->next;
          fin->next = l;
     }return fin;
    
}
elt* insertTail(elt* fin,int v){
    elt* l = cree(v);
     if( fin == NULL){
    fin = l;
 }else{
    l->next = fin->next ;
    fin->next = l;
    fin = l;
    }
    return fin;
 }
 elt* insertMid(elt* fin, int v,int before, int after){
    elt* l = cree(v);
        if( fin == NULL){
   fin = l;
}else{
    elt* tmp = fin->next;
    elt*tmp2 = tmp->next;
    while(tmp->value != before  && tmp2->value != after){
        tmp = tmp->next;
        tmp2 = tmp2->next;
    }
    tmp->next = l;
    l->next = tmp2;    
}
return fin;
 }
 elt* supphead(elt* fin){
    if(fin == NULL){
        printf("NULL\n");
        return fin;
    }else{
        elt* tmp = fin->next;
        fin->next = tmp->next;
        free(tmp);
        return fin;
    }
 }
 elt* supptail(elt* fin){
    if(fin == NULL){
    printf("NULL\n");
    return fin;
}else{
    elt* tmp = fin;
    elt* tmp2 = fin->next;    
    while(tmp->next != fin){
        tmp = tmp->next;
        tmp2 = tmp2->next;
    }
    tmp->next = fin->next;
    fin->next = tmp;
    fin = tmp;
    free(tmp2);
    return fin;
}
 } 
elt* suppmid(elt* fin,int v){
    if(fin == NULL){
printf("NULL\n");
return fin;}else{
    elt* tmp = fin->next;
    elt*tmp2 = tmp->next;
    while(tmp2->value != v){
        tmp = tmp->next;
        tmp2 = tmp2->next;
    }
    tmp->next = tmp2->next;
    free(tmp2);
    return fin;
}
}
void Display(elt* fin){
    elt* tmp;
    if(fin == NULL){
        printf("NULL\n");
    }else{
        
        tmp = fin->next;
        do{
            
            printf("%d->",tmp->value);
            tmp = tmp->next;
        }while(tmp != fin->next);
        printf("fin\n");
    }
}
int main(){
    elt* fin = NULL;
    fin = insertHead(fin,4);
    fin = insertHead(fin,5);
    fin = insertHead(fin,6);
    Display(fin);
    fin = insertTail(fin,3);
    fin = insertTail(fin,2);
    Display(fin);
    fin = supphead(fin);
    Display(fin);
    fin = supptail(fin);
    Display(fin);
    fin = insertMid(fin,2,4,3);
    Display(fin);
    printf("apres la suppresion de 4:\n");
    fin =suppmid(fin,4);
    Display(fin);
}