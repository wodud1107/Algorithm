import java.util.*;

class Solution {
    static class Node implements Comparable<Node> {
        int to;
        int weight;
        
        Node(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
        
        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.weight, o.weight);
        }
    }
    
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        boolean[] isSummit = new boolean[n + 1];
        for (int summit : summits) {
            isSummit[summit] = true;
        }
        
        boolean[] isGate = new boolean[n + 1];
        for (int gate : gates) {
            isGate[gate] = true;
        }
        
        List<List<Node>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int[] path : paths) {
            int u = path[0], v = path[1], w = path[2];
            graph.get(u).add(new Node(v, w));
            graph.get(v).add(new Node(u, w));
        }
        PriorityQueue<Node> pq = new PriorityQueue<>();
        int[] intensity = new int[n + 1];
        Arrays.fill(intensity, Integer.MAX_VALUE);
        
        for (int gate : gates) {
            pq.offer(new Node(gate, 0));
            intensity[gate] = 0;
        }
        
        while (!pq.isEmpty()) {
            Node curr = pq.poll();
            
            if (curr.weight > intensity[curr.to]) continue;
            if (isSummit[curr.to]) continue;
            
            for (Node next : graph.get(curr.to)) {
                if (isGate[next.to]) continue;
                int nextIntensity = Math.max(intensity[curr.to], next.weight);
                
                if (nextIntensity < intensity[next.to]) {
                    intensity[next.to] = nextIntensity;
                    pq.offer(new Node(next.to, nextIntensity));
                }
            }
        }
        
        Arrays.sort(summits);
        int bestSummit = -1;
        int minIntensity = Integer.MAX_VALUE;
        
        for (int summit : summits) {
            if (intensity[summit] < minIntensity) {
                minIntensity = intensity[summit];
                bestSummit = summit;
            }
        }
        
        return new int[]{bestSummit, minIntensity};
    }
}