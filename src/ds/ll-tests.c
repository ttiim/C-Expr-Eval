/*
 *  Singly Linked List ADT: Basic test driver
 *
 *  Author:  Joseph Fall
 *  Date:    Feb. 9, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "gentype.h"
#include "linkedlist.h"

//----- TEST DRIVER -----
int main( )
{
   ItemType v;
   Node_t* tmp;

   LinkedList_t list = llCreate();
   assert(llIsEmpty(list));
   assert(llLength(list) == 0);
   llAppend(&list, "1");
   llAppend(&list, "2");
   llAppend(&list, "3");
   
   printf("\nList:  ");
   llPrint(list);

   assert(!llIsEmpty(list));
   assert(llLength(list) == 3);
   llPush(&list, "99");
   llPush(&list, "98");
   llPush(&list, "97");
   
   printf("\nList:  ");
   llPrint(list);
   assert(llLength(list) == 6);

   assert(strcmp(llHead(list),"97") == 0);
   v = llPop(&list);
   assert(strcmp(v,"97") == 0);

   assert(strcmp(llHead(list),"98") == 0);
   v = llPop(&list);
   assert(strcmp(v,"98") == 0);

   printf("\nList:  ");
   llPrint(list);

   llDelete(&list);
   assert(llIsEmpty(list));
   llDestroy(&list);
}
