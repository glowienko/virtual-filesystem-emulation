//
// Created by patrick on 27.05.18.
//

#ifndef KOD_SUPERBLOCK_H
#define KOD_SUPERBLOCK_H


class SuperBlock {

public:
//    SuperBlock(char *discName, unsigned long discSize, unsigned long blocksCount, unsigned long discFreeSpace);
    SuperBlock();
    virtual ~SuperBlock();

private:
    char discName[];
    unsigned long discSize;
    unsigned long blocksCount;
    unsigned long discFreeSpace;

public:
    const char *getDiscName() const;
    unsigned long getDiscSize() const;
    unsigned long getBlocksCount() const;
    unsigned long getDiscFreeSpace() const;
};


#endif //KOD_SUPERBLOCK_H
