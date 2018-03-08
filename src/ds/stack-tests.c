/*
 *  Stack ADT: Basic test driver
 *
 *  Author:  Joseph Fall
 *  Date:    Feb. 9, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "stack.h"

//----- TEST DRIVER -----
int main( )
{
   ItemType v;
   Node_t* tmp;

   Stack_t stack = stackCreate();
   assert(stackIsEmpty(stack));
   assert(stackSize(stack) == 0);
   stackPush(&stack, "1");
   stackPush(&stack, "2");
   stackPush(&stack, "3");

   printf("\nStack:  ");
   stackPrint(stack);

   assert(!stackIsEmpty(stack));
   assert(stackSize(stack) == 3);

   stackPop(&stack);
   assert(stackSize(stack) == 2);

   stackPush(&stack, "99");
   stackPush(&stack, "98");
   stackPush(&stack, "97");

   printf("\nStack:  ");
   stackPrint(stack);

   assert(stackSize(stack) == 5);

   assert(strcmp(stackTop(stack),"97") == 0);
   v = stackPop(&stack);
   assert(strcmp(v,"97") == 0);

   assert(strcmp(stackTop(stack),"98") == 0);
   v = stackPop(&stack);
   assert(strcmp(v,"98") == 0);

   printf("\nStack:  ");
   stackPrint(stack);

   stackPopAll(&stack);
   assert(stackIsEmpty(stack));
   stackDestroy(&stack);
}
