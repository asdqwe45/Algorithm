import java.util.*;

class Solution {
    
    int N,M;
    int[][] maps;
    int[][] visited;
    int depth;
    Map<Integer,Integer> lump;
    
    public void bfs(int row, int col){
        visited[row][col] = 1;
        Queue<int[]> q = new LinkedList<>();
        maps[row][col] = depth;
        q.offer(new int[]{row,col});
        int count = 0;
        int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while(!q.isEmpty()){
            int[] front = q.poll();
            count++;
            for(int i=0;i<4;i++){
                int ny = front[0] + dir[i][0];
                int nx = front[1] + dir[i][1];
                
                if(ny<0 || nx<0 || ny>= N || nx>= M)
                    continue;
                if(maps[ny][nx] ==0)
                    continue;
                if(visited[ny][nx] == 1)
                    continue;
                visited[ny][nx]=1;
                maps[ny][nx]=depth;
                q.offer(new int[]{ny,nx});
                
            }
        }
        lump.put(depth++,count);
    }
    
    public int solution(int[][] land) {
        int answer = 0;
        N = land.length;
        M = land[0].length;
        maps = land;        
        depth = 1;
        visited = new int[N][M];
        lump = new HashMap<>();
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(maps[i][j] == 0 || visited[i][j] == 1)
                    continue;
                bfs(i,j);
            }
        }
    
        for(int i=0;i<M;i++){
            int temp = 0;
            Set<Integer> s = new HashSet<>();
            for(int j=0;j<N;j++){
                s.add(maps[j][i]);
            }
            for(int it : s){
                temp += lump.getOrDefault(it,0);
            }
            answer = Math.max(answer,temp);
        }
        
        return answer;
    }
}