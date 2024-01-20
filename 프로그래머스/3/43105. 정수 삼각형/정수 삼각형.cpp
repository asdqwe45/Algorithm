#include <vector>

using namespace std;


int n;
int memo[500][500];
vector<vector<int>> v;

int dp(int row, int col){
    if(row == n-1)
        return 0;
    if(memo[row][col] > 0)
        return memo[row][col];
    
    int a = dp(row+1, col) + v[row+1][col];
    int b = dp(row+1, col+1) + v[row+1][col+1];
    
    int maxi = max(a,b);
     
    memo[row][col] = maxi;
    
    return maxi;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    n = triangle.size();
    
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<=i-1;j++){
            if(triangle[i][j]>triangle[i][j+1])
                triangle[i-1][j] += triangle[i][j];
            else
                triangle[i-1][j] += triangle[i][j+1];
        }
    }
    answer = triangle[0][0];
    
    return answer; 
}