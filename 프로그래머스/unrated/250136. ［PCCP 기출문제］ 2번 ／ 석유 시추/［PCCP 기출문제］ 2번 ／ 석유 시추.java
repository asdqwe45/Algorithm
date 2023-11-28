import java.util.*;

public class Solution {
    int[][] maps;
    int depth;
    int[][] visited;
    Map<Integer, Integer> lump;
    int N, M;

    public void bfs(int row, int col) {
        int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        maps[row][col] = depth;
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{row, col});
        int count = 0;
        visited[row][col] = 1;
        while (!q.isEmpty()) {
            int[] front = q.poll();
            int y = front[0];
            int x = front[1];
            count++;
            for (int i = 0; i < 4; i++) {
                int ny = y + dir[i][0];
                int nx = x + dir[i][1];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                    continue;
                if (maps[ny][nx] == 0)
                    continue;
                if (visited[ny][nx] == 1)
                    continue;
                maps[ny][nx] = depth;
                visited[ny][nx] = 1;

                q.offer(new int[]{ny, nx});
            }
        }
        lump.put(depth++, count);
    }

    public int solution(int[][] land) {
        int answer = 0;
        depth = 1;
        maps = land;
        N = land.length;
        M = land[0].length;
        visited = new int[N][M];
        lump = new HashMap<>();

        // BFS를 돌면서 maps와 cnt 저장
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == 1 || maps[i][j] == 0)
                    continue;
                bfs(i, j);
            }
        }

        for (int i = 0; i < M; i++) {
            int temp = 0;
            Set<Integer> s = new HashSet<>();
            for (int j = 0; j < N; j++) {
                s.add(maps[j][i]);
            }
            for (int it : s) {
                temp += lump.getOrDefault(it, 0);
            }
            answer = Math.max(answer, temp);
        }

        return answer;
    }
}
