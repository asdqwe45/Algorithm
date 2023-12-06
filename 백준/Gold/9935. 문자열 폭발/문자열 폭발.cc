#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;




int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str, boom;
	cin >> str >> boom;

	stack<char> s;

	string ans;
	ans.reserve(1000000);

	int strSize = str.size();
	int boomSize = boom.size();

	for (int i = 0; i < strSize; i++) {

		s.push(str[i]);

		if (str[i] == boom[boomSize - 1] && s.size() >= boomSize) {

			string temp;

			for (int i = 0; i < boomSize; i++) {
				temp += s.top();
				s.pop();
			}
			reverse(temp.begin(), temp.end());
			if (temp != boom) {
				for (int i = 0; i < boomSize; i++) {
					s.push(temp[i]);
				}
			}
		}

	}
	if (s.empty()) {
		cout << "FRULA" << endl;
	}
	else {
		while (!s.empty()) {
			ans.push_back(s.top());
			s.pop();
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}

	return 0;
}