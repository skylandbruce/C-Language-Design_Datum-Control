/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/
#include <stdio.h>
#define MAX_ENTRY_IO 20
#define ENTRY_INIT 7 // should be less than MAX_ENTRY_IO 
#define ENTRY_SUP 12  // 3 2 2 2 1 1 1 \ // should be less than MAX_ENTRY_IO

#define PATTERN_INT(amount) int pattern_##amount[amount] // *** devide ENTRY_SUP pattern **
#define SET_PATTERN_INT(name, amount) \
    int *name = pattern_##amount

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


