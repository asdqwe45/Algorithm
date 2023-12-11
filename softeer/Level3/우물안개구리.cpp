#include<iostream>
#include <vector>

using namespace std;

int N, M;

int main(int argc, char** argv)
{
    cin >> N >> M;
    vector<int> weight(N + 1);
    vector<int> check(N + 1);
    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        int w; cin >> w;
        weight[i] = w;

    }
    int d = 1;
    for (int i = 0; i < M; i++) {
        int mem1, mem2; cin >> mem1 >> mem2;
        if (weight[mem1] > weight[mem2]) {
            check[mem2] = -1;
        }
        else if (weight[mem1] < weight[mem2]) {
            check[mem1] = -1;
        }
        else if (weight[mem1] == weight[mem2]) {
            check[mem1] = -1;
            check[mem2] = -1;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (check[i] != -1)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}