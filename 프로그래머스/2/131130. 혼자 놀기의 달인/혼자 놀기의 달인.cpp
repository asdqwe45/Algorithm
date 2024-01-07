#include <string>
#include <vector>

using namespace std;
int used[101];
int cnt[100];

int solution(vector<int> cards) {
    int answer = 0;

    int len = cards.size();
    int curNum = 1;
    int boxNum = 0;
    int lenNum = 0;

    while(1){
        if(lenNum >= len)
            break;
        int num = cards[curNum-1];
        if(used[num] == 1){
            for(int i=1;i<=len;i++){
                if(used[i] == 0){
                    curNum=i;
                }
            }
            boxNum++;
            continue;
        }else{
            cnt[boxNum]++;
            used[num] = 1;
        }
        curNum = num;
        lenNum++;

    }
    int maxi1=0, maxi2=0;
    for(int i=0;i<=boxNum;i++){
        if(cnt[i]>maxi1){
            int temp = maxi1;
            maxi1 = cnt[i];
            maxi2 = temp;
        }else if(cnt[i]>maxi2){
            maxi2 = cnt[i];
        }
    }
    answer = maxi1 * maxi2;

    return answer;
}