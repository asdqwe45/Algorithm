#include <string>
#include <vector>

using namespace std;

int arr[1001][1001];
int dir[3][2]={1,0,0,1,-1,-1};
vector<int> solution(int n) {
    vector<int> answer;

    int i = 1, j = 1, num = 1, cnt = 0, len = n;
    int d=0;
    while(len){
        arr[i][j]=num++;
        cnt++;
        
        if(cnt == len){
            d=(d+1)%3;
            len--;
            cnt=0;
        }
        i+=dir[d][0];
        j+=dir[d][1];
    }

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}