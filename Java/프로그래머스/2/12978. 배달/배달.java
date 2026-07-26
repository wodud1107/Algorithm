import java.util.*;

class Solution {
    public int solution(int N, int[][] road, int K) {
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int[] conn : road) {
            int a = conn[0], b = conn[1], c = conn[2];
            graph.get(a).add(new int[]{b, c});
            graph.get(b).add(new int[]{a, c});
        }
        
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            Comparator.comparingInt(a -> a[0])
        );
        pq.offer(new int[]{0, 1});
        int[] visited = new int[N + 1];
        Arrays.fill(visited, Integer.MAX_VALUE);
        visited[1] = 0;
        
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            
            if (curr[0] != visited[curr[1]]) continue;
            
            for (int[] nxt : graph.get(curr[1])) {
                int nxtCost = curr[0] + nxt[1];
                if (visited[nxt[0]] > nxtCost) {
                    visited[nxt[0]] = nxtCost;
                    pq.offer(new int[]{nxtCost, nxt[0]});
                }
            }
        }
        
        int answer = 0;
        for (int i = 1; i <= N; i++) {
            if (visited[i] <= K) answer++;
        }

        return answer;
    }
}