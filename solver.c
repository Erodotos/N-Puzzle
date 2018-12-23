/** @file solver.c
 *  @brief This .c file implement all solve functions
 * 
 *  @author Erodotos Demetriou 
 *  @bug No known bugs. 
 */
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include "tree.h"
#include "queue.h"
#include "solver.h"

int readFile(char *fileName, TREE_NODE *root, int *puzzleSize){

   FILE *fp = NULL;
   fp = fopen(fileName, "r");
   if (fp == NULL){
      printf("Error opening file!\n");
      return EXIT_FAILURE;
   }
   //I suppose that a line can not exceed 100 characters
   char lineBuffer[100];
   int lineNumber = 0;
   int numberCount = 0;

   // Create array using malloc
   root->puzzle = (int **)malloc(sizeof(int *));

   //Read file line by line using fgets
   while(fgets(lineBuffer,sizeof(lineBuffer),fp)){
      root->puzzle = (int **)realloc(root->puzzle,sizeof(int *)*(lineNumber+1));

      // Read line numbers one by one
      numberCount = 0;
      char *token = NULL;
      token = strtok(lineBuffer,"\t\n");
      int number;
      root->puzzle[lineNumber] = (int *)malloc(sizeof(int)*(numberCount+1));

      while(token!=NULL){
         number = atoi(token);
         root->puzzle[lineNumber] = (int *)realloc(root->puzzle[lineNumber],sizeof(int)*(numberCount+1));
         root->puzzle[lineNumber][numberCount++] = number;
         token = strtok(NULL,"\t\n");
      }
      lineNumber ++ ;
   }
   fclose(fp);
   if (numberCount != lineNumber){
      printf("Invalid file format. \n");
      return EXIT_FAILURE;
   }
   *puzzleSize = numberCount;
   return EXIT_SUCCESS;
}

TREE_NODE *createLeft(TREE_NODE *node, int puzzleSize){
   
   int i,j;
   int x=0;
   int y=0;
  

   for (i=0;i<puzzleSize;i++){
      for (j=0;j<puzzleSize;j++){
         if(node->puzzle[i][j] == 0){
            x=i;
            y=j;
         }
      }
   }

   TREE_NODE *newNode = NULL;

   if (y-1>=0){
 
      // Create new leaf using malloc
      newNode = (TREE_NODE *)malloc(sizeof(TREE_NODE));
      if (newNode == NULL){
         printf("System out of memory...\n");
         return NULL;
      }
      //Create a deep copy of the node's parent
      newNode->puzzle = (int **)malloc(puzzleSize*sizeof(int*));
      for (i=0;i<puzzleSize;i++){
         newNode->puzzle[i] = (int *)malloc(puzzleSize*sizeof(int));
         for (j=0;j<puzzleSize;j++){
            newNode->puzzle[i][j] = node->puzzle[i][j];
         }
      }

      //Do the swapping to left here.
      newNode->puzzle[x][y-1] = node->puzzle[x][y];
      newNode->puzzle[x][y] = node->puzzle[x][y-1];
   }

   return newNode;
   
}

TREE_NODE *createRight(TREE_NODE *node, int puzzleSize){
   int i,j;
   int x=0;
   int y=0;


   for (i=0;i<puzzleSize;i++){
      for (j=0;j<puzzleSize;j++){
         if(node->puzzle[i][j] == 0){
            x=i;
            y=j;
         }
      }
   }

   TREE_NODE *newNode = NULL;

   if (y+1 < puzzleSize){
 
      // Create new leaf using malloc
      newNode = (TREE_NODE *)malloc(sizeof(TREE_NODE));
      if (newNode == NULL){
         printf("System out of memory...\n");
         return NULL;
      }

      //Create a deep copy of the node's parent
      newNode->puzzle = (int **)malloc(puzzleSize*sizeof(int*));
      for (i=0;i<puzzleSize;i++){
         newNode->puzzle[i] = (int *)malloc(puzzleSize*sizeof(int));
         for (j=0;j<puzzleSize;j++){
            newNode->puzzle[i][j] = node->puzzle[i][j];
         }
      }

      //Do the swapping to left here.
      newNode->puzzle[x][y+1] = node->puzzle[x][y];
      newNode->puzzle[x][y] = node->puzzle[x][y+1];
   }

   return newNode;
}

