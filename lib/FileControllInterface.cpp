#include "FileControllInterface.h"

FileControllInterface::FileControllInterface() {}

FileControllInterface::FileControllInterface(const string &fileName, const ios_base::openmode mode){
    this->mode = mode;
    this->fileName = fileName;
    this->handler.open(fileName, mode);

    if (!handler.is_open()) {
        cerr << "file is not open\n";
    }
};
FileControllInterface::~FileControllInterface() {
    if (handler.is_open()) {
        this->handler.close();
    }
}

void FileControllInterface::fOpen(const string & fileName, const ios_base::openmode mode) {
    this->mode = mode;
    //this->fileName = "../scriptManage/scriptFile/"+fileName;
    this->fileName = fileName;
    this->handler.open(this->fileName, mode);
    this->handler.clear();

    if (!handler.is_open()) {
        cerr << "file is not open\n";
    }
}
void FileControllInterface::fClose() {
    handler.close();
}
