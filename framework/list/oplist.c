/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/

#include <stdio.h>
#include "oplist.h"

int link_bidata(BiData *cell, int count){
    for(int i=HEAD; i<(TAIL); i++){
        cell[CURRENT(i)].rear = &cell[NEXT(i)];
        cell[NEXT(i)].front = &cell[CURRENT(i)];
    }
    // 초기화 - not necessory 
    cell[HEAD].front = NULL;
    cell[TAIL].rear = NULL;
    return 0;
}

int attach_controller(DLinkedList *List, BiData *bidata, int count){
    List->count = count;
    List->head = bidata;
    List->tail = bidata+(count-1);

    return 0;
} 

int attach_Datum(BiData *bidata, Datum *datum, int count){
    BiData *current = bidata;
    for(int i=0; i<count; i++){
        current->datum = datum+i;
        MOVETO_NEXT(current);
    }
    return 0;
}

int attach_DLinkedList(BiData *bidata, DLinkedList *datum, int count){
    BiData *current = bidata;
    for(int i=0; i<count; i++){
        current->datum = datum+i;
        MOVETO_NEXT(current);
    }
    return 0;
}

int patch_Datum(DLinkedList *tissue, Datum *datum){
    BiData *current = tissue->head;
    for(int i=0; i < tissue->count; i++){
        memcpy(current->datum, &datum[i], sizeof(Datum));
        MOVETO_NEXT(current);
    }
    return 0;
}

int init_buffer(DLinkedList *DList, BiData *bidata, Datum *datum, int count){    
    for(int i=HEAD; i<(TAIL); i++){
        bidata[CURRENT(i)].rear = &bidata[NEXT(i)];
        bidata[NEXT(i)].front = &bidata[CURRENT(i)];
        bidata[CURRENT(i)].datum = &datum[CURRENT(i)];
    }
    bidata[TAIL].datum = &datum[TAIL];

    bidata[HEAD].front = NULL;
    bidata[TAIL].rear = NULL;

    DList->head = &bidata[HEAD];
    DList->tail = &bidata[TAIL];

    DList->count = count;
    return 0;
}

DLinkedList * extract_dlist(DLinkedList *tissue, BiData *selected, int count){
    BiData *tail = selected;
    JUMP_NEXT(tail, count);

    tissue->head = selected;
    tissue->tail = tail;
    
    if(IS_HEAD(tissue->head)) 
        GET_NEXT(tissue->tail)->front = NULL;   
    else
        GET_NEXT(tissue->tail)->front = GET_PREV(tissue->head);
    if(IS_TAIL(tissue->tail))
        GET_PREV(tissue->head)->rear = NULL;
    else        
        GET_PREV(tissue->head)->rear = GET_NEXT(tissue->tail);
    
    return tissue;
}

// cell 의 head부터 일괄 pull out 가정
int pull_out_DLinkedList(DLinkedList *tissue, DLinkedList *cell, int count){
    if(count > cell->count) return -1;

    BiData *tail = cell->head;
    JUMP_NEXT(tail, count-1);

    tissue->head = cell->head;
    tissue->tail = tail;

    if(GET_NEXT(tail) == NULL){
        cell->head = cell->tail = NULL;
    }
    else{
        cell->head = GET_NEXT(tail);
        cell->head->front = NULL;
    }

    tissue->tail->rear = NULL;

    tissue->count = count;
    cell->count -= count;

    return 0;
}

int put_back_BiData(DLinkedList *List, BiData *selected, DLinkedList * buffer){
    BiData *element = List->extract(List, selected);
    buffer->insert(buffer, element);
    return 0;
}

// 데이터 삽입 함수 구현
int insert_bidata_prev(DLinkedList *List, BiData *element, BiData *to_element){
    // LinkedList가 비어 있을 경우
    if(List->count == 0){
        element->front=NULL, element->rear=NULL;
        List->head=element;
        List->tail=element;

        List->count++;
        return 1;
    }
    else{
        // selected 가 head 이면
        if(GET_PREV(to_element) == NULL){
            List->head = element;
        }
        else{
            to_element->front->rear = element;
        }
        element->front = to_element->front;
        element->rear = to_element;
        to_element->front = element;
    }
    List->count++;
    return 0;
}

int insert_bidata_next(DLinkedList *List, BiData *element, BiData *selected){
    // LinkedList가 비어 있을 경우
    if(List->count == 0){
        element->front=NULL, element->rear=NULL;
        List->head=element;
        List->tail=element;

        List->count++;
        return 1;
    }    
    // selected가 tail 이면
    if(GET_NEXT(selected) == NULL)
        List->tail = element;
    else
        selected->rear->front = element;

    element->front = selected;
    element->rear = selected->rear;
    selected->rear = element;    

    List->count++;
    return 0;
}

#if 0
// 데이터 추출 함수 구현
BiData * extract_bidata(DLinkedList *List, BiData *selected, int count) {
    // 데이터 추출을 수행
    if(List->count==1 || List->head==List->tail){
        List->count=0;
        return selected;
    }
 
    // selected 의 front 와 rear 를 이어준다
    if(selected != List->head) 
        selected->front->rear = selected->rear;
    else
        List->head = selected->rear; 

    if(selected != List->tail)
        selected->rear->front = selected->front;        
    else
        List->tail = selected->front;

    List->count--;
    return selected;
}
#endif