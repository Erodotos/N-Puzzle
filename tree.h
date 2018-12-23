/** @file tree.h
 *  @brief The header file for tree.c
 *
 *  @author Erodotos Demetriou 
 *  @bug No known bugs. 
 */
#ifndef __TREE_H__
#define __TREE_H__

typedef struct tree_node{
   int ** puzzle;
   int g;
   int h;
   struct tree_node *parent;
   struct tree_node *children[4];
} TREE_NODE;

int initTree(TREE_NODE **);

int printTreeNode(TREE_NODE **, int);

#endif

