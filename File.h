#ifndef KOD_FILE_H
#define KOD_FILE_H

class File {
private:
    char name[64];
    unsigned long size;
    unsigned long startIndex;

public:
    const char *getName() const;
    unsigned long getSize() const;
    unsigned long getStartIndex() const;
};

#endif //KOD_FILE_H
