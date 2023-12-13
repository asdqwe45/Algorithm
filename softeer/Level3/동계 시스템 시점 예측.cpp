#include<iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node{
  int y,x;
};

int N,M;
queue<Node> ice;
int map[100][100];
int cnt[100][100];

void checkIce() {
    int visited[100][100] = { 0 };
    visited[0][0] = 1;
    queue<Node> q;
    q.push({ 0,0 });
    int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
    while (!q.empty()) {
        Node now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + dir[i][0];
            int nx = now.x + dir[i][1];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;
            if (map[ny][nx] == 1) {
                cnt[ny][nx]++;
                continue;
            }
            if (visited[ny][nx] == 1)
                continue;
            visited[ny][nx] = 1;
            q.push({ ny,nx });
        }
    }
}

void eraseIce(queue<Node> erase){
  while(!erase.empty()){
    Node now = erase.front();erase.pop();
    map[now.y][now.x]=0;
  }
}

int main(int argc, char** argv)
{
  cin>>N>>M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin>>map[i][j];
      if(map[i][j]==1){
          ice.push({ i,j });
      }
    }
  }

  int size = ice.size();
  int hours = 0;
  queue<Node> erase;
  
  while(size){
    hours++;
    memset(cnt, 0, sizeof(cnt));
    // 제거되는 얼음인지 확인
    checkIce();
    // 제거되는 얼음 erase에 추가
    for (int i = 0; i < size; i++) {
        Node now = ice.front(); ice.pop();
        if (cnt[now.y][now.x] >= 2) {
            erase.push(now);
        }
        else {
            ice.push(now);
        }
    }

    eraseIce(erase);
    size = ice.size();
  }
  cout<<hours<<endl;
   return 0;
}