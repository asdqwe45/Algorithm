#include<iostream>
#include <vector>

using namespace std;

struct Node {
    int y, x;
};
int N, K;
vector<vector<Node>> v(21);
int selectNode[21];
int mini;

void dfs(int now, Node minNode, Node maxNode) {
    if (now > K) {
        int temp = (maxNode.y - minNode.y) * (maxNode.x - minNode.x);
        mini = min(temp, mini);
        return;
    }

    int size = v[now].size();
    for (int i = 0; i < size; i++) {
        Node nowNode = v[now][i];
        Node minTemp = { min(minNode.y,nowNode.y),min(minNode.x,nowNode.x) };
        Node maxTemp = { max(maxNode.y,nowNode.y),max(maxNode.x,nowNode.x) };
        int temp = (maxTemp.y - minTemp.y) * (maxTemp.x - minTemp.x);
        if (mini > temp || now == 1) {
            selectNode[now] = i;
            dfs(now + 1, minTemp, maxTemp);
            selectNode[now] = -1;
        }
    }

}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int y, x, color;
        cin >> y >> x >> color;
        v[color].push_back({ y,x });
    }
    mini = 2e8;
    dfs(1, { 20000,20000 }, { -20000,-20000 });
    cout << mini << endl;
    return 0;
}