#ifndef PROJECT_PARAGRAPHMANAGER_H
#define PROJECT_PARAGRAPHMANAGER_H

#include "../../lib/FileControllInterface.h"

class ParagraphManager : public FileControllInterface{
private:
    string shortUrl;
    string longUrl;
public:
    ParagraphManager();
    ~ParagraphManager();
    void create(vector<string> strings, string);
    vector<string> read();
    vector<string> getInfo(int type);
    void setInfo(string title);
    void fOpen(const string &fileName, int type, const ios_base::openmode __mode);
};



#endif //PROJECT_PARAGRAPHMANAGER_H
