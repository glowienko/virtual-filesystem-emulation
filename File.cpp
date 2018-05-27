#include "File.h"


unsigned long File::getSize() const {
    return size;
}

unsigned long File::getStartIndex() const {
    return startIndex;
}

const char *File::getName() const {
    return name;
}
