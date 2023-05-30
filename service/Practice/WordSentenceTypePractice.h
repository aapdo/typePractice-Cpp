#ifndef PROJECT_WORDSENTENCETYPEPRACTICE_H
#define PROJECT_WORDSENTENCETYPEPRACTICE_H


#include <string>
#include "../../scriptManage/manager/ScriptManager.h"
#include "../record/Recorder.h"
#include "../Practice.h"

using namespace std;

class WordSentencePractice : public Practice{
private:
    ScriptManager scriptManager;
public:
    WordSentencePractice(User user);
    void wordPractice();
    void sentencePractice();
    void add(string, int);
    void update(string, string, int);
    void erase(string, int);

};


#endif //PROJECT_WORDSENTENCETYPEPRACTICE_H
