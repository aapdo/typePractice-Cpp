//
// Created by 임준영 on 2023/05/10.
//

#ifndef PROJECT_FILECONTROLLINTERFACE_H
#define PROJECT_FILECONTROLLINTERFACE_H
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class FileControllInterface {
protected:
    fstream handler;
    vector<string> data;
    ios_base::openmode mode;
    string fileName;

public:
    FileControllInterface();
    FileControllInterface(const string&, const ios_base::openmode __mode);
    // ios_base::openmode __mode = ios_base::in | ios_base::out
    ~FileControllInterface();
    void fOpen(const string&, const ios_base::openmode __mode);
    void fClose();
};


#endif //PROJECT_FILECONTROLLINTERFACE_H
