/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/


#include <stddef.h>
#include "process_test.h"
#include "..\list\oplist.h"

int process_test(DLinkedList *tissue, DLinkedList *buffer){
    BiData *current = tissue->head;
    Datum *datum;
    BiData *next = NULL;
    int count = tissue->count;

    for(int i=0; i<count; i++){
        datum = (Datum *)(current->datum);
        datum->value -= rand() % MAX_DECLINE_NUM;

        if(datum->value <= 0){
            next = GET_NEXT(current);
            put_back_BiData(tissue, current, buffer);
            current = next;
        }else{
            MOVETO_NEXT(current);
        }
    }
    return 0;
}