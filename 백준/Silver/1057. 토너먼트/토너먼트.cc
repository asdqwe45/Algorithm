#include <iostream>
#include <string>
using namespace std;


int main()
{
	int N, a, b;
	cin >> N >> a >> b;
	int flag = 1;
	int rnd = 1;
	a = (a + 1) / 2;
	b = (b + 1) / 2;
	while (a!=b) {
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		rnd++;
	}

	cout << rnd << endl;

	return 0;
}