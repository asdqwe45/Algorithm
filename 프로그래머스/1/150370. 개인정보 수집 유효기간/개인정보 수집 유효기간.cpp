#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<char, int> um;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    for (int i = 0; i < terms.size(); i++) {
        stringstream ss(terms[i]);
        char c;
        int month;
        ss >> c >> month;
        um[c] = month;
    }

    int todayYear = stoi(today.substr(0, 4));
    int todayMonth = stoi(today.substr(5, 2));
    int todayDay = stoi(today.substr(8));

    int todaySum = (todayYear * 12 + todayMonth - 1) * 28 + todayDay;

    for (int i = 0; i < privacies.size(); i++) {
        char ch = privacies[i].back();

        int year = stoi(privacies[i].substr(0, 4));
        int month = stoi(privacies[i].substr(5, 2));
        int day = stoi(privacies[i].substr(8, 2));

        int comSum = (year * 12 + month - 1 + um[ch]) * 28 + day - 1;

        if (comSum < todaySum)
            answer.push_back(i + 1);

    }

    return answer;
}
