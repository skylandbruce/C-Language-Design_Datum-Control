/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/


#include "..\data_structure\dlist.h"
#include "..\utill\utill.h"

#define MAX_BUFFER 56
#define MAX_TISSUE 7


// // 데이터 정렬 함수 정의
// int (*sort)(OrderDLinkedList *OrderList, BiData *head, BiData *tail, int count, int (*compare)(Datum *selected, Datum *target));

// // 데이터 검색 함수 정의
// int (*search)(OrderDLinkedList *OrderList, Datum *datum, int count, int (*compare)(Datum *selected, Datum *target));


int init_buffer(DLinkedList *DList, BiData *bidata, Datum *datum, int count);

int pull_out_DLinkedList(DLinkedList *tissue, DLinkedList *cell, int count);

int put_back_BiData(DLinkedList *List, BiData *selected, DLinkedList * cell);

int patch_Datum(DLinkedList *tissue, Datum *datum);

int link_bidata(BiData *cell, int count);
int attach_controller(DLinkedList *List, BiData *bidata, int count);

int attach_Datum(BiData *bidata, Datum *datum, int count);
int attach_DLinkedList(BiData *bidata, DLinkedList *datum, int count);

int insert_bidata_prev(DLinkedList *List, BiData *selected, BiData *element);
int insert_bidata_next(DLinkedList *List, BiData *selected, BiData *element);


