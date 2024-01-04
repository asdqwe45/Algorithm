#include <vector>
#include <queue>
#include <cstring>

using namespace std;
struct Node {
    int y, x;
};

int used[100][100];
int maxi;
int M, N;

int bfs(int row, int col, int color, vector<vector<int>> picture) {
    queue<Node>q;
    q.push({ row,col });
    int dir[4][2] = { 0,1,1,0,0,-1,-1,0 };
    int max_count = 0;
    used[row][col] = 1;
    while (!q.empty()) {
        Node now = q.front(); q.pop();
        max_count++;
        for (int i = 0; i < 4; i++) {
            int ny = now.y + dir[i][0];
            int nx = now.x + dir[i][1];

            if (ny < 0 || nx < 0 || ny >= M || nx >= N)
                continue;
            if (picture[ny][nx] != color)
                continue;
            if (used[ny][nx] == 1)
                continue;
            
            used[ny][nx] = 1;
            q.push({ ny,nx });
        }

    }
    return max_count;

}



// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {

    maxi = -2e8;
    M = m;
    N = n;
    int cnt = 0;
    int maxi = -2e8;
    memset(used, 0, sizeof(used));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] > 0 && used[i][j] == 0) {
                cnt++;
                int res = bfs(i, j, picture[i][j], picture);
                if (maxi < res)maxi = res;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = cnt;
    answer[1] = maxi;

    return answer;
}
