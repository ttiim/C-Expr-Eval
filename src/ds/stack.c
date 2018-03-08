/*
 *  Generic Stack ADT: private implementation
 *
 *  Author:  Joseph Fall
 *  Date:    Mar. 1, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "stack.h"

Stack_t stackCreate()
{
   return llCreate();
}

void stackDestroy(Stack_t* stack)
{
   llDestroy(stack);
}

void stackPrint(const Stack_t stack)
{
   llPrint(stack);
}

bool stackIsEmpty(const Stack_t stack)
{
   return llIsEmpty(stack);
}

void stackPopAll(Stack_t* stack)
{
   llDelete(stack);
}

int stackSize(const Stack_t stack)
{
   return llLength(stack);
}

void stackPush(Stack_t* stack, ItemType value)
{
   llPush(stack, value);
}

ItemType stackTop(const Stack_t stack)
{
   return llHead(stack);
}

ItemType stackPop(Stack_t* stack)
{
   return llPop(stack);
}

