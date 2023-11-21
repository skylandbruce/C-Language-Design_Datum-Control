


// #define SWAP_DLIST_POINTERS(list, selected, target) \
//     swap_pointers(&(list)->selected->datum, &(list)->target->datum); \
//     swap_pointers(&(list)->selected, &(list)->target);



#define DEC_PROTO(DNA) \
    DNA dna_##DNA; \
    init_##DNA(&dna_##DNA)

#define GET_INSTANCE(DNA, count) \
    dna_##DNA.create(&dna_##DNA, count) 

#define SET_INSTANCE(DNA, name) \
    DNA name; \
    memcpy(&name, &dna_##DNA, sizeof(DNA))

#define PATCH_DATUM(pDLinkedList, pDatum, count) \
    construct_datum(pDatum, count); \
    patch_Datum(pDLinkedList, pDatum)


#define ATTACH_DATUM(DNA, bidata, datum, count) \
    attach_##DNA(bidata, datum, count)

#define COMBINE_TISSUE(DNA, tissue, bidata, datum, count) \
    link_bidata(bidata, MAX_TISSUE); \
    attach_controller(tissue, bidata, count); \
    ATTACH_DATUM(DNA, bidata, datum, count)

#define DESTORY(DNA, CELL) \
    dna_##DNA.destory(CELL)    