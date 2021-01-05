/****************************************************************************************
* Maria Fernanda Becerra
* mfbecerr
* CSE101
* PA3
* GraphTest.c
****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"

int main(int argc, char* argv[]){
  Graph G= newGraph(5);
  printf("%d\n",getOrder(G));//should be 5
  addEdge(G,1,2);
  addEdge(G,1,3);
  addEdge(G,2,3);
  addEdge(G,2,4);
  addEdge(G,2,5);
  addEdge(G,3,4);
  addEdge(G,4,5);
  printf("%d\n",getSize(G));//should be 7
  printGraph(stdout,G);
  BFS(G,3);
  List P=newList();
  getPath(P,G,4);
  printList(stdout,P);//should be 3 1
  printf("%d\n",getDist(G,1));//should be 1
  printf("\n");
  printf("%d\n",getParent(G,5));//should be 2
  makeNull(G);
  printGraph(stdout,G);
  freeList(&P);
  freeGraph(&G);
  return(0);
}
