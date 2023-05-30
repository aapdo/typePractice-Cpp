#include "ParagraphManager.h"

ParagraphManager::ParagraphManager() {
    shortUrl = "../scriptManage/shortScriptFile/";
    longUrl = "../scriptManage/longScriptFile/";
}

ParagraphManager::~ParagraphManager() {

}

void ParagraphManager::create(vector<string> strings, string title) {
    setInfo(title);
    fOpen(title, 1, ios_base::out | ios_base::app);

    if (this->handler.eof()) {
        cout << "eof";
    }
    int len = strings.size();
    for (int i = 0; i < len; ++i) {
        handler << strings[i] << "\n";
    }
    handler.clear();

    fClose();
}

vector<string> ParagraphManager::read() {
    string readStr;
    while (getline(handler, readStr)) {
        this->data.push_back(readStr);
    }
    handler.clear();
    return data;
}

/**
 *
 * @param type 1 -> short 2-> long
 */
vector<string> ParagraphManager::getInfo(int type) {
    string readStr;
    vector<string> titles;
    fOpen("fileInfo.txt", type, ios_base::in);
    int i = 0;
    cout << "TITLES\n";
    while (getline(handler, readStr)) {
        i++;
        cout << i << ": " << readStr << "\n";
        titles.push_back(readStr);
    }
    fClose();
    return titles;
}
void ParagraphManager::setInfo(string title) {
    fOpen("fileInfo.txt", 1, ios_base::out | ios_base::app);

    handler << title << "\n";

    fClose();
}
/**
 *
 * @param fileName
 * @param type 1 => short 2=> long
 * @param __mode
 */
void ParagraphManager::fOpen(const string &fileName, int type, const ios_base::openmode __mode) {
    string url;
    if (type == 1) {
        url = shortUrl;
    } else {
        url = longUrl;
    }
    FileControllInterface::fOpen(url + fileName, __mode);
}