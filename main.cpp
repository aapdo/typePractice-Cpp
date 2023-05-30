#include <iostream>
#include "service/Practice/WordSentenceTypePractice.h"
#include "service/Practice/ParagraphTypePractice.h"
#include "user/User.h"
#include "service/record/UserService.h"
#include "game/Game.h"

void cudWordSentence(WordSentencePractice &wordSentencePractice, string &tmp1, string &tmp2, int mode);

using namespace std;

int main() {

    UserService userService;
    Game game;

    int select;
    int select2;
    string tmp1;
    string tmp2;

    User user;

    cout << "ȸ���̽Ű���?(y or n)";
    cin >> tmp1;
    while (1) {
        if (tmp1 == "y" || tmp1 == "Y" || tmp1 == "Yes" || tmp1 == "yes") {
            break;
        }else if (tmp1 == "n" || tmp1 == "N" || tmp1 == "No" || tmp1 == "no") {
            userService.signUp();
            break;
        }
    }

    cout << "\n";

    while (1){
        if (userService.login(user)) {
            cout << user.getId() << "�� ȯ���մϴ�!\n";
            break;
        } else {
            cout << "���̵� �Ǵ� ��й�ȣ�� Ʋ�Ƚ��ϴ�!\n";
        }
    }

    cout << "\n\n";

    WordSentencePractice wordSentencePractice(user);
    ParagraphTypePractice paragraphTypePractice(user);

    while (true) {
        cout << "0. ���α׷� ����\n";
        cout << "1. �ܾ� �߰�, ����, ����\n";
        cout << "2. ���� �߰�, ����, ����\n";
        cout << "3. ���ο� �� �����ϱ�\n";
        cout << "4. �ܾ� �Ǵ� ���� Ÿ�� ����\n";
        cout << "5. �� �� �Ǵ� ª�� �� ����\n";
        cout << "6. �̷� ã�� Ÿ�� ����\n";
        cout << "7. �� ��� Ȯ��\n";
        cout << "8. ��ŷ Ȯ��\n";
        cout << "�Է�: ";
        cin >> select;

        cout << "\n";

        switch (select) {
            case 0:
                cout << "���α׷� ����\n";
                exit(1);

            case 1:
                cout << "1. �ܾ� �߰�\n";
                cout << "2. �ܾ� ����\n";
                cout << "3. �ܾ� ����\n";
                cout << "�Է�: ";
                cudWordSentence(wordSentencePractice, tmp1, tmp2, 1);
                break;

            case 2:
                cout << "1. ���� �߰�\n";
                cout << "2. ���� ����\n";
                cout << "3. ���� ����\n";
                cout << "�Է�: ";
                cudWordSentence(wordSentencePractice, tmp1, tmp2, 2);
                break;

            case 3:
                paragraphTypePractice.createScriptGPT();
                break;

            case 4:
                cout << "1. �ܾ� Ÿ�� ����\n";
                cout << "2. ���� Ÿ�� ����\n";
                cout << "�Է�: ";
                cin >> select2;
                if (select2 == 1) {
                    wordSentencePractice.wordPractice();
                } else {
                    wordSentencePractice.sentencePractice();
                }
                break;

            case 5:
                cout << "1. ª�� �� Ÿ�� ����\n";
                cout << "2. �� �� Ÿ�� ����\n";
                cout << "�Է�: ";
                cin >> select2;
                if (select2 == 1) {
                    paragraphTypePractice.shortScriptPractice();
                } else {
                    paragraphTypePractice.longScriptPractice();
                }
                break;
            case 6://�̷� ã��
                cout << "���̵� ����(1~3): ";
                cin >> select2;
                game.gameStart(select2);
                break;
            case 7:
                userService.showMyRecord(user);
            case 8://��� Ȯ��
                userService.showRecord();
                break;
        }
        cout << "\n";
    }



    return 0;
}

//mode = 1 => word
//mode = 2 => sentence
void cudWordSentence(WordSentencePractice &wordSentencePractice, string &tmp1, string &tmp2, int mode) {
    int select2;
    cin >> select2;
    fflush(stdin);
    switch (select2) {
        case 1:
            cout << "�߰��� ���ڿ� �Է�: ";
            cin >> tmp1;
            wordSentencePractice.add(tmp1, mode);
            break;
        case 2:
            cout << "�ٲ� ���ڿ�: ";
            cin >> tmp1;
            cout << "�������� �ٲܱ��?: ";
            cin >> tmp2;
            wordSentencePractice.update(tmp1, tmp2, mode);
            break;
        case 3:
            cout << "������ ���ڿ�: ";
            cin >> tmp1;
            wordSentencePractice.erase(tmp1, mode);
            break;
    }
}
