#ifndef PROJECT_SCRIPTMANAGER_H
#define PROJECT_SCRIPTMANAGER_H


#include "../../lib/FileControllInterface.h"

using namespace std;

class ScriptManager : public FileControllInterface{
private:
    string url;
public:
    ScriptManager();
    ScriptManager(string fileName, const ios_base::openmode mode);
    ~ScriptManager();
    void create(string);
    vector<string> read();
    void update(string from, string to);
    void erase(string data);
    const vector<string> &getData();
    void printVector();
    void fOpen(const string&, const ios_base::openmode __mode);
};


#endif //PROJECT_SCRIPTMANAGER_H
