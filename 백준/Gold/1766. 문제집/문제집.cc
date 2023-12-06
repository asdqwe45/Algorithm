#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
queue<int>q;
int used[33000];


int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	vector<vector<int>>v(N + 1);
	vector<int>cnt(N + 1);
	vector<int>ans(N + 1);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		cnt[b]++;
	}

	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) {
			used[i] = 1;
			q.push( i);
			break;
		}
	}
	int count = 0;

	while (!q.empty()) {
		int next = q.front();
		ans[count++] = next;
		q.pop();

		for (int i = 0; i < v[next].size(); i++) {
			int x = v[next][i];
			cnt[x]--;
		}
		for (int i = 1; i <= N; i++) {
			if (used[i] == 1)continue;
			if (cnt[i] == 0) {
				used[i] = 1;
				q.push(i);
				break;
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
	cout << '\n';


	return 0;
}