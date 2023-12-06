#include <iostream>


using namespace std;

int dp[1001][3];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
	}
	int result = 2e8l;
	for (int i = 0; i < 3; i++) {
		if (dp[N][i] < result)
			result = dp[N][i];
	}

	cout << result << endl;

	return 0;
}