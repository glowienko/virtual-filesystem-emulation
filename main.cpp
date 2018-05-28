#include <iostream>
#include <cstring>
#include <sys/stat.h>
#include "FileSystemStructs.h"

using namespace std;

void createDisc(char *discName);
void deleteDisc();
void saveFileOnDisc(char *name);
void copyFileToSystemDisc(char *name);
void deleteFile(char *name);
void showDirectory();
void showDiscStatistics();

void printMenu();
void clearString(const char *charArray);
int disc_exist();
int isEmpty(FILE *file);
void saveStructureToDisc();
void initDiscStructure(const char *discName);
void loadStructureFromDisc();

FILE *disc = nullptr;
SuperBlock superBlock; //general info about disc and data blocks in the whole disc

short blocksOccupationTable[BLOCK_COUNT];      // 1 - block is taken, 0- block is free
FileDescriptor fileDescriptors[BLOCK_COUNT];   // info about file in every block
Block dataBlocksTable[BLOCK_COUNT];        // all blocks in disc
//short dataBlocksOccupationTable[BLOCK_COUNT];  // 1 - block has data, 0 - no data

int main() {
    int menuAction;
    bool continueWorking = true;

    while (continueWorking) {
        char filename[64];
        char discName[64];

        loadStructureFromDisc();

        printMenu();
        cin >> menuAction;
        switch (menuAction) {
            case menuOption(CREATE_DISC):
                cout << "Enter virtual disc name:" << endl;
                cin >> discName;
                createDisc(discName);
                clearString(discName);
                break;
            case menuOption(DELETE_DISC):
                deleteDisc();
                break;
            case menuOption(SAVE_FILE_TO_DISC):
                cout << "Enter filename:" << endl;
                cin >> filename;

                saveFileOnDisc(filename);
                clearString(filename);
                break;
            case menuOption(COPY_FILE_TO_SYSTEM):
                cout << "Enter the file name:" << endl;
                cin >> filename;

                copyFileToSystemDisc(filename);
                clearString(filename);
                break;
            case menuOption(DELETE_FILE):
                cout << "Enter filename you wish to delete:" << endl;
                cin >> filename;

                deleteFile(filename);
                clearString(filename);
                break;
            case menuOption(SHOW_DIR):
                showDirectory();
                break;
            case menuOption(SHOW_DISC_STATS):
                showDiscStatistics();
                break;
            case menuOption(EXIT):
                cout << "Bye, bye!" << endl;
                continueWorking = false;
                break;
            default:
                cout << "Enter a valid option!" << endl;
        }
    }

    return 0;
}


void createDisc(char *discName) {
    if (disc_exist()) {
        cout << "Virtual disc already exists!" << endl;
        return;
    }

    initDiscStructure(discName);
    saveStructureToDisc();
}


void deleteDisc() {
    if (!disc_exist()) {
        cout << "there is no disc yet" << endl;
        return;
    }

    remove(DISC_NAME);
    2
    cout << "Disc deleted" << endl;
}

void saveFileOnDisc(char *name) {

}

void copyFileToSystemDisc(char *name) {

}

void deleteFile(char *name) {

}

void showDirectory() {
    cout << "Disc directory:" << endl << endl;
    cout << superBlock.discName << "/root" << endl;

    for (int i = 0; i < BLOCK_COUNT; i++) {
        if (blocksOccupationTable[i] == 1) {
            cout << fileDescriptors[i].fileName << "  " << fileDescriptors[i].fileSize << " Bytes" << endl;
        }
    }
}

void showDiscStatistics() {

}

// ======================= for load / save program structures from / to disc

void initDiscStructure(const char *discName) {
    strcpy(superBlock.discName, discName);
    superBlock.blocksCount = BLOCK_COUNT;
    superBlock.discDataSize = BLOCK_COUNT * BLOCK_SIZE;
    superBlock.discTotalSize = sizeof(SuperBlock) + sizeof(short) * BLOCK_COUNT +
                               sizeof(FileDescriptor) * BLOCK_COUNT + sizeof(Block) * BLOCK_COUNT;

    for (short &i : blocksOccupationTable) {
        i = 0;
    }
}

void loadStructureFromDisc() {
    if (disc_exist()) {
        disc = fopen(DISC_NAME, "r");
        fread(&superBlock, sizeof(SuperBlock), 1, disc);
        fread(&blocksOccupationTable, sizeof(short), BLOCK_COUNT, disc);
        fread(&fileDescriptors, sizeof(FileDescriptor), BLOCK_COUNT, disc);
        fread(&dataBlocksTable, sizeof(Block), BLOCK_COUNT, disc);
        fclose(disc);
    }
}

void saveStructureToDisc() {
    disc = fopen(DISC_NAME, "w+");
    fwrite(&superBlock, sizeof(SuperBlock), 1, disc);
    fwrite(&blocksOccupationTable, sizeof(short), BLOCK_COUNT, disc);
    fwrite(&fileDescriptors, sizeof(FileDescriptor), BLOCK_COUNT, disc);
    fwrite(&dataBlocksTable, sizeof(Block), BLOCK_COUNT, disc);
    fclose(disc);
}




// ============ UTILS =====================

void clearString(const char *charArray) {
    memset((void *) charArray, 0, sizeof charArray);
}

int disc_exist() {
    struct stat buffer{};
    return (stat(DISC_NAME, &buffer) == 0);
}

int isEmpty(FILE *file) {
    long savedOffset = ftell(file);
    fseek(file, 0, SEEK_END);

    if (ftell(file) == 0) {
        return 1;
    }

    fseek(file, savedOffset, SEEK_SET);
    return 0;
}


void printMenu() {
    cout << endl << "FILESYSTEM::" << endl;
    cout << "1. Create virtual disc" << endl;
    cout << "2. Delete virtual disc" << endl;
    cout << "3. Copy file to virtual disc" << endl;
    cout << "4. Copy file to system disc" << endl;
    cout << "5. Delete file from disc" << endl;
    cout << "6. Show directory" << endl;
    cout << "7. Show disc statistics" << endl;
    cout << "8. Exit" << endl << endl;
}
