#ifndef KOD_FILESYSTEMSTRUCTS_H

#include "Constants.h"

#define KOD_FILESYSTEMSTRUCTS_H


struct SuperBlock {
    char discName[64];
    unsigned long discTotalSize;
    unsigned long discDataSize;
    unsigned long blocksCount;
};

struct FileDescriptor { //info about file in some block
    char fileName[64];
    unsigned long fileSize;
    unsigned long firstByteIndex;
    unsigned long lastByteIndex;
};

struct Block {
    char data[BLOCK_SIZE];
    long nextBlock;
};


#endif //KOD_FILESYSTEMSTRUCTS_H
