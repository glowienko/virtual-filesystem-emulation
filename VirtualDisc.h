#ifndef KOD_VIRTUALDISC_H
#define KOD_VIRTUALDISC_H


#include <cstdio>
#include "SuperBlock.h"

class VirtualDisc {

private:
    FILE* disc;

    SuperBlock superBlock;

    long sectors[sectorsCount][3];
    long blocks[blocksCount];

    long allocationTable[blocksCount][5];

public:
    VirtualDisc();
    virtual ~VirtualDisc();


};


#endif //KOD_VIRTUALDISC_H
