#ifndef PROJECT_PARAGRAPHTYPEPRACTICE_H
#define PROJECT_PARAGRAPHTYPEPRACTICE_H
#include "../Practice.h"
#include "../../scriptManage/manager/ParagraphManager.h"
#include "openai.hpp"

class ParagraphTypePractice : public Practice{
private:
    ParagraphManager paragraphManager;
public:
    ParagraphTypePractice(User user);
    ~ParagraphTypePractice();
    void longScriptPractice();
    void shortScriptPractice();
    void createScriptGPT();
    vector<string> requestGpt(string title);
};

vector<string> parseSentences(string &target);

#endif //PROJECT_PARAGRAPHTYPEPRACTICE_H
