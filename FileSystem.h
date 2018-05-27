#ifndef KOD_FILESYSTEM_H
#define KOD_FILESYSTEM_H


#include "File.h"
#include "VirtualDisc.h"

class FileSystem {

private:
    VirtualDisc virtualDisc;


public:
    FileSystem();

    void createDisc(char *discName, long blocksNumber, long blockSize);
    void deleteDisc();
    void saveFileOnDisc(char *name);
    void copyFileToSystemDisc(char *name);
    void deleteFile(char *name);
    void showDirectory();
    void showDiscStatistics();

    virtual ~FileSystem();
};


#endif //KOD_FILESYSTEM_H
