#include "SuperBlock.h"

SuperBlock::SuperBlock() = default;

const char *SuperBlock::getDiscName() const {
    return discName;
}

unsigned long SuperBlock::getDiscSize() const {
    return discSize;
}

unsigned long SuperBlock::getBlocksCount() const {
    return blocksCount;
}

unsigned long SuperBlock::getDiscFreeSpace() const {
    return discFreeSpace;
}

SuperBlock::~SuperBlock() = default;
