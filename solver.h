/** @file solver.h
 *  @brief The header file for solver.c
 * 
 * This file contains all function prototypes 
 * which can be used in other .h or .c files
 * These functions calculate different parts
 * of the puzzle solution.
 * 
 *  @author Erodotos Demetriou 
 *  @bug No known bugs. 
 */

#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <stdlib.h> 
#include <stdio.h> 
#include "tree.h"
#include "queue.h"

/** @brief This method reads the initial state of the puzzle from a file.
 *         
 *  This functions takes as input a fileName where the initial state of
 *  the puzzle is stored. It also takes an empty int variable by reference,
 *  the puzlleSize and an initialized TREE_NODE called root. Then it reads the 
 *  initial state from the file and creates the first instance of the puzzle
 *  assining the puzzle template to the root field **puzzle. This is done using 
 *  dynamic memory allocation each time a number is read from the initial state
 *  file. At the same time while the file is read calculations for the puzzleSize
 *  are done and at the end we assign to the puzzleSize its value.
 * 
 *  @param char *fileName A string pointer which shows to the file name given.
 *  @param TREE_NODE *root The root of the puzzle instances.
 *  @param int * The size of puzzle.
 *  @return int. 
 */
int readFile(char *fileName, TREE_NODE *root, int *);

/** @brief This method generate the possible children of each TREE_NODE.
 *         
 *  This function takes as input a TREE_NODE and the puzzleSize and generates 
 *  the 4 pozzible children of the TREE_NODE. Each TREE_NODE may have 4 children,
 *  which represent its instances in case of a 0 movement. The 4 allowed movements are 
 *  Up, Down, Right, Left. If any movement can not be done then the child is going
 *  to be NULL. When the children are generated their manhattan distance and g-value
 *  are calculated and at last they are checked if they are duplicate instances of 
 *  one of their ancestors. If so, they are rejected.
 * 
 *  @param TREE_NODE * The node we want to generate its children.
 *  @param int * The size of puzzle.
 *  @return int. 
 */
int generateChildren(TREE_NODE *, int);

/** @brief This method generate the left child of a TREE_NODE.
 *         
 *  This function takes as input a TREE_NODE and the puzzleSize. 
 *  Then the position of the 0 is found (x and y coordinate). After 
 *  that we check if movement to left is allowed. (check array boundaries).
 *  Finally a deep copy of the given TREE_NODE puzzle is created and the 0 is
 *  shifted to left. The new copied node is returned. 
 * 
 *  @param TREE_NODE * The node we want to generate its left child.
 *  @param int * The size of puzzle.
 *  @return TREE_NODE*. 
 */
TREE_NODE *createLeft(TREE_NODE *, int);

/** @brief This method generate the right child of a TREE_NODE.
 *         
 *  This function takes as input a TREE_NODE and the puzzleSize. 
 *  Then the position of the 0 is found (x and y coordinate). After 
 *  that we check if movement to left is allowed. (check array boundaries).
 *  Finally a deep copy of the given TREE_NODE puzzle is created and the 0 is
 *  shifted to right. The new copied node is returned. 
 * 
 *  @param TREE_NODE * The node we want to generate its right child.
 *  @param int * The size of puzzle.
 *  @return TREE_NODE*. 
 */
TREE_NODE *createRight(TREE_NODE *, int);

/** @brief This method generate the up child of a TREE_NODE.
 *         
 *  This function takes as input a TREE_NODE and the puzzleSize. 
 *  Then the position of the 0 is found (x and y coordinate). After 
 *  that we check if movement to left is allowed. (check array boundaries).
 *  Finally a deep copy of the given TREE_NODE puzzle is created and the 0 is
 *  shifted up. The new copied node is returned. 
 * 
 *  @param TREE_NODE * The node we want to generate its up child.
 *  @param int * The size of puzzle.
 *  @return TREE_NODE*. 
 */
TREE_NODE *createUp(TREE_NODE *, int);

/** @brief This method generate the down child of a TREE_NODE.
 *         
 *  This function takes as input a TREE_NODE and the puzzleSize. 
 *  Then the position of the 0 is found (x and y coordinate). After 
 *  that we check if movement to left is allowed. (check array boundaries).
 *  Finally a deep copy of the given TREE_NODE puzzle is created and the 0 is
 *  shifted down. The new copied node is returned. 
 * 
 *  @param TREE_NODE * The node we want to generate its down child.
 *  @param int * The size of puzzle.
 *  @return TREE_NODE*. 
 */
TREE_NODE *createDown(TREE_NODE *node, int);

/** @brief This method check for any duplicate ancestors of a TREE_NODE
 *         
 *  This function takes as input a TREE_NODE* and the puzzleSize. Then 
 *  we iterate all ancestestors of the TREE_NODE* we want to check up to the 
 *  root. If any ancestestor is the same as TREE_NODE* given then the methos 
 *  returns false.
 * 
 *  @param TREE_NODE * The node we want to check its ancestors.
 *  @param int * The size of puzzle.
 *  @return int. 
 */
int checkAncestors(TREE_NODE * , int);

/** @brief This method check a solution to the puzzle is found.
 *         
 *  This function takes as input a TREE_NODE* and the puzzleSize. If the 
 *  puzzle array od the given node is correct then the function returns 
 *  true.
 * 
 *  @param TREE_NODE * The node we want to check if it is the solution.
 *  @param int * The size of puzzle.
 *  @return int. 
 */
int isSolved(TREE_NODE *, int);

/** @brief This method prints to file the movements which give you the solution.
 *         
 *  This function takes as input a TREE_NODE* , a file pointer , and int variable to store the steps and the puzzleSize.
 *  The function uses recursion to climb to the root of the puzzle. Then on its return the solution 
 *  is printed to the given file.
 *
 *  @param TREE_NODE * The node which is the solution.
 *  @param FILE * fp The node which is the solution.
 *  @param int *steps variable to store the total of movements.
 *  @param int * The size of puzzle.
 *  @return int. 
 */
void recursivePrint(TREE_NODE *node, FILE *fp, int *steps, int puzzleSize);

/** @brief An auxiliary method to trigger the recursivePrint
 *         
 *  It creates a file pointer and call recursivePrint.
 *
 *  @param TREE_NODE * The node which is the solution.
 *  @param char * The name of the file which the solution is going to be stored
 *  @param int * The size of puzzle.
 *  @return int. 
 */
int printToFile(TREE_NODE *, char *, int);

/** @brief A method that calculates the manhattan distance between 2 points.
 *         
 *  Firstly this function takes as input a TREE_NODE* and finds the actual points of 
 *  each number of the puzzle as well as the final points of each number. Then using a 
 *  formula we find the dinstance.
 *
 *  @param TREE_NODE * The node we want to find its manhattan distance
 *  @param int * The size of puzzle.
 *  @return int. 
 */
int manhattan(TREE_NODE *, int );

/** @brief This method calculate the field G of each node. 
 *
 *  This method is auxiliary and trigger an other one to make the calculation
 *  recursively.
 
 *  @param TREE_NODE * The node we want to calculate its G value
 *  @return int. 
 */
void generate_G(TREE_NODE*);

/** @brief This method calculates recursively the G value.
 *
 *  @param TREE_NODE * The node we want to calculate its G value
 *  @return int. 
 */
int recursive_G(TREE_NODE*);

/** @brief This method triggers all other methods to generate a solution.
 *
 *  @param TREE_NODE * The root of the tree.
  *  @param QUEUE * an empty queue to help find the solution
 *  @param int * The size of puzzle.
 *  @return int. 
 */
int BFS(TREE_NODE* , QUEUE *, int, int, int, int, char *);

#endif
