#include <array>
#include <iostream>
#include <algorithm>
#include "FileSystem.h"

using namespace std;

FileSystem::FileSystem() {
    VirtualDisc virtualDisc;
}

FileSystem::~FileSystem() = default;

void FileSystem::showDiscStatistics() {
    cout << "statistics of disc" << endl;
}

void FileSystem::showDirectory() {
    cout << "in show current directory" << endl;
}

void FileSystem::deleteFile(char *name) {

}

void FileSystem::deleteDisc() {

}

void FileSystem::saveFileOnDisc(char *name) {

}

void FileSystem::createDisc(char *discName, long blocksNumber, long blockSize) {
    cout << "Virtual disc created, name:" << discName;
}

void FileSystem::copyFileToSystemDisc(char *name) {

}