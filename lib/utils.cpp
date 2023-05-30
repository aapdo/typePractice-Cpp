#include "utils.h"

/**
 *
 * @param str1
 * @param str2
 * @return -1: diff, 1: same
 */
bool stringCompare(const string &str1, const string &str2){
    int str1Len = str1.size();
    int str2Len = str2.size();

    //���̰� -1 0 1 �� �ϳ�������.
    if ( !(str1Len - str2Len < 2 && str1Len - str2Len > -2) ){
        return false;
    }

    //�� �� ���̰� ª�������� ���ؼ� �ٸ��� ����� -1
    if (str1Len > str2Len) {
        for (int i = 0; i < str2Len; ++i) {
            if (str1[i] != str2[i]) {
                return false;
            }
        }
    } else {
        for (int i = 0; i < str1Len; ++i) {
            if (str1[i] != str2[i]) {
                return false;
            }
        }
    }

    return true;
}

bool hardStringCompare(const string &str1, const string &str2) {
    if (str1.size() != str2.size()) {
        return false;
    }

    int str1Len = str1.size();

    for (int i = 0; i < str1Len; ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}
string& leftTrim(string& str, string chars)
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

string& rightTrim(string& str, string chars)
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

string& trimString(string& str, string chars)
{
    return leftTrim(rightTrim(str, chars), chars);
}