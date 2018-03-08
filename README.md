# C-Expr-Eval
Comp220 - Stacks &amp; Queues lab:  Starter Project

## Build / Test / Execute project
 > `cd src;` `make`
   * builds the experession evaluator program
     * this will FAIL until `intStack` module is implemented
     * Usage: `eval "4 + 5 * ( x - a ) / 3"`
   * also builds the data structures library and test drivers
     * to run test drivers: `./ds/lltest`, `./ds/stacktest`, `./ds/qtest` 

## TO DO
 1. Complete the implementation for `intStack` module:
     * specify the data structue in `istack.h`
     * implement Stack operations in `istack.c`
 2. Build intStack test driver:  `cd src/intStack;` `make`
 3. Build `eval` project (see above) -- execute to see how it works
 4. In `lab7.c`, complete the function: `evalExpr(expression)`

## Package Contents
 * `src/ds` - Data Structures
   * Complete Generic List / Stack / Queue data structures, configured to handle char* tokens
   * Basic test driver for each data structure
   * ds/lib/libds.a - static data structures library
 * `src/intStack` - Integer Stack
   * Partial specification for a Stack of Integers + basic test driver
   * *Students must complete the Stack implementation*
   * Choose any implementation: static array, dynamic array, linked list, or List ADT
 * `src/lab.c` - project main
   * Partial basic algebraic expression evaluator
   * *Students must code function*: `evalExpr(expression)`
 * `src/Makefile`.c - makefile for building project
