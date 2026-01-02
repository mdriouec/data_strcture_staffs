#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
void bfs(int adj[MAX][MAX], int numVertex, int startvertex){
      bool visiter[MAX] = {false};
      int file[MAX];
      int front = -1,rear = -1;
      file[++rear] = startvertex;
      visiter[startvertex] = {false};
     print("parcour BFs\n");
     while (front != rear){
        int current = file[rear++];
        printf("%d->", current);
        for(int i = 0; i < numVertex; i++){
            if(adj[current][i] == 1 && !visiter[i]){
                file[++front] = i;
                visiter[i] = true
            }
        }
     }
     printf("End\n");

}