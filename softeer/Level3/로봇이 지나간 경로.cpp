#include<iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
    int y, x;
    int dir;
};
int H, W;
char map[26][26];
Node stNode;
int stDirNum;
string stDir = "<v>^";
string path;

void findStart() {
    int dirs[4][2] = { 0,-1,1,0,0,1,-1,0 };
    int d = -1;
    int cnt = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (map[i][j] != '#')
                continue;
            Node now = { i,j };
            cnt = 0;

            int temp = -1;
            for (int t = 0; t < 4; t++) {
                int ny = now.y + dirs[t][0];
                int nx = now.x + dirs[t][1];

                if (ny<1 || nx<1 || ny>H || nx>W)
                    continue;
                if (map[ny][nx] == '#') {
                    cnt++;
                    temp = t;
                }

            }
            if (cnt == 1) {
                stNode = { i,j };
                stDirNum = temp;
                break;
            }
        }
    }
}

void findPath(Node st, int direction) {
    int visited[26][26] = { 0 };
    int dirs[4][2] = { 0,-1,1,0,0,1,-1,0 };
    visited[st.y][st.x] = 1;
    queue<Node> q;
    q.push({ st.y,st.x,direction });
    int pathCnt = 0;
    while (!q.empty()) {
        Node now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + dirs[i][0];
            int nx = now.x + dirs[i][1];

            if (ny<1 || nx<1 || ny>H || nx>W)
                continue;
            if (visited[ny][nx] == 1)
                continue;
            if (map[ny][nx] == '#') {
                visited[ny][nx] = 1;
                // 좌회전
                if (i == (now.dir + 1) % 4) {
                    path += "L";
                    //cout << "L";
                }
                // 우회전
                int dirTemp = now.dir - 1;
                if (dirTemp == -1)
                    dirTemp = 3;
                if (i == dirTemp) {
                    path += "R";
                    //cout << "R";

                }
                int nny = ny + dirs[i][0];
                int nnx = nx + dirs[i][1];
                visited[nny][nnx] = 1;
                q.push({ nny,nnx,i });
                path += "A";
                //cout << "A";
                break;
            }
        }
    }
}

int main(int argc, char** argv)
{
    cin >> H >> W;
    path = "";
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> map[i][j];
        }
    }
    findStart();
    findPath(stNode, stDirNum);
    cout << stNode.y << ' ' << stNode.x << endl << stDir[stDirNum] << endl;
    cout << path << endl;

    return 0;
}