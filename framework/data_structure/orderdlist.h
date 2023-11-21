#include "dlist.h"


typedef struct OrderDLinkedList_ {
    int count;
 
    DLinkedList *List;
    BiData *head, *tail; 

    // 데이터 Instance 생성 함수
    struct OrderDLinkedList_ * (*create)(struct OrderDLinkedList_ *ptototype, int count);

    // 메모리 할당 해제
    void (*destory)(struct OrderDLinkedList_ *cell);

    // // DLinkedList *List 를 반드시 초기화 되어야 함
    // int (*setlist)(DLinkedList *List);

} OrderDLinkedList;


void init_OrderDLinkedList(OrderDLinkedList *dna);
OrderDLinkedList * duplicate_order_dlist(OrderDLinkedList *ptototype, int count);
void destory_order_dlist(OrderDLinkedList *cell);
