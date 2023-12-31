/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/

#include "datum.h"

#define NEW     0x00000001
#define UPDATED 0x00000010
#define DELETED 0x00000100
#define NOTUSED 0x00001000
#define DIRTY   0x00001111

#define HEAD 0
#define TAIL count-1
#define IS_HEAD(selected) selected->front == NULL  
#define IS_TAIL(selected) selected->rear == NULL  

// DLinkedList, BiData Operation 
#define CURRENT(i) i
#define NEXT(i) i+1
#define TAIL count-1

#define GET_NEXT(selected) (selected->rear)
#define GET_PREV(selected) (selected->front)
#define MOVETO_NEXT(selected) ((selected) = (selected)->rear)
#define MOVETO_PREV(selected) ((selected) = (selected)->front)

#define JUMP_NEXT(element, step) \
    for(int i=0; i<step; i++) MOVETO_NEXT(element);
#define JUMP_PREV(element, step) \
    for(int i=0; i<step; i++) MOVETO_PREV(element);

#ifndef DLIST_H
#define DLIST_H

// BiData 구조체 정의
typedef struct BiData_ {
    struct BiData_ *front;
    // Datum *datum;
    void *datum;
    struct BiData_ *rear;

    struct BiData_ *(*create)(struct BiData_ *prototype, int count);
    void (*destory)(struct BiData_ *cell);    
} BiData;

// BiLinkedList 구조체 정의
typedef struct DLinkedList_ {
    long count;
    int state;
    BiData *head, *tail;

    // 데이터 Instance 생성 함수
    struct DLinkedList_ * (*create)(struct DLinkedList_ *ptototype, int count);

    // 메모리 할당 해제
    void (*destory)(struct DLinkedList_ *cell);

    // 데이터 업데이트 함수
    void (*update)(BiData *selected, Datum *datum);

    // 데이터 삽입 함수
    int (*insert)(struct DLinkedList_ *List, BiData *element);

    // 데이터 추출 함수
    BiData * (*extract)(struct DLinkedList_ *List, BiData *selected);

} DLinkedList;
#endif

void init_BiData(BiData *dna);
BiData * duplicate_bidata(BiData *prototype, int count);
void destory_bidata(BiData *cell);


void init_DLinkedList(DLinkedList *dna);
DLinkedList * duplicate_dlist(DLinkedList *prototype, int count);
void destory_dlist(DLinkedList *cell);


void update_bidata(BiData *selected, Datum *datum);

int insert_head(DLinkedList *List, BiData *element);

int insert_tail(DLinkedList *List, BiData *element);
