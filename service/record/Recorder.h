#ifndef PROJECT_RECORDER_H
#define PROJECT_RECORDER_H
#include <ctime>
#include <chrono>
#include "../../user/User.h"
#include "UserService.h"

using namespace std;

class Recorder {
private:
    //���� �ð�
    chrono::system_clock::time_point start;
    //���� �ð�
    chrono::system_clock::time_point cur;
    //�� �� ��
    int totalLine;
    //���� ����
    int numTrue;
    //Ʋ�� ����
    int numFalse;
    int typeLine;
    //��Ȯ��, ��Ÿ��
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
