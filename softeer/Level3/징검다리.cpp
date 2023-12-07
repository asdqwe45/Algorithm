#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
vector<int>stone;
int arr[3000];

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int h; cin >> h;
		stone.push_back(h);
		arr[i] = 1;
	}

	for (int i = 1; i < N; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (stone[i] > stone[j] && arr[i] < arr[j] + 1) {
				arr[i] = arr[j] + 1;
			}
		}
	}

	int result = 0;

	for (int i = 0; i < N; i++) {
		result = max(result, arr[i]);
	}

	cout << result << endl;

	return 0;
}