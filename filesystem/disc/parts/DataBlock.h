

#ifndef KOD_DATABLOCK_H
#define KOD_DATABLOCK_H


class DataBlock {

    unsigned long size;
    char data[];
    long nextBlock;
};


#endif //KOD_DATABLOCK_H
