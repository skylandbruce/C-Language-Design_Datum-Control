/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/


#include "..\data_structure\orderdlist.h"

#ifndef _DEBUG_
#define _DEBUG_

#define MSG_ARRAY(cell) msg_##cell

int msg_Datum(char *msg, Datum *cell, int count);
int msg_BiData(char *msg, BiData *cell, int count);
// count=0 is MAX
int msg_DLinkedList(char *msg, DLinkedList *cell, int count);

#endif