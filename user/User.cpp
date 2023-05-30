#include "User.h"

const string &User::getId() const {
    return id;
}

int User::getAccuracyRate() const {
    return accuracyRate;
}

int User::getTypoRate() const {
    return typoRate;
}

void User::setId(const string &id) {
    User::id = id;
}

int User::getPracticeCnt() const {
    return practiceCnt;
}

void User::setPracticeCnt(int practiceCnt) {
    User::practiceCnt = practiceCnt;
}

void User::setAccuracyRate(int accuracyRate) {
    User::accuracyRate = accuracyRate;
}

const string &User::getPw() const {
    return pw;
}

void User::setPw(const string &pw) {
    User::pw = pw;
}

void User::setTypoRate(int typoRate) {
    User::typoRate = typoRate;
}

User::User(const string &id, int accuracyRate, int typoRate) : id(id), accuracyRate(accuracyRate), typoRate(typoRate) {}

User::~User() {

}

User::User() {

}
