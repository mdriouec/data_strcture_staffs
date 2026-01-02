#include <stdio.h>
#include <stdlib.h>
typedef struct vertex{
    int value;
    struct vertex* right;
    struct vertex* left;
}vertex;
vertex* creevertex(int v){
    vertex* l = (vertex*)malloc(sizeof(vertex));
    l->value = v;
    l->right = NULL;
    l->left = NULL;
    return l;
}
vertex* creeArbre(vertex* l){
    return NULL;
}
vertex* addElt(vertex* l,int v){
    vertex* n = creevertex(v);
    if (l == NULL){
        return n;
    }else{
        if( v < l->value){
            l->left = addElt(l->left,v);
            return  l;
        }
        else if ( v > l->value){
            l->right = addElt(l->right,v);
            return l;
        
    }
}
}
void supptree(vertex* l){
    if(l != NULL){
        supptree(l->left);
        supptree(l->right);
        free(l);
    }
}
int hight(vertex* l){
    if (l == NULL){
        return 0;
    }else{
        int hl = hight(l->left);
        int hr = hight(l->right);
        return hl < hr ? hr + 1  : hl + 1;
    }
}
int size(vertex* l){
    if( l == NULL){
        return 0;
    }else{
        return size(l->left) + size(l->right) + 1;
    }
}
int nbinterne(vertex* l){
    if(l == NULL || l->left == NULL && l->right == NULL){
        return 1;
    }else{
        return nbinterne(l->left) + nbinterne(l->right) + 1;
    }
}
int nbexterne(vertex* l){
    if(l == NULL){
        return 0;
    }
    if(l->right == NULL && l->left == NULL){
        return 1;
    }else{
        return nbexterne(l->left) + nbexterne(l->right);
    }
}
void bfs(vertex* l){
     if(l != NULL){
        printf("%d", l->value);
        bfs(l->left);
        bfs(l->right);
    }
}
void dfs(vertex* l){
    if(l != NULL){
    dfs(l->left);
    printf("%d ",l->value);
    dfs(l->right);
                    
   }
}
void postfixe(vertex* l){
    if( l != NULL ){
        postfixe(l->left);
        postfixe(l->right);
        printf("%d", l->value);
    }
}
int find(vertex* l, int v){
    if (l == NULL) return 0;
    if (v == l->value) return 1;
    if ( v < l->value) return find(l->left,v);
    else {
       return find(l->right,v);
    }
} 
vertex*  ppet(vertex* l){
       if(l == NULL){
        return NULL;
       }else{
            vertex* tmp = l;
            while(tmp->left != NULL){
                tmp = tmp->left;
            }
            return tmp;
       }
}
vertex* pget(vertex* l){
    if(l == NULL){
 return NULL;
}else{
     vertex* tmp = l;
     while(tmp->right != NULL){
         tmp = tmp->right;
     }
     
     return tmp;
}
}
vertex* suppElt(vertex* l,int v){
    if(l == NULL) return l;                       
    if(v < l->value)  l->left = suppElt(l->left,v);
    else if(v > l->value)  l->right = suppElt(l->right,v);
    else{
        if (l->left == NULL){
            vertex* tmp = l->right;
            free(l);
            return tmp;
        }else if(l->right == NULL ){
            vertex* tmp = l->left;
            free(l);
            return tmp;
        }else{
            vertex* tmp = ppet(l->right);
            l->value = tmp->value;
            l->right = suppElt(l->right,tmp->value);
        }
        return l;
    }
    
}

void afficherArbre(vertex* racine, int espace,int niveau){
    if(racine == NULL)
    return;
espace += 10;
afficherArbre(racine->right, espace, niveau + 1);
printf("\n");
int i;
for (i = 10; i < espace; i++){
    printf(" ");
}
printf("%d\n", racine->value);
afficherArbre(racine->left, espace, niveau + 1);
}
int main(){
    vertex* racine = creeArbre(racine);
    racine = addElt(racine, 50);
    racine = addElt(racine, 30);
    racine = addElt(racine, 20);
    racine = addElt(racine, 40);
    racine = addElt(racine, 70);
    racine = addElt(racine, 60);
    racine = addElt(racine, 80);
    printf("parcour Infixe:");
    bfs(racine);
    printf("\n");
    printf("hautaur de l'arbre :%d\n",hight(racine));
    printf("Taille de l'arbre :%d\n",size(racine));
    printf("Nombre de vertexe internes : %d\n", nbinterne(racine));
    printf("Nombre de vertexes Externes : %d\n", nbexterne(racine));
    printf("le plus petit element :%d\n", ppet(racine)->value);
    printf("le plus grand element :%d\n", pget(racine)->value);
    find(racine,40); 
printf("l'Affichage de l'arbre binaire: \n");
afficherArbre(racine, 0, 0);
suppElt(racine, 70);
printf("affichage de l'arbre binaaire apres la supression de 70:\n");
afficherArbre(racine, 0, 0);
supptree(racine);
return 0;
   
}

