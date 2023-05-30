#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H
#include <string>

using namespace std;

/**
 * 파일에서 문자열을 가져오면 맨 뒤에 공백이 같이 가져와줘서 compare를 사용할 수 없음.
 * 이를 보완하는 함수
 * @param str1
 * @param str2
 * @return same => true
 */
bool stringCompare(const string &str1, const string &str2);

/**
 * 기존 compare 함수와 같지만 return type을 bool로 만듬.
 * @param str1
 * @param str2
 * @return same => true
 */
bool hardStringCompare(const string &str1, const string &str2);

string& leftTrim(string& str, string chars);
string& rightTrim(string& str, string chars);
string& trimString(string& str, string chars);

#endif //PROJECT_UTILS_H
