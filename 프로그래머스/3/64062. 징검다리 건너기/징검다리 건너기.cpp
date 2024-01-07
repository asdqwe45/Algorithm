#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int left, int right) {
    if (left < right)
        return true;
    else if (left > right)
        return false;
    return false;
}

bool isPossible(vector<int> stones, int k, int num) {
    int count=0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] <= num)
            count++;
        else
            count=0;
        if(count>=k)
            return false;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int answer = 0;

    vector<int> copy = stones;
    sort(copy.begin(), copy.end(), cmp);

    int left = 1;
    int right = copy[copy.size()-1];
    int mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (isPossible(stones, k, mid)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    answer = left;
    
    return answer;
}