#include "ParagraphTypePractice.h"


ParagraphTypePractice::ParagraphTypePractice(User user) : Practice(user) {

}

ParagraphTypePractice::~ParagraphTypePractice() {

}

void ParagraphTypePractice::longScriptPractice() {
    int select;
    vector<string> titles;
    vector<string> script;
    titles = paragraphManager.getInfo(2);
    cout << "�� ���� ����ּ���: ";
    cin >> select;
    paragraphManager.fOpen(titles[select], 2, ios_base::in);
    script = paragraphManager.read();
    paragraphManager.fClose();
    typePractice(script);
}

void ParagraphTypePractice::shortScriptPractice() {
    int select;
    vector<string> titles;
    vector<string> script;
    titles = paragraphManager.getInfo(1);
    cout << "ª�� ���� ����ּ���: ";
    cin >> select;
    paragraphManager.fOpen(titles[select-1], 1, ios_base::in);
    script = paragraphManager.read();
    paragraphManager.fClose();
    typePractice(script);
}

void ParagraphTypePractice::createScriptGPT() {
    fflush(stdin);
    string inputStr;
    string title;

    cout << "����� ���� ���� ������ �Է����ּ���(�����): ";
    getline(cin, title);

    inputStr = "Write a very short novel(10 sentences) about "+title;

    cout << "����: " << title << "\n";
    vector<string> lines = requestGpt(inputStr);
    for (int i = 0; i < lines.size(); ++i) {
        cout << lines[i] << "\n";
    }
    paragraphManager.create(lines, title);
}

vector<string> ParagraphTypePractice::requestGpt(string title) {
    openai::OpenAI openai_instance{"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"};
    vector<string> result;
    string resultStr;
    nlohmann::json inputStr = R"({
            "model": "gpt-3.5-turbo",
            "messages":[{"role":"user", "content":"title"}],
            "max_tokens": 300,
            "temperature": 1
    })"_json;

    inputStr["messages"][0]["content"] = title;
    //cout << inputStr["messages"][0]["content"];

    // You can try catch API method if an error occur
    try {
        auto chat = openai_instance.chat.create(inputStr);
        //std::cout << "Response is:\n" << chat["choices"][0]["message"]["content"] << '\n';
        resultStr = chat["choices"][0]["message"]["content"].get<std::string>();
        fflush(stdin);

        result = parseSentences(resultStr);
    }
    catch(std::exception const& e) {
        std::cerr << "Exception:" <<  e.what() << "\n\n";
    }

    return result;
}
vector<string> parseSentences(string &target){
    // ���ڿ��� ��Ʈ������ ��ȯ
    stringstream ss(target);
    string line;
    vector<string> lines;

    // ���� ����('\n')�� �������� ���ڿ� �ڸ���
    while (std::getline(ss, line, '.')) {
        trimString(line, " ");
        lines.push_back(line);
    }

    return lines;
}
