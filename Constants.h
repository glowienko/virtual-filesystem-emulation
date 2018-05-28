#ifndef KOD_CONSTANTS_H
#define KOD_CONSTANTS_H
#define BLOCK_SIZE 2048
#define BLOCK_COUNT 8192
#define DISC_NAME "disc.txt"

enum menuOption {
    CREATE_DISC = 1,
    DELETE_DISC = 2,
    SAVE_FILE_TO_DISC = 3,
    COPY_FILE_TO_SYSTEM = 4,
    DELETE_FILE = 5,
    SHOW_DIR = 6,
    SHOW_DISC_STATS = 7,
    EXIT = 8
};

#endif //KOD_CONSTANTS_H
