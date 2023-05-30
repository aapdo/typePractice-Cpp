#include "Practice.h"

void Practice::typePractice(vector<string> strings){
    int len = strings.size();
    string inputStr;
    clock_t curTime;
    pair<double, double> recordData;
    bool flag;

    recorder.init(len);
    recorder.startTimer();
    fflush(stdin);
    cout << "\n\n";

    for (int i = 0; i < len; ++i) {
        cout << strings[i] << "\n";

        getline(cin, inputStr);
        curTime = recorder.getTimeNow();

        //q�� ������ ����
        if (inputStr.compare("Q") == 0 || inputStr.compare("q") == 0) {
            break;
        }
        if (strings[i].size() < 2) {
            continue;
        }

        if (stringCompare(inputStr, strings[i])) {
            flag = true;
        } else {
            flag = false;
        }
        recorder.setRecordData(flag);
        recordData = recorder.getRecordData();
        cout << "\n��� �ð�: " << curTime << "�� ��Ȯ��: " << (int)recordData.first << "% ��Ÿ��: " << (int)recordData.second << "%\n\n";
    }
    recorder.record(user);

    cout << "\n\n";
}

Practice::Practice(User user) {
    this->user = user;
}

Practice::~Practice() {

}
