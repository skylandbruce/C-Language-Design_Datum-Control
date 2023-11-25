/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/


#include "issort.h"

int compare_Datum_value(const Datum *selected, const Datum *target){
    if(target->value < selected->value) 
        return HIGH;
    else if(selected->value < target->value)
        return LOW;
    else
        return EQU;    
}

int compare_Datum_name(const Datum *selected, const Datum *target){
    // strcmp 함수를 사용하여 두 문자열을 비교
    int result = strcmp(selected->name, target->name);

    // 비교 결과에 따라 우선순위를 반환
    if (result < 0) {
        return LOW;  // selected 가 우선순위 높음 -1
    } else if (result > 0) {
        return HIGH;   // target 가 우선순위 높음 1
    } else {
        return EQU;   // 두 문자열이 같은 우선순위 0
    }
}

void init_insert_prev(){
    insert = insert_bidata_prev;
}

void init_insert_next(){
    insert = insert_bidata_next;
}


int issort_DLinkedList(DLinkedList *DList, int (*compare)(void *selected, void *target)){
    BiData *element = DList->head;
    BiData *current = GET_NEXT(DList->head);
    BiData *current_prev;

    DLinkedList *current_DList;
    DLinkedList *element_DList;
    int result;

    for(int i=1; i<DList->count && current != NULL; i++){
        element = DList->head;

        for(int j=0; j<i; j++){
            current_DList = (DLinkedList *)(current->datum);
            element_DList = (DLinkedList *)(element->datum);

            result = compare(&(current_DList->count), &(element_DList->count));
            if(result == LOW) {
                current_prev = current;
                MOVETO_NEXT(current); // if current == NULL 일 경우 문제 
                insert(DList, DList->extract(DList, current_prev), element);
                break;
            }
            else
                MOVETO_NEXT(element);
        }
        if(result != LOW ) MOVETO_NEXT(current);
    }
    return 0;
}
