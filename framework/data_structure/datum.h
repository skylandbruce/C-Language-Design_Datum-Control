/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/
#include <stdio.h>

#define MAX_ENTRY_INIT 7 
#define ENTRY_SUP 12  // 3 2 2 2 1 1 1 
#define NAME_LENTH 64 

#ifndef DATUM_H
#define DATUM_H

// Datum 구조체 정의
typedef struct Datum_{ 
    char name[NAME_LENTH];
    int value;
    struct Datum_ * (*create)(struct Datum_ *prototype, int count);
    void (*destory)(struct Datum_ *cell);
} Datum;
#endif

void init_Datum(Datum *dna);
Datum * duplicate_datum(Datum *prototype, int count);
void destory_datum(Datum *cell);


