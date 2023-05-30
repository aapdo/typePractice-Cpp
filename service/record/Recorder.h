#ifndef PROJECT_RECORDER_H
#define PROJECT_RECORDER_H
#include <ctime>
#include <chrono>
#include "../../user/User.h"
#include "UserService.h"

using namespace std;

class Recorder {
private:
    //시작 시간
    chrono::system_clock::time_point start;
    //현재 시간
    chrono::system_clock::time_point cur;
    //총 줄 수
    int totalLine;
    //맞춘 개수
    int numTrue;
    //틀린 개수
    int numFalse;
    int typeLine;
    //정확도, 오타율
    pair<double, double> accuracy;
    UserService userService;
public:
    Recorder(int);
    Recorder();

    ~Recorder();
    pair<double, double> getRecordData();
    void setRecordData(bool);
    void init(int);
    void startTimer();
    int getTimeNow();
    void record(User user);
};


#endif //PROJECT_RECORDER_H
