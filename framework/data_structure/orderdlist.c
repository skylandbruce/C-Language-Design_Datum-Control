/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/

#include "orderdlist.h"

void init_OrderDLinkedList(OrderDLinkedList *dna){
    dna->count =0;
    dna->head = NULL;
    dna->tail = NULL;
    dna->List = NULL;
    dna->create = duplicate_order_dlist;
    dna->destory = destory_order_dlist;
}

OrderDLinkedList * duplicate_order_dlist(OrderDLinkedList *ptototype, int count){
    OrderDLinkedList * cell;
    cell = (OrderDLinkedList *)malloc(sizeof(OrderDLinkedList) * count);
    return cell;
}

void destory_order_dlist(OrderDLinkedList *cell){
    free(cell);
}

