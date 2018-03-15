/* 
*   Capilano University
*   Comp 220- Professor Jospeph Fall
*   Authour: Tim Wriglesworth
*   Worked in collaboration 
*   Date: 08.02.18
    Lab 7
*   
    
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h> 

#include "istack.h"

// helper functions prototypes

Node2_t* Node2Create(int value) ;
Node2_t* findPriorNode2(IntStack_t* stack, Node2_t* cursor);
void stackInsertAfter( IntStack_t* stack, Node2_t* cursor, int value);
void stackLinkAfter(IntStack_t* stack, Node2_t* cursor, Node2_t* NewNode2);

/*
*Helper functions

*/


/*
* initialize a Node2 pointing to NULL 
*/

Node2_t* Node2Create(int value) 
{
    Node2_t* Node2 = malloc(sizeof(Node2_t));
    Node2->data = value;
    Node2->next = NULL;
    return Node2;
}
/*
* print the actual Node2 data value 
*/
void Node2Print(Node2_t Node2) 
{
    printf("[%d]  %s\n", Node2.data, Node2.next ? " " : "\n --|");
}


/*
*  receives pointer to the given Node2 and then inserts a Node2 after it. 
*/
void stackInsertAfter( IntStack_t* stack, Node2_t* cursor, int value)  
{
	Node2_t* NewNode2 =Node2Create(value);
    stackLinkAfter(stack,cursor,NewNode2);	
}

/*
* link in after at specified Node2 
*/
void stackLinkAfter(IntStack_t* stack, Node2_t* cursor, Node2_t* NewNode2)
{
  NewNode2->next = cursor->next;
  cursor->next = NewNode2;
	

}

//list functions--------------------------------



/*
 * Constructor - return a new, empty stack 
 * POST: istackIsEmpty(stack)
 */
IntStack_t istackCreate( )
{
   
   Node2_t* dummy= Node2Create(INT_MIN);
   IntStack_t stack= {dummy};
   return stack;

}


/*
 * Destructor - empty stack and free all associated memory
 */
 void istackDestroy( IntStack_t *stack )
 {
     
     while (stack->head->next != NULL) 
	 {
		 istackPop(stack);
		 }
}
 

/*
 * Print a text representation of this stack on STDOUT
 */
void istackPrint( IntStack_t stack  )
{
  Node2_t* cur = stack.head->next; 
  printf("\nList:\n  ");
  
  while (cur != NULL) 
  {
	  Node2Print(*cur);
      cur = cur->next;
	  }
	  
	  printf("\n\n");
    
}

/*
 * Return true iff the stack is empty
 */
bool istackIsEmpty( IntStack_t stack )
{
    return stack.head->next == NULL;
    
}

/*
 * Return true iff the stack is full
 */
bool istackIsFull( IntStack_t stack );    //leave this alone


/*
 * Examine the item at the top of the stack
 * PRE: ! istackIsEmpty( stack )
 */
int istackTop( IntStack_t stack )
{
    assert(!istackIsEmpty(stack));
    return stack.head->next->data;
    
}

/*
 * Pop the item from the top of the stack 
 * PRE: ! istackIsEmpty( stack )
 */
int istackPop( IntStack_t *stack )
{
  int value;
  if(istackIsEmpty(*stack))
  {
      printf("\nSTACK UNDERFLOW");
      
  }
     else
     {
         //assert(!istackIsEmpty(*stack));
         Node2_t* Node2 = stack->head->next;
         stack->head->next=Node2->next;
          value = Node2->data;
         free(Node2);
          
      }
      return value; 
    
}

/*
 * Push given item on the top of the stack 
 * PRE: ! istackIsFull( stack )
 * POST: istackTop( stack ) == item
 */
int istackPush( IntStack_t *stack, int item)
{
    
    Node2_t* newNode2 = Node2Create(item);
   
	stackInsertAfter(stack,stack->head,item);
	
}

