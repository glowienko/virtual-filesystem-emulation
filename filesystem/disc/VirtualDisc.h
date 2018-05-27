#ifndef KOD_VIRTUALDISC_H
#define KOD_VIRTUALDISC_H


#include <cstdio>
#include "./parts/SuperBlock.h"
#include "parts/SuperBlock.h"
#include "parts/FileDescriptor.h"
#include "parts/DataBlock.h"

class VirtualDisc {

private:
    FILE* disc;
    SuperBlock superBlock; //general info about disc and data blocks in the whole disc

    FileDescriptor fileDescriptors[];   // info about file in every block
    short blocksOccupationTable[];      // 1 - block is taken, 0- block is free

    DataBlock dataBlocksTable[];        // all blocks in disc
    short dataBlocksOccupationTable[];  // 1 - block has data, 0 - no data

    bool isCreated;

public:
    VirtualDisc();
    virtual ~VirtualDisc();
};


#endif //KOD_VIRTUALDISC_H
