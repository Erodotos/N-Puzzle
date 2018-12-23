/** @file queue.c
 *  @brief This .c file implement all queue functions
 *
 *  @author Erodotos Demetriou 
 *  @bug No known bugs. 
 */
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "tree.h"


int initQueue(QUEUE **queue){
   *queue = (QUEUE *) malloc(sizeof(QUEUE));
   if ((*queue) == NULL) return EXIT_FAILURE;
      (*queue)->frontier_head = (*queue)->frontier_tail = NULL;
      (*queue)->size = 0;
   return EXIT_SUCCESS;
}

int enqueue(TREE_NODE *leaf, QUEUE *queue){
   FRONTIER_NODE *p = NULL;

   if (queue == NULL){ return EXIT_FAILURE; }

   p = (FRONTIER_NODE *)malloc(sizeof(FRONTIER_NODE));

   if ( p == NULL ) {
      printf("System out of memory…\n");
      return EXIT_FAILURE;
   }

   p->leaf = leaf;
   p->next = NULL;
   if (queue->size == 0)
      queue->frontier_head = queue->frontier_tail = p;
   else { 
      queue->frontier_tail->next = p;
      p->previous = queue->frontier_tail;
      queue->frontier_tail = p;
   }

   (queue->size)++;

   return EXIT_SUCCESS;
}

TREE_NODE *dequeue(QUEUE *queue){
   
   FRONTIER_NODE *p = NULL; // temp pointer used for free()
   TREE_NODE *val;
   if ((queue == NULL) || (queue->size == 0)) {
      printf("Sorry, queue is empty \n");
      return NULL;
   }

   p = queue->frontier_head;
   val = queue->frontier_head->leaf;
   queue->frontier_head = queue->frontier_head->next;

   //queue->frontier_head->previous = NULL; 

   free(p);
   (queue->size)--;

   if (queue->size == 0) {
      queue->frontier_tail = NULL;
   }
   return val;
}

int printQueue(QUEUE *q, int puzzleSize){
   
   if (q->frontier_head == NULL){
      printf("Queue is empty ! \n");
      return EXIT_SUCCESS;
   }
   FRONTIER_NODE *tmp = NULL; 
   tmp = q->frontier_head;
   while (tmp!=NULL){
      printTreeNode(&(tmp->leaf),puzzleSize);
      tmp = tmp->next;
   }
   return EXIT_SUCCESS;
}


int insertSorted_H(TREE_NODE *leaf, QUEUE *q){

   if (q == NULL){
      printf("Queue is NULL ... ERROR\n");
      return EXIT_FAILURE;
   }

   FRONTIER_NODE *p = NULL;
   p = (FRONTIER_NODE *)malloc(sizeof(FRONTIER_NODE));

   if ( p == NULL ) {
      printf("System out of memory…\n");
      return EXIT_FAILURE;
   }

   p->leaf = leaf;
   p->next = NULL;
   p->previous = NULL;
   if (q->size == 0)
      q->frontier_head = q->frontier_tail = p;
   else {
      FRONTIER_NODE *position = NULL;
      position = q->frontier_head;
      if (position->leaf->h > p->leaf->h){
         q->frontier_head = p;
         p->next = position;
         position->previous = p;
         return EXIT_SUCCESS;
      }
   
      while(position->next != NULL && position->next->leaf->h <= p->leaf->h){
         position = position->next;   
      }

      if (position->next != NULL){
         position->next->previous = p;
         p->next = position->next;
         p->previous = position;
         position->next = p;
      }else{
         p->previous=q->frontier_tail;
         q->frontier_tail->next = p;
         q->frontier_tail = p;
      }
   }

   (q->size)++;

   return EXIT_SUCCESS;

}

int insertSorted_G(TREE_NODE *leaf, QUEUE *q){

   if (q == NULL){
      printf("Queue is NULL ... ERROR\n");
      return EXIT_FAILURE;
   }

   FRONTIER_NODE *p = NULL;
   p = (FRONTIER_NODE *)malloc(sizeof(FRONTIER_NODE));

   if ( p == NULL ) {
      printf("System out of memory…\n");
      return EXIT_FAILURE;
   }

   p->leaf = leaf;
   p->next = NULL;
   p->previous = NULL;
   if (q->size == 0)
      q->frontier_head = q->frontier_tail = p;
   else {
      FRONTIER_NODE *position = NULL;
      position = q->frontier_head;
      if ((position->leaf->h + position->leaf->g) > (p->leaf->h + p->leaf->g)){
         q->frontier_head = p;
         p->next = position;
         position->previous = p;
         return EXIT_SUCCESS;
      }
   
      while(position->next != NULL && (position->next->leaf->h + position->next->leaf->g) <= (p->leaf->h + p->leaf->g)){
         position = position->next;   
      }

      if (position->next != NULL){
         position->next->previous = p;
         p->next = position->next;
         p->previous = position;
         position->next = p;
      }else{
         p->previous=q->frontier_tail;
         q->frontier_tail->next = p;
         q->frontier_tail = p;
      }
   }

   (q->size)++;

   return EXIT_SUCCESS;

}


