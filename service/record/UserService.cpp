#include <sstream>
#include "UserService.h"
#include "../../lib/utils.h"

UserService::UserService() {

}

UserService::~UserService() {

}

bool UserService::login(User &user) {
    string id;
    string pw;
    cout << "============ login! ==============\n";
    cout << "id: ";
    cin >> id;
    cout << "pw: ";
    cin >> pw;

    string readStr;
    string checkId;
    string checkPw;
    int accuracyRate;
    int typoRate;
    int practiceCnt;

    stringstream *ss;
    fOpen("../user/user_data.txt", ios_base::in);
    while (getline(handler, readStr)) {
        ss = new stringstream(readStr);
        *ss >> checkId;

        if (hardStringCompare(checkId, id)) {
            *ss >> checkPw;
            if (hardStringCompare(checkPw, pw)) {
                *ss >> accuracyRate;
                *ss >> typoRate;
                *ss >> practiceCnt;

                user.setId(checkId);
                user.setPw(checkPw);
                user.setAccuracyRate(accuracyRate);
                user.setTypoRate(typoRate);
                user.setPracticeCnt(practiceCnt);

                return true;
            }
        }
        delete ss;
    }
    fClose();
    return false;
}

void UserService::signUp() {
    string id;
    string pw;

    fOpen("../user/user_data.txt", ios_base::out | ios_base::app);
    cout << "============ sign up! ==============\n";
    cout << "id�� �Է��ϼ���: ";
    cin >> id;
    cout << "��й�ȣ�� �Է��ϼ���: ";
    cin >> pw;

    handler << id << " " << pw << " " << 0 << " " << 0 << "\n";
    fClose();
    cout << "\n";
}

void UserService::record(User user, pair<double, double> accuracy){
    string newContents;
    string readStr;
    string checkId;
    string tmp;

    stringstream *ss;
    fOpen("../user/user_data.txt", ios_base::in);
    while (getline(handler, readStr)) {
        ss = new stringstream(readStr);
        *ss >> checkId;
        //������ �� ������ ����.
        if (!hardStringCompare(checkId, user.getId())) {
            newContents += readStr + "\n";
        } else { //�ٸ��� ������ ��Ȯ�� ��Ÿ���� ������Ʈ�Ѵ�.
            user.setAccuracyRate( (user.getAccuracyRate()*user.getPracticeCnt() + accuracy.first) / (user.getPracticeCnt()+1) );
            user.setTypoRate((user.getTypoRate()*user.getPracticeCnt() + accuracy.second) / (user.getPracticeCnt()+1) );
            user.setPracticeCnt(user.getPracticeCnt() + 1);
        }
    }
    fClose();
    newContents += user.getId() + " " + user.getPw() + " " + to_string(user.getAccuracyRate()) + " " + to_string(user.getTypoRate()) + " " +
            to_string(user.getPracticeCnt()) + "\n";
    fOpen("../user/user_data.txt", ios_base::out);
    handler << newContents;
    fClose();
}


void UserService::showRecord(User user) {
    cout << "���̵�: " << user.getId();
    cout << " ��Ȯ��: " << user.getAccuracyRate();
    cout << " ��Ÿ��: " << user.getTypoRate();
    cout << "\n";
}
