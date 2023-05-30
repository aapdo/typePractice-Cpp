#include "WordSentenceTypePractice.h"

//�ܾ ����� ���� ��� Ÿ�� ���� ����
void WordSentencePractice::wordPractice() {
    vector<string> words;
    scriptManager.fOpen("words.txt", ios_base::in);
    words = scriptManager.read();
    typePractice(words);
    scriptManager.fClose();
    cout << "\n\n";
}

//������ ����� ���� ��� Ÿ�� ���� ����
void WordSentencePractice::sentencePractice() {
    vector<string> sentences;
    scriptManager.fOpen("sentences.txt", ios_base::in);
    sentences = scriptManager.read();
    typePractice(sentences);
    scriptManager.fClose();
    cout << "\n\n";
}

void WordSentencePractice::add(string data, int mode) {
    if (mode == 1) {
        scriptManager.fOpen("words.txt", ios_base::out | ios_base::app);
    } else if (mode == 2) {
        scriptManager.fOpen("sentences.txt", ios_base::out | ios_base::app);
    }
    scriptManager.create(data);
    scriptManager.fClose();
    cout << "\n\n";
}

void WordSentencePractice::update(string from, string to, int mode) {
    if (mode == 1) {
        scriptManager.fOpen("words.txt", ios_base::in);
    } else if (mode == 2) {
        scriptManager.fOpen("sentences.txt", ios_base::in);
    }
    scriptManager.update(from, to);
    scriptManager.fClose();
}

void WordSentencePractice::erase(string data, int mode) {
    if (mode == 1) {
        scriptManager.fOpen("words.txt", ios_base::in);
    } else if (mode == 2) {
        scriptManager.fOpen("sentences.txt", ios_base::in);
    }
    scriptManager.erase(data);
    scriptManager.fClose();
}


WordSentencePractice::WordSentencePractice(User user) : Practice(user) {
}

