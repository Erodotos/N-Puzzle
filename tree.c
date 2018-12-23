/** @file tree.c
 *  @brief This .c file implement all tree functions
 *
 *  @author Erodotos Demetriou 
 *  @bug No known bugs. 
 */
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "solver.h"

int initTree(TREE_NODE **root){
   *root = (TREE_NODE *)malloc(sizeof(TREE_NODE));
   if (*root == NULL){
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}

int printTreeNode(TREE_NODE **node, int puzzleSize){
   if ((*node) == NULL){printf("NULL NODE\n"); return EXIT_FAILURE;}
   int i,j;
   for (i=0;i<puzzleSize;i++){
      printf("---");
   }
   printf("\n");

   for (i=0;i<puzzleSize;i++){
      for (j=0;j<puzzleSize;j++){
         printf(" %d  ",(*node)->puzzle[i][j]);
      }
      printf("\n");
   }
   printf("\nH + G = %d\n", /*(*node)->h +*/ (*node)->g);
   for (i=0;i<puzzleSize;i++){
      printf("---");
   }
   printf("\n");
   return EXIT_SUCCESS;
}
