/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Nado
 *
 * Created on 7. Mai 2017, 16:16
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/*
 * 
 */
int main(int argc, char** argv) {
//   
//    //TODO achtung , falls zuviele Werte eingebeben werden
//    intstack_t firststack; 
//    firststack.size = 1000;
//    stackInit(&firststack);
////  //  stackGetBack(4,&firststack);
////    
//// //   printf("&d",firststack.stack[10]);
//        stackPush(&firststack, 100);
//        stackPush(&firststack, 20);
//        printf("%d \n", stackTop(&firststack));
//        
//        stackPop(&firststack);
//        printf("%d", stackTop(&firststack));
//        //   
//        //  printf("%d",stackGetBack(0,&firststack));
//    for(int i = 0; i < 50; i++){
//        stackPush(&firststack, i);
//    }
//    
//    stackPrint(&firststack);
//    
    
    intstack_t stack;
    
	stackInit(&stack);
	fprintf(stderr, "%s", "Stack overfloww!\n");
        
	stackPush(&stack, 1);
	stackPush(&stack, 2);
	stackPush(&stack, 3);
	printf("%d \n",!stackIsEmpty(&stack));
//	while (!stackIsEmpty(&stack))
//		printf("%i\n", stackPop(&stack));
        int i = 0;
        while(i< 100000){
            stackPush(&stack,i);
            i++;
        }
	stackPop(&stack);
	stackPrint(&stack);
	stackRelease(&stack);
        
        stackPop(&stack);stackPop(&stack);
        stackPop(&stack);
    
    return (EXIT_SUCCESS);
}

