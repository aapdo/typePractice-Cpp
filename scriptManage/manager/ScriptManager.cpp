//
// Created by 임준영 on 2023/05/10.
//

#include "ScriptManager.h"
#include "../../lib/utils.h"

ScriptManager::ScriptManager(string fileName, const ios_base::openmode mode) : FileControllInterface("../scriptManage/scriptFile/" + fileName, mode) {
}
ScriptManager::~ScriptManager() {
}
void ScriptManager::create(string inputStr) {
    if (this->handler.eof()) {
        cout << "eof";
    }
    handler << inputStr << "\n";
    handler.clear();
}

vector<string> ScriptManager::read() {
    string readStr;
    while (getline(handler, readStr)) {
        this->data.push_back(readStr);
    }
    handler.clear();
    return data;
}

void ScriptManager::update(string from, string to) {
    string check;
    string newContents = "";
    while(getline(handler, check)) {
        //입력 받은 문자열과 파일 내 문자열이 같지 않을 때 그대로 추가
        //참이면 같음
        if (stringCompare(check, from)) {
            cout << "same ";
            newContents += to + "\n";
        } else {
            cout << "diff ";
            newContents += check + "\n";
        }

    }

    //파일을 닫고 초기화 시킨 후 다시 열기
    handler.close();
    handler.open(fileName, ios_base::out);
    handler.clear();
    //파일에 새로운 내용을 넣는다.
    handler << newContents;
    //파일 포인터 초기화 후 함수 종료
    handler.clear();
}

void ScriptManager::erase(string data) {
    string check;
    string newContents;
    while(getline(handler, check)) {
        //입력 받은 문자열과 파일 내 문자열이 같지 않을 때에만 한줄 씩 추가
        if (!stringCompare(check, data)) {
            newContents += check + "\n";
        }
    }

    //파일을 닫고 초기화 시킨 후 다시 열기
    handler.close();
    handler.clear();
    handler.open(fileName, ios_base::out);
    //파일에 새로운 내용을 넣는다.
    handler << newContents;
    //파일 포인터 초기화 후 함수 종료
    handler.clear();
}

const vector<string> &ScriptManager::getData() {
    return data;
}
void ScriptManager::printVector() {
    for (int i = 0; i < data.size(); ++i) {
        cout << data[i] << " ";
    }
    cout << "\n";
}

ScriptManager::ScriptManager(){
    url = "../scriptManage/scriptFile/";
}

void ScriptManager::fOpen(const string &fileName, const ios_base::openmode __mode) {
    FileControllInterface::fOpen(this->url + fileName, __mode);
}
