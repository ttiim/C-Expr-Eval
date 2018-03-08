/*
 *  Generic Queue ADT: private implementation
 *
 *  Author:  Joseph Fall
 *  Date:    Mar. 1, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "queue.h"

Queue_t qCreate()
{
   return llCreate();
}

void qDestroy(Queue_t* q)
{
   llDestroy(q);
}

void qPrint(const Queue_t q)
{
   llPrint(q);
}

bool qIsEmpty(const Queue_t q)
{
   return llIsEmpty(q);
}

void qClear(Queue_t* q)
{
   llDelete(q);
}

int qLength(const Queue_t q)
{
   return llLength(q);
}

void qEnqueue(Queue_t* q, ItemType value)
{
   llAppend(q, value);
}

ItemType qFront(const Queue_t q)
{
   return llHead(q);
}

ItemType qDequeue(Queue_t* q)
{
   return llPop(q);
}

