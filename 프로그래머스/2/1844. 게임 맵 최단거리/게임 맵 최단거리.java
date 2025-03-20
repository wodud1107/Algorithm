import java.util.*;

class Solution {
    static int[] dx={-1, 1, 0, 0};
    static int[] dy={0, 0, -1, 1};
    public int solution(int[][] maps) {
        int n=maps.length;
        int m=maps[0].length;
        
        return bfs(maps, n, m);
    }
    static int bfs(int[][] maps, int n, int m){
        Queue<int[]> queue=new LinkedList<>();
        
        queue.add(new int[]{0, 0, 1});
        
        while (!queue.isEmpty()){
            int[] current=queue.poll();
            int x=current[0];
            int y=current[1];
            int distance=current[2];
            
            if (x == n-1 && y == m-1){
                return distance;
            }
            
            for (int i=0; i<4; i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                    if (maps[nx][ny]==1){
                        maps[nx][ny]=0;
                        queue.add(new int[]{nx, ny, distance+1});
                    }
                }
            }
        }
        
        return -1;
    }
}