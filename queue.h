/** @file queue.h
 *  @brief The header file for queue.c
 * 
 * This file contains all function prototypes 
 * which can be used in other .h or .c files
 * These functions consern the implementation
 * of a queue.
 * 
 *  @author Erodotos Demetriou 
 *  @bug No known bugs. 
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

// A C program to demonstrate a queue based on doubly linkedlist implementation 
#include <stdlib.h> 
#include <stdio.h> 
#include "tree.h"

/**@brief This is a struct representing a queue Node
 * 
 * There are 3 fields in this struct. 
 * (1) TREE_NODE *leaf which contains a TREE_NODE 
 * (2) struct frontier_node *next which is a pointer
 *     to the next node of the queue.
 * (3) struct frontier_node *previous which is a pointer
 *     to the previous node of the queue.
 * 
*/
typedef struct frontier_node{
   TREE_NODE *leaf;
   struct frontier_node *next;
   struct frontier_node *previous;
} FRONTIER_NODE;

/**@brief This is a struct representing a queue 
 * 
 * There are 3 fields in this struct. 
 * (1) FRONTIER_NODE *frontier_head which is a pointer
 *     showing to the head of the queue.
 * (2) FRONTIER_NODE *frontier_tail which is a pointer
 *     showing to the tail of the queue.
 * (3) int size which is a variable to store the number 
 *     of Nodes that the queue contains.
 * 
*/
typedef struct queue{ 
   FRONTIER_NODE *frontier_head;
   FRONTIER_NODE *frontier_tail;
   int size;
}QUEUE; 

/** @brief This is a function which initializes a queue.
 *        
 * This function takes as input a double pointer QUEUE 
 * and initializes the queue. More specific  it allocates
 * memory to the queue structure and initializes its fields
 * (head = NULL , tail  = NULL  , size = 0).
 * 
 *  @param QUEUE ** The queue we want to initialize.
 *  @return int. 
 */
int initQueue(QUEUE **);

/** @brief This function insert new nodes to the tail of the queue.
 *        
 * This function takes as input a new TREE_NODE and the queue.
 * After the required checks are completed (checking for NULL inputs),
 * then memory space is allocated for a new queue Node and its fields
 * are manipulated as it has to be. In otherwords the TREE_NODE is
 * assigned to the field leaf and fields next and previous are 
 * pointers showing to the next and previous nodes of the current node.
 * 
 *  @param TREE_NODE * Is a new instance of the puzzle (tree) we want to en enqueue.
 *  @param QUEUE * The queue we want to insert the new node.
 *  @return int. 
 */
int enqueue(TREE_NODE *, QUEUE *);

/** @brief This function removes the first node from the head of the queue.
 *        
 * This function takes as input the queue we want to perform on it a dequeue.
 * In these method memory free is implemented as well as the pointers of the 
 * queue head and nodes are manged in a way that there will be not a dangling pointer 
 * or memory leak. At last this method return a pointer to the TREE_NODE of the queueu
 * node we dequed.
 * 
 *  @param QUEUE * The queue we want to dequeue the head node.
 *  @return TREE_NODE *.s 
 */
TREE_NODE *dequeue(QUEUE *queue);

/** @brief This is a secondary function used by the developer.
 * 
 * This method takes as input a queue and the size of the puzzle 
 * and call other functions in order to print the puzzle instance
 * which represents each node in the queue. This function IS NOT
 * used for the solution of the program. It is USED ONLY for 
 * DEBUGGING PERPOSES of the developer.
 *  
 *  @param QUEUE * The queue we want to print
 *  @return int. 
 */
int printQueue(QUEUE *, int );

int insertSorted(TREE_NODE *, QUEUE *);

/** @brief This function insert (sorted) new nodes to the queue.
 *        
 * This function takes as input a new TREE_NODE and the queue.
 * After the required checks are completed (checking for NULL inputs),
 * then memory space is allocated for a new queue Node and its fields
 * are manipulated as it has to be. In otherwords the TREE_NODE is
 * assigned to the field leaf and fields next and previous are 
 * pointers showing to the next and previous nodes of the current node.
 * NOTE : This method is special and can insert nodes sorted according to 
 *        the field h of the TREE_NODE
 * 
 *  @param TREE_NODE * Is a new instance of the puzzle (tree) we want to en enqueue.
 *  @param QUEUE * The queue we want to insert the new node.
 *  @return int. 
 */
int insertSorted_H(TREE_NODE *, QUEUE *);

/** @brief This function insert (sorted) new nodes to the queue.
 *        
 * This function takes as input a new TREE_NODE and the queue.
 * After the required checks are completed (checking for NULL inputs),
 * then memory space is allocated for a new queue Node and its fields
 * are manipulated as it has to be. In otherwords the TREE_NODE is
 * assigned to the field leaf and fields next and previous are 
 * pointers showing to the next and previous nodes of the current node.
 * NOTE : This method is special and can insert nodes sorted according to 
 *        the field g of the TREE_NODE
 * 
 *  @param TREE_NODE * Is a new instance of the puzzle (tree) we want to en enqueue.
 *  @param QUEUE * The queue we want to insert the new node.
 *  @return int. 
 */
int insertSorted_G(TREE_NODE *, QUEUE *);

#endif
