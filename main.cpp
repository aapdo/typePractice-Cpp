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

    cout << "회원이신가요?(y or n)";
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
            cout << user.getId() << "님 환영합니다!\n";
            break;
        } else {
            cout << "아이디 또는 비밀번호가 틀렸습니다!\n";
        }
    }

    cout << "\n\n";

    WordSentencePractice wordSentencePractice(user);
    ParagraphTypePractice paragraphTypePractice(user);

    while (true) {
        cout << "0. 프로그램 종료\n";
        cout << "1. 단어 추가, 수정, 삭제\n";
        cout << "2. 문장 추가, 수정, 삭제\n";
        cout << "3. 새로운 글 생성하기\n";
        cout << "4. 단어 또는 문장 타자 연습\n";
        cout << "5. 긴 글 또는 짧은 글 연습\n";
        cout << "6. 미로 찾기 타자 연습\n";
        cout << "7. 내 기록 확인\n";
        cout << "8. 랭킹 확인\n";
        cout << "입력: ";
        cin >> select;

        cout << "\n";

        switch (select) {
            case 0:
                cout << "프로그램 종료\n";
                exit(1);

            case 1:
                cout << "1. 단어 추가\n";
                cout << "2. 단어 수정\n";
                cout << "3. 단어 삭제\n";
                cout << "입력: ";
                cudWordSentence(wordSentencePractice, tmp1, tmp2, 1);
                break;

            case 2:
                cout << "1. 문장 추가\n";
                cout << "2. 문장 수정\n";
                cout << "3. 문장 삭제\n";
                cout << "입력: ";
                cudWordSentence(wordSentencePractice, tmp1, tmp2, 2);
                break;

            case 3:
                paragraphTypePractice.createScriptGPT();
                break;

            case 4:
                cout << "1. 단어 타자 연습\n";
                cout << "2. 문장 타자 연습\n";
                cout << "입력: ";
                cin >> select2;
                if (select2 == 1) {
                    wordSentencePractice.wordPractice();
                } else {
                    wordSentencePractice.sentencePractice();
                }
                break;

            case 5:
                cout << "1. 짧은 글 타자 연습\n";
                cout << "2. 긴 글 타자 연습\n";
                cout << "입력: ";
                cin >> select2;
                if (select2 == 1) {
                    paragraphTypePractice.shortScriptPractice();
                } else {
                    paragraphTypePractice.longScriptPractice();
                }
                break;
            case 6://미로 찾기
                cout << "난이도 선택(1~3): ";
                cin >> select2;
                game.gameStart(select2);
                break;
            case 7:
                userService.showMyRecord(user);
            case 8://기록 확인
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
            cout << "추가할 문자열 입력: ";
            cin >> tmp1;
            wordSentencePractice.add(tmp1, mode);
            break;
        case 2:
            cout << "바꿀 문자열: ";
            cin >> tmp1;
            cout << "무엇으로 바꿀까요?: ";
            cin >> tmp2;
            wordSentencePractice.update(tmp1, tmp2, mode);
            break;
        case 3:
            cout << "삭제할 문자열: ";
            cin >> tmp1;
            wordSentencePractice.erase(tmp1, mode);
            break;
    }
}
