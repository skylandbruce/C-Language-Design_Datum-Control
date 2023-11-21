/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/

#include <stddef.h>
#include "dlist.h"
#include "..\list\oplist.h"

BiData * duplicate_bidata(BiData *prototype, int count){
    BiData * cell;
    cell = (BiData *)malloc(sizeof(BiData) * count);
    // cell = (BiData *)calloc(count, sizeof(BiData));
    for(int i=0; i<count; i++) memcpy(cell+i, prototype, sizeof(BiData));
    return cell;
}

void destory_bidata(BiData *cell){
    free(cell);
}

DLinkedList * duplicate_dlist(DLinkedList *prototype, int count){
    DLinkedList * cell;
    cell = (DLinkedList *)malloc(sizeof(DLinkedList) * count);
    // cell = (DLinkedList *)calloc(count, sizeof(DLinkedList));
    for(int i=0; i<count; i++) memcpy(cell+i, prototype, sizeof(DLinkedList));
    return cell;
}

void destory_dlist(DLinkedList *cell){
    free(cell);
}

void init_BiData(BiData *dna){
    dna->datum = NULL;
    dna->front = NULL;
    dna->rear = NULL;
    dna->create = duplicate_bidata;
    dna->destory = destory_bidata;
}

// 리스트 업데이트 함수 구현
void update_bidata(BiData *selected, Datum *datum) {
    // 데이터 업데이트를 수행
    memcpy(selected->datum, datum, sizeof(Datum));
    return;
}

// 데이터 삽입 함수 구현
int insert_head(DLinkedList *List, BiData *element) {
    // LinkedList가 비어 있을 경우
    if(List->count == 0){
        element->front=NULL, element->rear=NULL;
        List->head=element;
        List->tail=element;

        List->count++;
        return 1;
    }
    else{
        element->front = NULL;
        element->rear = List->head;
        List->head->front = element;
        List->head = element;

        List->count++;
    }
    return 0;
}

int insert_tail(DLinkedList *List, BiData *element) {
    // LinkedList가 비어 있을 경우
    if(List->count == 0){
        element->front=NULL, element->rear=NULL;
        List->head=element;
        List->tail=element;

        List->count++;
        return 1;
    }
    else {    
    element->front = List->tail;
    element->rear = NULL;
    List->tail->rear = element;  
    List->tail = element;  

    List->count++;
    }
    return 0;
}

// 데이터 추출 함수 구현
BiData * extract_bidata(DLinkedList *List, BiData *selected) {
    // selected 의 front 와 rear 를 이어준다
    if(selected == List->head) 
        List->head = selected->rear; 
    else
        selected->front->rear = selected->rear;

    if(selected == List->tail)
        List->tail = selected->front;
    else
        selected->rear->front = selected->front;        

    List->count--;
    return selected;
}


void init_DLinkedList(DLinkedList *dna){
    dna->count =0;
    dna->state = 0;
    dna->head = NULL;
    dna->tail = NULL;

    dna->create = duplicate_dlist;
    dna->destory = destory_dlist;

    dna->update = update_bidata;
    dna->insert = insert_tail;
    dna->extract = extract_bidata;
}


