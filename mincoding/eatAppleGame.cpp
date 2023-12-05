#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[10][10];
struct Node {
	int y, x;
	int num;
	int dir;
};


bool cmp(Node left, Node right) {
	if (left.num < right.num) {
		return true;
	}
	else if (left.num > right.num) {
		return false;
	}
	return false;
}
int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {

		int N;
		cin >> N;
		int cnt = 0;

		Node now = { 0,0,0,0 };

		vector<Node> v;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int n; cin >> n;
				if (n > 0) {
					v.push_back({ i,j,n });
				}
			}
		}

		sort(v.begin(), v.end(), cmp);
		int size = v.size();

		for (int i = 0; i < size; i++) {
			if (now.dir == 0) {
				if (v[i].y == now.y && v[i].x >= now.x) {
					now = v[i];
				}
				else if (v[i].x >= now.x && v[i].y > now.y)
				{
					cnt += 1;
					now = v[i];
					now.dir = 1;
				}
				else if (v[i].y > now.y && v[i].x < now.x) {
					now = v[i];
					cnt += 2;
					now.dir = 2;
				}
				else if (v[i].x == N - 1 && v[i].y < now.y) {
					now = v[i];
					cnt += 4;
				}
				else  {
					now = v[i];
					cnt += 3;
					now.dir = 3;
				}
			}
			else if (now.dir == 1) {
				if (v[i].x == now.x && v[i].y >= now.y) {
					now = v[i];
				}
				else if (v[i].x < now.x && v[i].y >= now.y)
				{
					cnt += 1;
					now = v[i];
					now.dir = 2;
				}
				else if (v[i].y < now.y && v[i].x < now.x) {
					now = v[i];
					cnt += 2;
					now.dir = 3;
				}
				else if (v[i].y == N - 1 && v[i].x > now.x) {
					now = v[i];
					cnt += 4;
				}
				else  {
					now = v[i];
					cnt += 3;
					now.dir = 0;
				}
			}
			else if (now.dir == 2) {
				if (v[i].y == now.y && v[i].x <= now.x) {
					now = v[i];
				}
				else if (v[i].x <= now.x && v[i].y < now.y)
				{
					cnt += 1;
					now = v[i];
					now.dir = 3;
				}
				else if (v[i].y < now.y && v[i].x > now.x) {
					now = v[i];
					cnt += 2;
					now.dir = 0;
				}
				else if (v[i].x == 0 && v[i].y > now.y) {
					now = v[i];
					cnt += 4;
				}
				else  {
					now = v[i];
					cnt += 3;
					now.dir = 1;
				}
			}
			else if (now.dir = 3) {
				if (v[i].x == now.x && v[i].y <= now.y) {
					now = v[i];
				}
				else if (v[i].x > now.x && v[i].y <= now.y)
				{
					cnt += 1;
					now = v[i];
					now.dir = 0;
				}
				else if (v[i].y > now.y && v[i].x > now.x) {
					now = v[i];
					cnt += 2;
					now.dir = 1;
				}
				else if (v[i].y == 0 && v[i].x < now.x) {
					now = v[i];
					cnt += 4;
				}
				else {
					now = v[i];
					cnt += 3;
					now.dir = 2;
				}
			}
		}

		cout << "#" << t << ' ' << cnt << endl;

	}

	return 0;
}