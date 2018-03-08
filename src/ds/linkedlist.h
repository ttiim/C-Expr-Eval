/**
 *  Generic Singly-Linked List ADT : public interface
 *    Node:  One Node in a linked list
 *    LinkedList: A generic singly-linked list of data defined by gentype.h
 *
 *  Author:  Joseph Fall
 *  Date:    Mar. 1, 2018
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "gentype.h"

/*******************
 * PRIVATE TYPE DECLARATIONS
 ********************/

//----- NODE -----
struct  Node {
    ItemType data;
    struct Node* next;
};
typedef struct Node Node_t;


Node_t* nodeCreate(ItemType value);
void nodePrint(Node_t node); 


//----- LINKED LIST -----
struct LinkedList {
   Node_t* head;
   Node_t* tail;
};
typedef struct LinkedList LinkedList_t;


void llLinkAfter(LinkedList_t* list, Node_t* cursor, Node_t* newNode);

Node_t* llUnlinkAfter(LinkedList_t* list, Node_t* cursor);


/*********************
 *  PUBLIC INTERFACE
 *********************/

LinkedList_t llCreate();

void llDestroy(LinkedList_t* list);

void llPrint(const LinkedList_t list);

bool llIsEmpty(const LinkedList_t list);

void llDelete(LinkedList_t* list);

int llLength(const LinkedList_t list);

void llPush(LinkedList_t* list, ItemType value);

void llAppend(LinkedList_t* list, ItemType value);

ItemType llHead(const LinkedList_t list);

ItemType llPop(LinkedList_t* list);

#endif