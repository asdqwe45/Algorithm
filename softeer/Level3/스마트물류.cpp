#include<iostream>


using namespace std;

int N, K;
string str;
int visited[20000];

int main(int argc, char** argv)
{
    cin >> N >> K;
    cin >> str;
    int size = str.size();
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        int flag = 0;
        if (str[i] == 'P') {
            for (int j = K; j >= 1; j--) {
                int idx = i - j;
                if (idx < 0)
                    continue;
                if (visited[idx] == 1)
                    continue;
                visited[idx] = 1;
                if (str[idx] == 'H') {
                    cnt++;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                continue;
            for (int j = 1; j <= K; j++) {
                int idx = i + j;
                if (idx >= N)
                    continue;
                if (visited[idx] == 1)
                    continue;
                visited[idx] = 1;
                if (str[idx] == 'H') {
                    cnt++;
                    flag = 1;
                    break;
                }
            }
        }
    }
    cout << cnt << endl;

    return 0;
}