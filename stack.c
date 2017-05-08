/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 
 Made by Nado B.
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

extern int stackInit(intstack_t* self){
//default 100 // aendert sich dynamisch
   //self->intP = malloc(self->size *sizeof(int)); alte line
    self->size = 50; //default
    self->intP = malloc(self->size *sizeof(int));
   if( NULL == self->intP || self->size <= 0  ) {
      printf("Fehler bei malloc....\n");
      return 0; //False
   }
     else{
       self->currentAmount = 0;
       return 1;
   }
}


    extern void stackPush(intstack_t* self, int i){
        
        if(self->currentAmount == self->size){
            self->size *=2;
            self->intP = (int *) realloc(self->intP, self->size*sizeof(int));
                   // (int *)realloc(a->array, a->size * sizeof(int));
        }
        else{
            printf("Nicht genug Speicherplatz");
        }
        
        
        if(!(self->currentAmount<0)){
            self->intP[self->currentAmount] = i;
            self->currentAmount++;
            //Maybe besser self.intP,[++self.currentAmount];
        }
        else{
            printf("Nicht hacken!");
        }
    
}

extern int stackTop(const intstack_t* self){
    
    if(self->currentAmount>0){
        return self->intP[(self->currentAmount)-1];
    }
    else{
        return 0;
    }
}

extern int stackPop(intstack_t* self){
    
    if(self->currentAmount>=1){ //Falls kleiner, macht kein Sinn,weil kein Wert drine
        int help = self->intP[self->currentAmount-1];
        self->intP[self->currentAmount-1] = 0;
        self->currentAmount -= 1;
        return help;
    }
    else{
        printf("Stack ist leer\n");
        return 0; //false
    }
    
}

extern int stackIsEmpty(const intstack_t* self){
    
    if(self->currentAmount <= 0){
        return 1; //1 
    }
    else{
        return 0;
    }
}
    
extern void stackPrint(const intstack_t* self){
    
    int help = self->currentAmount;
    while(help != 0 || help < 0){ //Zweite Bedingung zu checken ist  etwas überflüssig aber soll nur hacking vorbeugen ;) 
        
        printf("Nummer %d ",self->intP[help]);
        help--;
    }
}
 extern void stackRelease(intstack_t* self) {
     
    // free(self);
     free(self->intP);
     self->intP = NULL;
     self->currentAmount = self->size = 0;
 }   
   
    
    
    
    



