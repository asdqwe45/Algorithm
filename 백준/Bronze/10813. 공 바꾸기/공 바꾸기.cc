#include <iostream>
#include <vector>
using namespace std;



int main() {
	
	int N, M;
	cin >> N >> M;
	vector<int> v(N + 1);
	
	for (int i = 1; i < N + 1; i++) {
		v[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		swap(v[a], v[b]);
	}

	for (int i = 1; i < N + 1; i++) {
		cout << v[i] << ' ';
	}

	return 0;
}