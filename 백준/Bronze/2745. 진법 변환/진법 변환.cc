#include <iostream>
#include <cmath>
using namespace std;

string num = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
	string str;
	int N;

	cin >> str >> N;
	int result = 0;
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < N; j++) {
			if (str[str.length()-1-i] == num[j]) {
				result += pow(N, i) * j;
				break;
			}
		}
	}

	cout << result << endl;

	return 0;
}