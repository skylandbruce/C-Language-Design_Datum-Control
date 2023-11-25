/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/


#include "utill_sort.h"
#include "..\utill\utill.h"
#include "..\list\oplist.h"

#define SET_ASCEND \
    init_insert_prev()

#define SET_DESEND \
    init_insert_next()

int compare_Datum_value(const Datum *selected, const Datum *target);
int compare_Datum_name(const Datum *selected, const Datum *target);


int (*issort)(DLinkedList *DList, int (*compare)(void *selected, void *target));
int issort_DLinkedList(DLinkedList *DList, int (*compare)(void *selected, void *target));

int (*insert)(DLinkedList *List, BiData *selected, BiData *element);

void init_insert_prev();
void init_insert_next();

