#include <stdio.h>
#include <stdlib.h>
#define Max 10 
typedef struct graph{
    int w[Max][Max];
    int v;
    int g;
}graph;
void inisialiser(graph *g, int n,int m){
    g->v = n;
    g-> = m;
    for(int i = 0; i< g->v ; i++){
        for(int j; j< g->v){
            w[i][j]= 0;
        }
    }
}
void ajouter(graph *g, int source , int dest , int poids){
    
}