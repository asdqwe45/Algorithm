#include <iostream>
#include <string>
using namespace std;



int main() {

	string str;

	for (int i = 0; i < 100; i++) {
		int a = 0, b = 0, c = 0, d = 0;
		getline(cin, str);

		if (str.size() == 0)
			break;

		for (int i = 0; i < str.size(); i++) {
			if (islower(str[i]))
				a++;
			else if (isupper(str[i]))
				b++;
			else if (isdigit(str[i]))
				c++;
			else if (isspace(str[i]))
				d++;
		}
		cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
	}
	

	return 0;
}