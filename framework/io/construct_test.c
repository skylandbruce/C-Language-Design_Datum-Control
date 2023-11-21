/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/


#include "construct_test.h"
#include <time.h>
#include <stdio.h>
// #include <stdio.h>
// #include <stdlib.h>

/*
int construct_DLinkedList_manual(DLinkedList *List, int count){
    int array_manual[] = {3, 0, 0, 7, 7, 7, 8, 3, 3, 5};
    // int array_manual[] = {3, 0, 0, 3, 3, 3, 3, 3, 3, 3};
    Datum new_datum;
    BiData *bidata;
    BiData *current = List->head;
    for(int i=0; i<count; i++){
        sprintf(new_datum.name, "name_%d", array_manual[i]);
        new_datum.value = array_manual[i];

        bidata=List->create(&new_datum);  
        List->insert(current, bidata);
        current = bidata; 
    }
    return 0;
}

int construct_DLinkedList_serial(DLinkedList *List, int count, int order){
    printf("create datum\n\n");
    Datum new_datum;
    BiData *bidata;
    BiData *current;
    for(int i=0; i<count; i++){
        sprintf(new_datum.name, "%d_name ", i);
        new_datum.value=i;

        bidata=List->create(&new_datum);  
        List->insert(current, bidata);
        current = bidata; 
    }
    return 0;
}

int construct_DLinkedList_random(DLinkedList *List, int count, int order){
    printf("create datum\n\n");
    Datum new_datum;
    BiData *bidata;
    BiData *current;

    srand(time(NULL));

    for(int i=0; i<count; i++){
        int randomNum = rand() % MAX_ENTRY;
        sprintf(new_datum.name, "%d_name ", randomNum);
        new_datum.value=randomNum;
        bidata=List->create(&new_datum);  

        List->insert(current, bidata);
        current = bidata; 
    }
    return 0;
}
*/

// int construct_datum(Datum *cell, int count){
//     srand(time(NULL));
//     for(int i=0; i<count; i++){
//         cell[i].value=random()%count;
//         sprintf(cell[i].name, "%d_name ", cell[i].value);
//     }
//     return 0;
// }


int construct_datum(Datum *cell, int count){
    // srand(time(NULL));
    for(int i=0; i<count; i++){
        // cell[i].value = (int)random() % MAX_NUM_RANDOM;
        cell[i].value = rand() % MAX_NUM_RANDOM;
        sprintf(cell[i].name, "%d_name ", cell[i].value);
    }
    return 0;
}
