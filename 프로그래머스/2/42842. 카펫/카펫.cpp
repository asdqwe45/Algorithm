#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int sum = brown + yellow;
    int width = 3, height = 3;
    for(int i=3;i<=sum;i++){
        if(sum%i == 0){
            int widthTemp = i;
            int heightTemp = sum/i;
            if((widthTemp-2) * (heightTemp-2) == yellow){
                width = widthTemp;
                height = heightTemp;
                break;
            }
        }
    }

    if(width>=height){
        answer.push_back(width);
        answer.push_back(height);
    }else{
        answer.push_back(height);
        answer.push_back(width);
    }

    return answer;
}