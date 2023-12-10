#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[50][50];

struct Node {
	int y, x;
};

int bfs(int row, int col) {
	int visited[50][50] = { 0 };
	queue<Node>q;
	q.push({ row,col });
	visited[row][col] = 1;
	int dir[8][2] = { -1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1 };
	int flag = 0;
	int count = 0;
	while (!q.empty()) {
		int len = q.size();
		for (int n = 0; n < len; n++) {
		Node now = q.front(); q.pop();

		
			for (int i = 0; i < 8; i++) {
				int ny = now.y + dir[i][0];
				int nx = now.x + dir[i][1];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M)
					continue;
				if (visited[ny][nx] == 1)
					continue;
				if (map[ny][nx] == 1) {
					flag = 1;
					break;
				}
				visited[ny][nx] = 1;

				q.push({ ny,nx });
			}
			if (flag == 1)
				break;
		}
		if (flag == 1) {
			count++;
			break;
		}
		count++;
	}

	return count;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int maxi = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				int temp = bfs(i, j);
				maxi = max(maxi, temp);
			}
		}
	}

	cout << maxi << endl;

	return 0;
}