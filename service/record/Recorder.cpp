#include <utility>
#include <iostream>
#include "Recorder.h"

Recorder::Recorder(int totalLine) {
    this->totalLine = totalLine;
    this->accuracy.first = 0;
    this->accuracy.second = 0;
    this->numTrue = 0;
    this->numFalse = 0;
}

Recorder::~Recorder() {

}

void Recorder::setRecordData(bool flag) {
    typeLine++;
    if (flag) {
        ++numTrue;
        accuracy.first =  (numTrue/(double)typeLine) * 100;
    } else {
        ++numFalse;
        accuracy.second = (numFalse/(double)typeLine) * 100;
    }
}
pair<double, double> Recorder::getRecordData() {
    return accuracy;
}

void Recorder::init(int totalLine) {
    this->totalLine = totalLine;
    this->accuracy.first = 0;
    this->accuracy.second = 0;
    this->numTrue = 0;
    this->numFalse = 0;
    this->typeLine = 0;
}

void Recorder::startTimer() {
    start = chrono::system_clock::now();
}

int Recorder::getTimeNow() {
    cur = chrono::system_clock::now();
    return chrono::duration_cast<chrono::seconds>(cur - start).count();
}

void Recorder::record(User user) {
    userService.record(user, this->accuracy);
}
Recorder::Recorder() {

}


