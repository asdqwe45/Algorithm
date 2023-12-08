#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct lecture {
	int st, en;
};

bool cmp(lecture left, lecture right) {
	if (left.en < right.en) 
		return true;
	
	else if (left.en > right.en) 
		return false;
	
	if ((left.en - left.st) < (right.en - right.st))
		return true;

	else if ((left.en - left.st) > (right.en - right.st))
		return false;

	else
		return false;
}

int N;
vector<lecture> lec;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int st, en;
		cin >> st >> en;
		lec.push_back({ st,en });
	}

	sort(lec.begin(), lec.end(), cmp);

	int count = 0;
	int lastTime = 0;

	for (int i = 0; i < N; i++) {
		if (lec[i].st < lastTime)
			continue;
		lastTime = lec[i].en;
		count++;
	}

	cout << count << endl;

	return 0;
}