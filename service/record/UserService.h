#ifndef PROJECT_USERSERVICE_H
#define PROJECT_USERSERVICE_H


#include "../../lib/FileControllInterface.h"
#include "../../user/User.h"
#include <algorithm>

class UserService : public FileControllInterface{
public:
    UserService();
    ~UserService();
    bool login(User &user);
    void signUp();
    void record(User user, pair<double, double>);

    void showRecord();

    void showMyRecord(User user);

};

bool compareByAccuracyRate(const User& a, const User& b);


#endif //PROJECT_USERSERVICE_H
