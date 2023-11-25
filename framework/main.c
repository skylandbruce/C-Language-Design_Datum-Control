/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/

#include "main.h"

int main(){

    DEC_PROTO(Datum);
    DEC_PROTO(BiData);
    DEC_PROTO(DLinkedList);

    Datum *cell_datum_io;
    Datum *buffer_datum;
    BiData *buffer_bidata;
    DLinkedList *cell_tissue;   
    BiData *tissue_bidata;

    // 외부 Datum 입출력 
    cell_datum_io = GET_INSTANCE(Datum, MAX_ENTRY_IO);
    if(cell_datum_io == NULL) return -1;

    // 내부 Buffer Datum
    buffer_datum = GET_INSTANCE(Datum, MAX_BUFFER);
    if(buffer_datum == NULL) return -1;
    // Buffer를 연결하는 BiData
    buffer_bidata = GET_INSTANCE(BiData, MAX_BUFFER);
    if(buffer_bidata == NULL) return -1;
    
    // Buffer 자료를 가져와 분류하는 tissue 
    cell_tissue = GET_INSTANCE(DLinkedList, MAX_TISSUE);
    if(cell_tissue == NULL) return -1;

    // tissue를 연결하는 BiData
    tissue_bidata = GET_INSTANCE(BiData, MAX_TISSUE);
    if(tissue_bidata == NULL) return -1;

///////////initialize buffer////////
    // buffer 참조자
    SET_INSTANCE(DLinkedList, buffer_dlist);
    init_buffer(&buffer_dlist, buffer_bidata, buffer_datum, MAX_BUFFER);

    // tissue 참조자
    SET_INSTANCE(DLinkedList, tissue_dlist);
    COMBINE_TISSUE(DLinkedList, &tissue_dlist, tissue_bidata, cell_tissue, MAX_TISSUE);

///////////initialize tissues////////
    for(int i=0; i<MAX_TISSUE; i++){
        if(pull_out_DLinkedList(&cell_tissue[i], &buffer_dlist, ENTRY_INIT) == -1){
            printf("not enough buffer count=%d\n",buffer_dlist.count);
            return -1;
        } 
        PATCH_DATUM(&cell_tissue[i], cell_datum_io, ENTRY_INIT);
        // MSG_ARRAY(Datum)("cell_datum", cell_datum_io, ENTRY_INIT);
        // MSG_ARRAY(DLinkedList)("tissue", &cell_tissue[i], 0);
    }   

///// == work flow == [[[[[[[[[[[[[[ 
    #define MAX_LOOP 3
    SET_INSTANCE(DLinkedList, buffer_dlist_sup);

    PATTERN_INT(MAX_TISSUE) = {3,2,2,2,1,1,1};
    SET_PATTERN_INT(pattern_ENTRY_SUP, MAX_TISSUE);

    SET_ASCEND;
    issort = issort_DLinkedList;
    issort(&tissue_dlist, compare_int);    
    
    for(int j=0; j<MAX_LOOP; j++){

        // tissue 의 값을 변화 시키고, 조건에 부합하는 cell은 buffer로 돌려 놓는다
        for(int i=0; i<MAX_TISSUE; i++){
            process_test(&cell_tissue[i], &buffer_dlist);
            // MSG_ARRAY(DLinkedList)("output tissue", &cell_tissue[i], 0);
        }
        
        // buffer로 부터 bidata를 가져와서 MAX_TISSUE 크기의 tissue를 만든다
        if(pull_out_DLinkedList(&buffer_dlist_sup, &buffer_dlist, ENTRY_SUP) == -1){
            printf("not enough buffer count=%d\n",buffer_dlist.count);
            return -1;
        } 
        // buffer_dlist_sup tissue에 MAX_TISSUE 크기의 데이터(Datum)를 생성한 cell_datum_io를 patch 한다 
        PATCH_DATUM(&buffer_dlist_sup, cell_datum_io, ENTRY_SUP);
        MSG_ARRAY(DLinkedList)("tissue_sup_datum", &buffer_dlist_sup, 0);

        // 새로 생성한 데이터(BiData)를 각 tissue에 분배하여 추가한다
        BiData *current = tissue_dlist.head;
        DLinkedList *tissue;
        for(int i=0; i<tissue_dlist.count; i++){
            tissue = (DLinkedList *)current->datum;
            for(int j=0; j<pattern_ENTRY_SUP[i]; j++){
                tissue->insert(tissue, buffer_dlist_sup.extract(&buffer_dlist_sup, buffer_dlist_sup.head));
            }
            MSG_ARRAY(DLinkedList)("supplied tissue", tissue, 0);
            MOVETO_NEXT(current);
        }

        // MSG_ARRAY(BiData)("buffer BiData", buffer_bidata, MAX_BUFFER);
        // MSG_ARRAY(DLinkedList)("buffer DLinkedList", &buffer_dlist, 0);
        printf("\n buffer count = %d\n\n", buffer_dlist.count);
    } // for(j)

//// == work flow == ]]]]]]]]]]]]]]

///////////free memory////////
    DESTORY(Datum, cell_datum_io);
    DESTORY(Datum, buffer_datum);
    DESTORY(BiData, buffer_bidata);
    DESTORY(DLinkedList, cell_tissue);
    DESTORY(BiData, tissue_bidata);
}

