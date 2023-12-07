#include <iostream>

using namespace std;

#define ll long long

ll K, P, N;


int main() {

	cin >> K >> P >> N;

	for (int i = 0; i < N; i++) {
		K = (K * P) % 1000000007;
	}



	cout << K << endl;

	return 0;
}