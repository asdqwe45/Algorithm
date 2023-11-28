#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

vector<vector<int>> maps;
int depth;
int visited[500][500];
map<int,int> lump;
int N,M;

void bfs(int row,int col){
    int dir[4][2] = {0,1,0,-1,1,0,-1,0};
    maps[row][col]=depth;
    queue<pair<int,int>> q;
    q.push({row,col});
    int count = 0;
    visited[row][col] = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        count++;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if(ny<0 || nx<0 || ny>=N || nx >= M)
                continue;
            if(maps[ny][nx] == 0)
                continue;
            if(visited[ny][nx] == 1)
                continue;
            maps[ny][nx] = depth;
            visited[ny][nx]=1;
        
            q.push({ny,nx});
        }
    }
    lump[depth++]=count;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    depth = 1;
    maps = land;
    N = land.size();
    M = land[0].size();
    // bfs돌면서 maps랑 cnt 저장
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j] == 1 || maps[i][j] == 0)
                continue;
            bfs(i,j);
        }
    }
    
    for(int i=0;i<M;i++){
        int temp = 0;
        set<int> s;
        for(int j=0;j<N;j++){
            s.insert(maps[j][i]);
        }
        for(auto it : s){
            temp += lump[it];
        }
        answer = max(answer,temp);
    }
    
    
    return answer;
}