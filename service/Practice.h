#ifndef PROJECT_PRACTICE_H
#define PROJECT_PRACTICE_H


#include <string>
#include <vector>
#include <iostream>
#include "../lib/utils.h"
#include "record/Recorder.h"
#include "../user/User.h"

using namespace std;

class Practice {
protected:
    void typePractice(vector<string>);
    Recorder recorder;
    User user;
public:
    Practice(User user);
    ~Practice();
};



#endif //PROJECT_PRACTICE_H
