#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H
#include <string>

using namespace std;

/**
 * ���Ͽ��� ���ڿ��� �������� �� �ڿ� ������ ���� �������༭ compare�� ����� �� ����.
 * �̸� �����ϴ� �Լ�
 * @param str1
 * @param str2
 * @return same => true
 */
bool stringCompare(const string &str1, const string &str2);

/**
 * ���� compare �Լ��� ������ return type�� bool�� ����.
 * @param str1
 * @param str2
 * @return same => true
 */
bool hardStringCompare(const string &str1, const string &str2);

string& leftTrim(string& str, string chars);
string& rightTrim(string& str, string chars);
string& trimString(string& str, string chars);

#endif //PROJECT_UTILS_H
