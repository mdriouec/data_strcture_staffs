#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct graph{
    int n,m;
    int adj[MAX][MAX];
}graph;
void initGraph(graph* g, int a,int b){
    g->n = a;
    g->m = b;
    for(int i = 0 ; i < g->n; i++){
        for(int j = 0; j < g->n; j++){
            g->adj[i][j] = 0;
        }
    }
}
void addvertex(graph* g,int src, int des,int poids){
        if( src >= 0 && src < g->n && des >= 0 && des < g->n){
             g->adj[src][des]=poids;          
        }else printf("error");
}
void rechersucc(graph *g , int n){
    printf("les succesures de %d est :", n);
    for(int i = 0 ; i < g->n ; i++){
        if(g->adj[n][i] != 0){
            printf(" %d (poids %d) ", i , g->adj[n][i] );
        }
    }
    printf("\n");
}
void searchPre(graph* g,int m){
    printf("les predecceurs de %d est:", m);
    for (int i = 0 ; i < g->m; i++){
        if(g->adj[i][m] != 0){
            printf(" %d (poids %d) ", i, g->adj[i][m]);
        }
    }
    printf("\n");
}
int main(){
      graph g;
      printf("entrer les nombre des sommets:");
      scanf(" %d", &g.n);
      printf("entre les nombre d'arc:");
      scanf(" %d", &g.m);
      initGraph(&g,g.n,g.m);
      printf("entrer les arcs sous la forme:src,destination,poid\n");
      for(int i = 0; i < g.m ; i++){
        int src,des,poid;
        scanf("%d %d %d", &src, &des, &poid );
        addvertex(&g,src,des,poid);
      }
      printf("----------- les Resultats -------------\n");
      rechersucc(&g,0);
      searchPre(&g,4);

}

