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

/* helper functions prototypes*/

Node_t* nodeCreate(int value) ;
Node_t* findPriorNode(IntStack_t* stack, Node_t* cursor);
void llInsertAfter( IntStack_t* stack, Node_t* cursor, int value);
void llLinkAfter(IntStack_t* stack, Node_t* cursor, Node_t* NewNode);

/*

*Helper functions
*
*

*/
/*
* initialize a node pointing to NULL 
*/

Node_t* nodeCreate(int value) 
{
    Node_t* node = malloc(sizeof(Node_t));
    node->data = value;
    node->next = NULL;
    return node;
}
/*
* print the actual node data value 
*/
void nodePrint(Node_t node) 
{
    printf("[%d]%s\n", node.data, node.next ? "" : "\nbottom");
}


/*
*  receives pointer to the given node and then inserts a node after it. 
*/
void llInsertAfter( IntStack_t* stack, Node_t* cursor, int value)  
{
	Node_t* NewNode =nodeCreate(value);
	llLinkAfter(stack,cursor,NewNode);	
}

/*
* link in after at specified node 
*/
void llLinkAfter(IntStack_t* stack, Node_t* cursor, Node_t* NewNode)
{
  NewNode->next = cursor->next;
  cursor->next = NewNode;
	

}

//list functions--------------------------------



/*
 * Constructor - return a new, empty stack 
 * POST: istackIsEmpty(stack)
 */
IntStack_t istackCreate( )
{
   
   Node_t* dummy= nodeCreate(INT_MIN);
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
     Node_t* cur = stack.head->next; 
  printf("\nList:\n  ");
  
  while (cur != NULL) 
  {
	  nodePrint(*cur);
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
   assert(!istackIsEmpty(*stack));
   Node_t* node = stack->head->next;
  stack->head->next=node->next;
   
   int value = node->data;
   free(node);
	   
 return value; 
    
}

/*
 * Push given item on the top of the stack 
 * PRE: ! istackIsFull( stack )
 * POST: istackTop( stack ) == item
 */
int istackPush( IntStack_t *stack, int item)
{
    
    Node_t* newNode = nodeCreate(item);
   
	llInsertAfter(stack,stack->head,item);
	
 
    
    
}