TREE_NODE *createUp(TREE_NODE *node, int puzzleSize){
   int i,j;
   int x=0;
   int y=0;
   

   for (i=0;i<puzzleSize;i++){
      for (j=0;j<puzzleSize;j++){
         if(node->puzzle[i][j] == 0){
            x=i;
            y=j;
         }
      }
   }

   TREE_NODE *newNode = NULL;

   if (x-1 >= 0){
 
      // Create new leaf using malloc
      newNode = (TREE_NODE *)malloc(sizeof(TREE_NODE));
      if (newNode == NULL){
         printf("System out of memory...\n");
         return NULL;
      }

      //Create a deep copy of the node's parent
      newNode->puzzle = (int **)malloc(puzzleSize*sizeof(int*));
      for (i=0;i<puzzleSize;i++){
         newNode->puzzle[i] = (int *)malloc(puzzleSize*sizeof(int));
         for (j=0;j<puzzleSize;j++){
            newNode->puzzle[i][j] = node->puzzle[i][j];
         }
      }

      //Do the swapping to left here.
      newNode->puzzle[x-1][y] = node->puzzle[x][y];
      newNode->puzzle[x][y] = node->puzzle[x-1][y];
   }
   return newNode;
}


TREE_NODE *createDown(TREE_NODE *node, int puzzleSize){
   int i,j;
   int x=0;
   int y=0;
 

   for (i=0;i<puzzleSize;i++){
      for (j=0;j<puzzleSize;j++){
         if(node->puzzle[i][j] == 0){
            x=i;
            y=j;
         }
      }
   }

   TREE_NODE *newNode = NULL;

   if (x+1 < puzzleSize){
 
      // Create new leaf using malloc
      newNode = (TREE_NODE *)malloc(sizeof(TREE_NODE));
      if (newNode == NULL){
         printf("System out of memory...\n");
         return NULL;
      }

      //Create a deep copy of the node's parent
      // here i have to check if malloc is done correct
      newNode->puzzle = (int **)malloc(puzzleSize*sizeof(int*));
      for (i=0;i<puzzleSize;i++){
         newNode->puzzle[i] = (int *)malloc(puzzleSize*sizeof(int));
         for (j=0;j<puzzleSize;j++){
            newNode->puzzle[i][j] = node->puzzle[i][j];
         }
      }

      //Do the swapping to left here.
      newNode->puzzle[x+1][y] = node->puzzle[x][y];
      newNode->puzzle[x][y] = node->puzzle[x+1][y];
   }
   return newNode;
}

int checkAncestors(TREE_NODE * node, int puzzleSize){
   int i,j;
   TREE_NODE *temp = NULL;
   temp = node->parent;
   int isDifferent = 1;

   while((temp != NULL) && isDifferent ){
      isDifferent=0;
      for (i=0;i<puzzleSize;i++){
         for (j=0;j<puzzleSize;j++){
            if (node->puzzle[i][j] != temp->puzzle[i][j]){
               isDifferent =1;
               break;
            }  
         }
         if (isDifferent){
            break;
         }
      }
      temp = temp->parent;
   }
   //This returns false (0) in case there are duplicates
   return isDifferent;
}

int isSolved(TREE_NODE * node, int puzzleSize){
   int i,j;
   int counter = 1;
   
   for (i=0;i<puzzleSize;i++){
      for (j=0;j<puzzleSize;j++){
         if(i==puzzleSize-1 && j== puzzleSize-1){
            if (node->puzzle[i][j] == 0){
               return 1;
            }
         }else{
            if(node->puzzle[i][j] != counter){
               return 0;
            }
            counter++;
         } 
      }    
   }
   return 0;
}


int generateChildren(TREE_NODE *node, int puzzleSize){

   TREE_NODE *ch1 = createRight(node, puzzleSize); 
   TREE_NODE *ch2 = createDown(node, puzzleSize);
   TREE_NODE *ch3 = createLeft(node, puzzleSize);
   TREE_NODE *ch4 = createUp(node, puzzleSize);

   node->children[0]=ch1;
   if(node->children[0] != NULL){
      manhattan(node->children[0],puzzleSize);
      node->children[0]->parent = node;
      generate_G(node->children[0]);
      int noDuplicate = checkAncestors(node->children[0],puzzleSize);
      if (!noDuplicate)
         node->children[0] = NULL;
   }

   node->children[1] = ch2;
   if(node->children[1] != NULL){
      manhattan(node->children[1],puzzleSize); 
      node->children[1]->parent = node;
      generate_G(node->children[1]);
      int noDuplicate = checkAncestors(node->children[1],puzzleSize);
      if (!noDuplicate)
         node->children[1] = NULL;
   }
   
   node->children[2] = ch3;
   if(node->children[2] != NULL){
      manhattan(node->children[2],puzzleSize);
      node->children[2]->parent = node;
      generate_G(node->children[2]); 
      int noDuplicate = checkAncestors(node->children[2],puzzleSize);
      if (!noDuplicate)
         node->children[2] = NULL;
   }
  
   node->children[3] = ch4;
   if(node->children[3] != NULL){
      manhattan(node->children[3],puzzleSize); 
      node->children[3]->parent = node;
      generate_G(node->children[3]);
      int noDuplicate = checkAncestors(node->children[3],puzzleSize);
      if (!noDuplicate)
         node->children[3] = NULL;
   }

   return EXIT_SUCCESS;
}

