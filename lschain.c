#include <stdio.h>
#include <stdlib.h>
typedef struct  nd{
    int value;
   struct nd *next;
}nd;

nd *cree(nd *l){
    l = NULL;
    return l;
}
nd *insertHead(nd *l, int v){
    nd *newl = malloc(sizeof(nd));
    if (l == NULL){
          newl->value = v ;
          newl->next = NULL;
        return newl;
    }
    else {
        newl->value = v;
        newl->next = l;
        l->next = NULL;
        return newl;
    }    
}
nd *insertTail(nd *l, int v){
    nd *newl = malloc(sizeof(nd));
     if (l == NULL){
       newl->value = v ;
       newl->next = NULL;
     return newl;
 }else{
    nd *temp;
    temp = l;
    while(temp->next != NULL){
        temp = temp->next;
    }
    newl->value = v ;
    newl->next = NULL;
    temp->next = newl ;
    return l;
 }
}
nd *removefirst(nd* l){
       nd *tmp = l;
       if(l != NULL){
        tmp = l->next;
        free(l);
       }
       return tmp;
}
nd *removelast(nd* l){
    if(l == NULL){
        printf(" NULL\n");
        return NULL;
    }
    else{
        nd* tmp = l;
        nd* tmp2 = l->next;
        while(tmp2->next != NULL){
              tmp = tmp2;
              tmp2=tmp2->next;
        }
        tmp->next = NULL;
        free(tmp2);
        return l;
        
    }
}
nd *removeMiddle(nd* l, int v){
    nd* tmp = l;
    nd* tmp2 = l->next;
    nd* tmp3 = l->next->next;
    if( l == NULL){
        printf("la chaine est vide\n");
        return l;
    }else{
        while(tmp2->value != v){
             tmp = tmp2;
             tmp2 = tmp3;
             tmp3 = tmp3->next;
        }
        tmp->next = tmp3;
        free(tmp2);
        return l;
    }
}
nd* supprep(nd* l,int v){
    nd* tmp = l;
    nd* tmp2;
    if(l == NULL){
        return l;
    }else{
        while(tmp != NULL && tmp->next != NULL){
            tmp2 = tmp->next;
            if( tmp2->value == v){
                  tmp->next = tmp2->next;
                  free(tmp2);
            }
            else{
                tmp = tmp->next;
            }
     
    }
    return l;
}
}
void searchV(nd* l, int v){
    if(l == NULL){
        printf("la list est vide!\n");
        return;
    }

       nd* tmp = l;
       bool i = false ;
       while(tmp != NULL){
         if(tmp->value == v){
          i = true;
        }
          tmp = tmp->next; 
        
       
       }
       if( i){
        printf("the element exist\n");
        }
       else {
        printf("the elemet doesnt  exist\n");
        }
    
}
void DisplayNd(nd *l){
    while(l != NULL){
        printf(" %d->", l->value);
        l = l->next;
    }
    printf(" NULL\n");
}
int main(){
    nd* l = cree(l);
    l= insertHead(l,4);
    l = insertHead(l,5);
    l= insertTail(l,4);
    l = insertTail(l,3);   
   //  DisplayNd(l);
 //   l = removefirst(l);
   // printf("apres la suppression de debut:\n");
   // DisplayNd(l);   
    //l = removelast(l);
     printf("apres la supression enfin de liste:\n");
     DisplayNd(l); 
     searchV(l,4);
     //l = removeMiddle(l,4);
  l = supprep(l,4);
     DisplayNd(l);
    return 0;
}