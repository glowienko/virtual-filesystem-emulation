#include "SuperBlock.h"

SuperBlock::SuperBlock(char *discName, unsigned long discSize, unsigned long blocksCount, unsigned long discFreeSpace)
        : discName(discName), discSize(discSize), blocksCount(blocksCount), discFreeSpace(discFreeSpace) {}

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
