/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/

#include "datum.h"

Datum * duplicate_datum(Datum *prototype, int count){
    Datum * cell;
    cell = (Datum *)malloc(sizeof(Datum) * count);
    // cell = (Datum *)calloc(count, sizeof(Datum));
    for(int i=0; i<count; i++){
        memcpy(cell+i, prototype, sizeof(Datum));
    }
    return cell;
}

void destory_datum(Datum *cell){
    free(cell);
}

void init_Datum(Datum *dna){
    // memcpy(dna->name, "_name\0", sizeof(char));
    strcpy(dna->name, "_name");
    dna->value = 0;
    dna->create = duplicate_datum;
    dna->destory = destory_datum;
}


