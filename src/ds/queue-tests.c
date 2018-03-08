/*
 *  Generic Queue ADT: Basic test driver 
 *
 *  Author:  Joseph Fall
 *  Date:    Feb. 9, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "queue.h"

//----- TEST DRIVER -----
int main( )
{
   ItemType v;
   Node_t* tmp;

   Queue_t q = qCreate();
   assert(qIsEmpty(q));
   assert(qLength(q) == 0);
   qEnqueue(&q, "1");
   qEnqueue(&q, "2");
   qEnqueue(&q, "3");

   printf("\nQueue:  ");
   qPrint(q);

   assert(!qIsEmpty(q));
   assert(qLength(q) == 3);

   qDequeue(&q);
   assert(qLength(q) == 2);

   qEnqueue(&q, "99");
   qEnqueue(&q, "98");
   qEnqueue(&q, "97");

   printf("\nQueue:  ");
   qPrint(q);

   assert(qLength(q) == 5);

   assert(strcmp(qFront(q),"2") == 0);
   v = qDequeue(&q);
   assert(strcmp(v,"2") == 0);

   assert(strcmp(qFront(q),"3") == 0);
   v = qDequeue(&q);
   assert(strcmp(v,"3") == 0);

   printf("\nQueue:  ");
   qPrint(q);

   qClear(&q);
   assert(qIsEmpty(q));
   qDestroy(&q);
}
