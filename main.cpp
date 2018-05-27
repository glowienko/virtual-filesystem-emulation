#include <iostream>
#include <cstring>
#include "filesystem/FileSystem.h"


#define DATA_BLOCK_SIZE 2048 //ilosc danych w jednym bloku pamieci
#define BLOCK_COUNT 8192 //ilosc blokow pamieci

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

void printMenu();

void clearString(const char *charArray);
using namespace std;

int main() {
    FileSystem fileSystem;

    int menuAction;
    bool continueWorking = true;

    while (continueWorking) {
        char filename[64];
        char discName[64];

        printMenu();
        cin >> menuAction;
        switch (menuAction) {
            case menuOption(CREATE_DISC):
                cout << "Enter virtual disc name:" << endl;
                cin >> discName;

                fileSystem.createDisc(discName, BLOCK_COUNT, DATA_BLOCK_SIZE);
                clearString(discName);
                break;
            case menuOption(DELETE_DISC):
                fileSystem.deleteDisc();
                break;
            case menuOption(SAVE_FILE_TO_DISC):
                cout << "Enter filename:"<<endl;
                cin >> filename;

                fileSystem.saveFileOnDisc(filename);
                clearString(filename);
                break;
            case menuOption(COPY_FILE_TO_SYSTEM):
                cout << "Enter the file name:"<<endl;
                cin >> filename;

                fileSystem.copyFileToSystemDisc(filename);
                clearString(filename);
                break;
            case menuOption(DELETE_FILE):
                cout << "Enter filename you wish to delete:" << endl;
                cin >> filename;

                fileSystem.deleteFile(filename);
                clearString(filename);
                break;
            case menuOption(SHOW_DIR):
                fileSystem.showDirectory();
                break;
            case menuOption(SHOW_DISC_STATS):
                fileSystem.showDiscStatistics();
                break;
            case menuOption(EXIT):
                cout << "Bye, bye!" << endl;
                continueWorking = false;
                break;
            default:
                cout << "Enter a valid option!\n";
        }
    }

    return 0;
}

void clearString(const char *charArray) {
    memset((void *) charArray, 0, sizeof charArray);
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


/*
 * //                cin.clear();
//                fflush(stdin);
//                f1.create_file(name, content);
 *
    cout << "Enter file name\n";
                cin >> name;
                c = f1.show_file_content(name);
                if (c != NULL)
                    cout << c;
                break;
            case 3:
                cout << "Enter file name\n";
                cin >> name;
                c = f1.search_file(name);
                if (c != NULL)
                    cout << c;
                break;
            case 4:
                cout << "Enter the file name\n";
                cin >> name;
                cout << "Enter the keyword to be searched\n";
                cin >> keyword;
                f1.search_keyword(name, keyword);
                break;
            case 5:
                cout << "Enter the name of new file\n";
                cin >> name;
                cout << "Enter the content of the file\n";
                cin.clear();
                fflush(stdin);
                cin.getline(content, sizeof(content));
                f1.create_file(name, content);
                break;
            case 6:
                cout << "Enter the name of the file to be deleted\n";
                cin >> name;
                f1.delete_file(name);
                break;
            case 7:
                cout << "Exiting, bye!"<<endl;
                continueWorking = false;
                break;
            default:
                cout << "Enter a valid option!\n";
 * */