#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int long long> v;

int main() {

	int N;
	int num;

	cin >> N >> num;
	int long long sum = 0;
	int maxi = 0;
	for (int i = 0;i < N;i++) {
		int long long temp;
		cin >> temp;
		sum += temp;
		v.push_back(temp);
		if (maxi < temp)maxi = temp;
	}
	int long long answer = 0;
	int ret = 0;
	
	int long long mid, low = 1, high = maxi;

	while (low <= high) {
		mid = (low + high) / 2;

		int cnt = 0;
		for (int i = 0;i < N;i++) {
			cnt += v[i] / mid;
		}
		if (cnt >= num) {
			low = mid + 1;
			if (answer < mid)answer = mid;
		}
		else {
			high = mid - 1;
		}

	}

	cout << answer << endl;

	return 0;
}