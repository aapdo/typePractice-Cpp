#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#include <string>
using namespace std;

class User{
private:
    string id;
    string pw;
    int accuracyRate;
    int typoRate;
    int practiceCnt;
public:
    User(const string &id, int accuracyRate, int typoRate);
    User();
    User(const string &id, const string &pw, int accuracyRate, int typoRate, int practiceCnt);

    ~User();
    const string &getId() const;
    void setId(const string &id);

    int getAccuracyRate() const;
    void setAccuracyRate(int accuracyRate);

    int getTypoRate() const;
    void setTypoRate(int typoRate);

    int getPracticeCnt() const;
    void setPracticeCnt(int practiceCnt);

    const string &getPw() const;
    void setPw(const string &pw);
};


#endif //PROJECT_USER_H
