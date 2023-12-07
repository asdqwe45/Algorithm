#include <iostream>
#include <vector>

using namespace std;

vector<float> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	v.push_back(0.00);
	float sum = 0.00;

	cout << fixed;
	cout.precision(2);

	for (int i = 0; i < N; i++) {
		float num; cin >> num;
		sum += num;
		v.push_back(sum);
	}

	for (int i = 0; i < K; i++) {
		int A, B;
		cin >> A >> B;
		float result = (v[B] - v[A - 1]) / (B - (A - 1));
		cout << result / 1.00 << endl;
	}
	
	return 0;
}