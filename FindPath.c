//-----------------------------------------------------------------------------
// Maria Fernanda Becerra
// mfbecerr
// CSE101
// pa3
// FindPath.c
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#define INF -3
#define NIL -1
int main(int argc, char * argv[]){
   FILE *in, *out;

   // check command line for correct number of arguments
   if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }

   // open files for reading and writing 
   in = fopen(argv[1], "r");
      if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }
    out = fopen(argv[2], "w");
   if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }
   int n=0;
   fscanf(in,"%d",&n);
   Graph G=newGraph(n);
   int x=-1;
   int y=-1;
   fscanf(in,"%d",&x);
   fscanf(in,"%d",&y);
   while(x!=0 && y!=0){
      addEdge(G,x,y);
//      fprintf(out,"%d %d\n",x,y);
      fscanf(in,"%d",&x);
      fscanf(in,"%d",&y);
    }
//    fprintf(out,"out of while");
    printGraph(out,G);
    fprintf(out,"\n");
   x=-1;
   y=-1;//TO DO: Add one fscanf before while loop and then at end so we don't get error
    fscanf(in,"%d %d",&x,&y);
    while(x!=0 && y!=0){
      //fscanf(in,"%d %d",&x,&y);
      BFS(G,x);
      List P=newList();
      getPath(P,G,y);
      fprintf(out,"The distance from %d to %d is ",x,y);
      if(getDist(G,y)==INF){
        fprintf(out, "%s\n","infinity");
        fprintf(out,"No %d-%d path exists\n\n",x,y);
      }
      else{
        fprintf(out,"%d\n",getDist(G,y));
        fprintf(out,"A shortest %d-%d path is: ",x,y);
        printList(out,P);
        fprintf(out,"%s","\n\n");
      }
      freeList(&P);
      fscanf(in,"%d %d",&x,&y);
    }
    // close files 
   freeGraph(&G);
   fclose(in);
   fclose(out);

   return(0);
}
