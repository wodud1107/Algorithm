import java.util.*;

class Solution {
    static int[] dx=new int[]{-1, 1, 0, 0};
    static int[] dy=new int[]{0, 0, -1, 1};
    public int solution(int[][] maps) {
        int answer = 0;
        int n=maps.length;
        int m=maps[0].length;
        
        int[][] visited=new int[n][m];
        
        bfs(maps, visited);
        answer=visited[n-1][m-1];
        
        if (answer==0) answer=-1;
        return answer;
    }
    static void bfs(int[][] maps, int[][] visited){
        Queue<int[]> queue=new LinkedList<>();
        queue.add(new int[]{0,0});
        visited[0][0]=1;
        
        while(!queue.isEmpty()){
            int[] current=queue.poll();
            int x=current[0];
            int y=current[1];
            
            for (int i=0; i<4; i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if (nx < 0 || nx > maps.length-1 || ny < 0 || ny > maps[0].length-1){
                    continue;
                }
                
                if (visited[nx][ny] == 0 && maps[nx][ny]==1){
                    visited[nx][ny]=visited[x][y]+1;
                    queue.add(new int[]{nx, ny});
                }
            }
        }
    }
}