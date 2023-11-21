/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/


#include "..\data_structure\dlist.h"
#include "..\utill\utill.h"

#define HEAD 0
#define TAIL count-1
#define IS_HEAD(selected) selected->front == NULL  
#define IS_TAIL(selected) selected->rear == NULL  


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


// // 데이터 정렬 함수 정의
// int (*sort)(OrderDLinkedList *OrderList, BiData *head, BiData *tail, int count, int (*compare)(Datum *selected, Datum *target));

// // 데이터 검색 함수 정의
// int (*search)(OrderDLinkedList *OrderList, Datum *datum, int count, int (*compare)(Datum *selected, Datum *target));


int init_buffer(DLinkedList *DList, BiData *bidata, void *datum, int count);

int pull_out_DLinkedList(DLinkedList *tissue, DLinkedList *cell, int count);

int put_back_BiData(DLinkedList *List, BiData *selected, DLinkedList * cell);

int patch_Datum(DLinkedList *tissue, Datum *datum);

int link_bidata(BiData *cell, int count);
int attach_controller(DLinkedList *List, BiData *bidata, int count);

int attach_Datum(BiData *bidata, Datum *datum, int count);
int attach_DLinkedList(BiData *bidata, DLinkedList *datum, int count);


