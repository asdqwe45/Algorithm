#include <iostream>


using namespace std;

int N, M, B;

int map[500][500];

int main()
{
	cin >> N >> M >> B;
	int mini = 2e8;
	int maxi = -2e8;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (mini > map[i][j])
				mini = map[i][j];
			if (maxi < map[i][j])
				maxi = map[i][j];
		}
	}

	int T = 2e8 , H = 0;

	for (int h = mini; h <= maxi; h++) {
		int tempB = B;

		int t = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == h)
					continue;
				else if (map[i][j] > h) {
					t += (map[i][j] - h) * 2;
					tempB += map[i][j]-h;
				}
				else if (map[i][j] < h) {
					t += (h - map[i][j]);
					tempB -= (h - map[i][j]);
				}
			}

		}
		if (tempB < 0)
			continue;
		if (T >= t) {
			T = t;
			H = h;
		}

	}

	cout << T << " " << H << endl;
	return 0;
}