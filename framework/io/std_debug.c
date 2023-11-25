/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/

#include <stdio.h>
#include "std_debug.h"
#include "..\list\oplist.h"

int msg_Datum(char *msg, Datum *cell, int count){
#ifdef _DEBUG_    
    int max = (count <= ENTRY_INIT) ? count :  ENTRY_INIT;
    printf("\n === %s === \n",msg);
    for (int i = 0; i < max; i++) {
        printf("%s.value = %d\n", cell[i].name, cell[i].value);
    }
#endif    
    return 0;
}

int msg_BiData(char *msg, BiData *cell, int count){
#ifdef _DEBUG_    
    Datum *datum;
    int max = (count <= MAX_BUFFER) ? count :  MAX_BUFFER;
    printf("\n === %s === \n",msg);
    for (int i = 0; i < max; i++) {
        datum = (Datum *)((cell+i)->datum);
        printf("%s.value = %d\n", datum->name, datum->value);
    }
#endif    
    return 0;
}

int msg_DLinkedList(char *msg, DLinkedList *cell, int count){
#ifdef _DEBUG_    
    Datum *datum;
    int max = (count < cell->count && count != 0) ? count : cell->count;
    BiData *current = cell->head;
    printf("\n === %s === \n",msg);
    for (int i = 0; i < max; i++){
        datum = (Datum *)current->datum;
        printf("%s.value = %d\n", datum->name, datum->value);
        MOVETO_NEXT(current);
    }
#endif    
    return 0;
}
