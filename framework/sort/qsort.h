/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/


#include "..\data_structure\orderdlist.h"

// // 데이터 정렬 함수
int (*set_pivot)(BiData *head, BiData *tail, int (*compare)(Datum *selected, Datum *target));
int (*partition)(BiData *head, BiData *tail, int count, int (*compare)(Datum *selected, Datum *target));

// int qsort(DLinkedList *DList, int (*compare)(void *selected, void *target));
