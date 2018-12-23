/** @file as3.c
 *  @brief This .c file that run the solver.c finctions
 *
 *  @author Erodotos Demetriou 
 *  @bug No known bugs. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "tree.h"
#include "solver.h"


int main(int argc, char *argv[]){
   
   int breadth=0;
   int best =0;
   int a_star=0;
   
   if (argc != 4){
      printf("Error In given arguments!\n");
      exit(0);	  
   }
   
   if (!strcmp("breadth",argv[1])){
	   breadth = 1;
   }else if(!strcmp("best",argv[1])){
	   best = 1;
   }else if(!strcmp("a-star",argv[1])){
	   a_star = 1;
   }else{
      printf("Error In given arguments!\n");
      exit(0);
   }   
   
   TREE_NODE *root = NULL;
   int puzzleSize;
   initTree(&root);
   char *filename = argv[2];
   char *solutionFile = argv[3];
   readFile(filename, root, &puzzleSize);

   QUEUE *q = NULL;
   initQueue(&q);  
   enqueue(root, q);

   BFS(root,q,puzzleSize,breadth,best,a_star,solutionFile);
 
   return 0;
}
