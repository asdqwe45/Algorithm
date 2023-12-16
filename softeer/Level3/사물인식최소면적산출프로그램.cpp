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

int calc() {
    Node minNode = { 200000000,200000000 };
    Node maxNode = { -200000000,-200000000 };
    for (int i = 1; i <= K; i++) {
        if (selectNode[i] == -1)
            continue;
        Node now = v[i][selectNode[i]];
        minNode.y = min(minNode.y, now.y);
        minNode.x = min(minNode.x, now.x);
        maxNode.y = max(maxNode.y, now.y);
        maxNode.x = max(maxNode.x, now.x);
    }
    int result = (maxNode.y - minNode.y) * (maxNode.x - minNode.x);

    return result;
}

void dfs(int now) {
    if (now > K) {
        int temp = calc();
        mini = min(temp, mini);
        return;
    }

    int size = v[now].size();
    for (int i = 0; i < size; i++) {
        if (mini > calc()) {
            selectNode[now] = i;
            dfs(now + 1);
            selectNode[now] = -1;
        }
    }

}

int main(int argc, char** argv)
{
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int y, x, color;
        cin >> y >> x >> color;
        v[color].push_back({ y,x });
    }
    mini = 2e8;
    dfs(1);
    cout << mini << endl;
    return 0;
}