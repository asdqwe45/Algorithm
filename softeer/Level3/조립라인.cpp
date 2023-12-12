#include <iostream>

using namespace std;

int N;
int dp[10005][2];

int main()
{
	cin >> N;
	int aToB, bToA, A, B;
	cin >> dp[1][0] >> dp[1][1];

	for (int i = 2; i <= N; i++) {
		cin >> aToB >> bToA >> A >> B;
		dp[i][0] = min(A + dp[i - 1][0], dp[i - 1][1] + A + bToA);
		dp[i][1] = min(B + dp[i - 1][1], dp[i - 1][0] + B + aToB);
	}

	int result = min(dp[N][0], dp[N][1]);

	cout << result << endl;

	return 0;
}