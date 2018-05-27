//
// Created by patrick on 27.05.18.
//

#ifndef KOD_SUPERBLOCK_H
#define KOD_SUPERBLOCK_H


class SuperBlock {

public:
    SuperBlock(char *discName, unsigned long discSize, unsigned long blocksCount, unsigned long discFreeSpace);
    virtual ~SuperBlock();

private:
    char discName[];
public:
    const char *getDiscName() const;
    unsigned long getDiscSize() const;
    unsigned long getBlocksCount() const;
    unsigned long getDiscFreeSpace() const;
private:
    unsigned long discSize;
    unsigned long blocksCount;
    unsigned long discFreeSpace;
};


#endif //KOD_SUPERBLOCK_H
