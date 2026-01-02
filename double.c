#include <stdio.h>
#include <stdlib.h>
typedef struct elt{
    int value;
    struct elt* next;
    struct elt* previous;
}elt;
elt* cree(elt* l){
    l = NULL;
   return l;
}
elt* insertHead(elt* l, int v){
    elt* newl = malloc(sizeof(elt));
    newl->next = NULL;
    newl->previous = NULL;
    if(l == NULL){
        newl->value =v;
        return newl;
    }else{
        newl->value = v;
        newl->next = l;
        l->previous = newl;
        newl->previous = NULL;
        
        return newl;
    }
}
elt* insertTail(elt* l,int v){
    elt* newl = malloc(sizeof(elt));
    newl->next = NULL;
newl->previous = NULL;
if(l == NULL){
    newl->value =v;
    return newl;
}else{
    elt* tmp = l;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
   newl->value = v;
   tmp->next = newl;
   newl->previous = tmp;
   return l;
}
}
elt* removeHead(elt* l){
    if(l == NULL){
        return l;
    }else{
        elt* tmp = l;
        tmp = tmp->next;
        tmp->previous = NULL;
        free(l);
        return tmp;
    }
}
elt* removeTail(elt* l){
    if(l == NULL){
    return l;
}else{
    elt* tmp = l;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->previous->next = NULL;
     
    free(tmp);
    return l;
}
}
elt* removeMiddle(elt* l, int v){
    if(l == NULL){
    return l;
}else{
    elt* tmp = l;
    while(tmp->value != v){
        tmp = tmp->next;
    }
    tmp->previous->next = tmp->next;
    tmp->next->previous = tmp->previous;
    free(tmp);
    return l; 
}
}
void Find(elt* l, int v){
    int i = 0;
    if(l == NULL){
        printf("NULL\n");
    }
    else{
        elt* tmp = l;
        while(tmp!= NULL){
           if (tmp->value == v){
            i = 1;
           }
           tmp = tmp->next;
        }
      if(i==1){
        printf("exist!!\n");
      }else printf("Doesn't exist.\n");
    }
}
void Display(elt* l){
    if(l == NULL){
        printf("NULL\n");
       return ;
    }else{
     while(l != NULL){
        printf("%d<->",l->value);
        l = l->next;
     }
     printf("NULL\n");
    }
}
int main(){
    elt* l;
    l = cree(l);
    l = insertHead(l,3);
    l = insertHead(l,2);
    l = insertHead(l,1);
    Display(l);
    l = insertTail(l,4);
    Display(l);
    //l = removeHead(l);
    //printf("after we remove at head:\n");
    //Display(l);
   // printf("after remove tail:\n");
   // l = removeTail(l);
   l = removeMiddle(l,2);
    Display(l);
    Find(l,2);
    return 0;
}