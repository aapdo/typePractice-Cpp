#ifndef PROJECT_USERSERVICE_H
#define PROJECT_USERSERVICE_H


#include "../../lib/FileControllInterface.h"
#include "../../user/User.h"

class UserService : public FileControllInterface{
public:
    UserService();
    ~UserService();
    bool login(User &user);
    void signUp();
    void record(User user, pair<double, double>);

    void showRecord(User user);
};



#endif //PROJECT_USERSERVICE_H
