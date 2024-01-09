#include <string>
#include <vector>

using namespace std;
int N;

vector<int> parent(200);

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = computers.size();
    
    
    for(int i=0;i<N;i++){
        parent[i] = i;
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N&&i!=j;j++){
            if(computers[i][j])
                merge(i,j);
        }
    }
    vector<int> used(N);
    int cnt=0;
    for(int i=0;i<N;i++){
        int num = find(i);
        if(used[num] == 0){
            cnt++;
            used[num]=1;   
        }
    }
    
    return cnt;
}