void recursivePrint(TREE_NODE *node, FILE *fp, int *steps, int puzzleSize){

   if (node->parent == NULL){
      fprintf(fp,"%d\n", (*steps));
      return;
   }
   (*steps)++;
   recursivePrint(node->parent, fp, steps,puzzleSize);

   int h,i, j;
   int flag = 1;
   int path;
   for (h=0;h<4;h++){
      path = h;
      flag = 1;
      if (node->parent->children[h] == NULL){
         continue;
      }
      for (i=0;i<puzzleSize;i++){
         for(j=0;j<puzzleSize;j++){
            if (node->puzzle[i][j] != node->parent->children[h]->puzzle[i][j]){
               flag = 0;
               break;
            }
         }
         if (!flag){
            break;
         }
      }
      if (flag){
         break;
      }
   }

   switch(path) {

      case 0  :
         fprintf(fp,"%s\n", "right");
         break;
	
      case 1  :
         fprintf(fp,"%s\n", "down");
         break;
  
      case 2  :
         fprintf(fp,"%s\n", "left");
         break;

      case 3  :
         fprintf(fp,"%s\n", "up");
         break;
   
      default : 
         fprintf(fp,"%s\n", "error");
   }
  
}


int printToFile(TREE_NODE *node, char *fileName, int puzzleSize){
   if (node == NULL){
      printf("Error reading the solution Node (is NULL)\n");
      return EXIT_FAILURE;
   }
   FILE *fp = NULL;
   fp = fopen(fileName, "w");
   if (fp == NULL){
      printf("Error oppening the file\n");
      return EXIT_FAILURE;
   }
   int steps = 0;
   
   recursivePrint(node,fp,&steps,puzzleSize);
   fclose(fp);

   return EXIT_SUCCESS;
}

int manhattan(TREE_NODE *node, int puzzleSize){
   
   if (node == NULL){
      printf("Null in manhattan\n");
      return EXIT_FAILURE;
   }
   int helpArray[puzzleSize][puzzleSize];
   int manhattanSum = 0;
   int h,i,j;  
   int counter = 1;
   for (i=0;i<puzzleSize;i++){
      for (j=0;j<puzzleSize;j++){
          if (i==puzzleSize-1 && j==puzzleSize-1){
             helpArray[i][j] = 0;
             break;
          }
          helpArray[i][j] = counter++;       
      }
   }

   int x1 = 0;
   int y1 = 0;
   int x2 = 0;
   int y2 = 0;
   int breakFlag = 0;

   for (h=1;h<puzzleSize*puzzleSize;h++){
      breakFlag = 0;
      for (i=0;i<puzzleSize;i++){
         for (j=0;j<puzzleSize;j++){
            if(node->puzzle[i][j] == h){
               x1 = i;
               y1 = j;
               breakFlag = 1;  
               break; 
            }       
         }
         if (breakFlag){
            break;
         }
      }
      breakFlag = 0;
      for (i=0;i<puzzleSize;i++){
         for (j=0;j<puzzleSize;j++){
            if(helpArray[i][j] == h){
               x2 = i;
               y2 = j;
               breakFlag = 1;  
               break; 
            }       
         }
         if (breakFlag){
            break;
         }
      }
      manhattanSum+= abs(x1-x2) + abs(y1-y2);
   }
   node->h = manhattanSum;
   return EXIT_SUCCESS;
}

void generate_G(TREE_NODE* node){
   node->g = recursive_G(node);
}

int recursive_G(TREE_NODE* node){
   if (node->parent == NULL){
      return 0;
   }
   return 1 + recursive_G(node->parent);
}

int BFS(TREE_NODE* root, QUEUE *q, int puzzleSize, int breadth, int best, int a_star, char * solutionFile){

   int solutionFound;
   TREE_NODE *currentChild= NULL;

   while(1){
     
     currentChild = dequeue(q);
     solutionFound = isSolved(currentChild,puzzleSize);
     if (solutionFound){
        printToFile(currentChild,solutionFile,puzzleSize);
        break;  
     }
     generateChildren(currentChild,puzzleSize);
     int i;
     for (i=0;i<4;i++){
        if (currentChild->children[i] != NULL){
           if (breadth){
			   enqueue(currentChild->children[i],q);
		   }else if (best){
               insertSorted_H(currentChild->children[i],q);		   
		   }else if(a_star){   
		      insertSorted_G(currentChild->children[i],q);
		   }    
        }
     } 
   }

   return 0;

}

