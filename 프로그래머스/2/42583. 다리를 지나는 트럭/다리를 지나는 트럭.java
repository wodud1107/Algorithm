import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        int bridge_weight=0;
        Queue<Integer> bridge = new LinkedList<>();
        
        for (int i=0; i<bridge_length; i++){
            bridge.add(0);
        }
        
        int index=0;
        while (index<truck_weights.length){
            answer++;
            
            bridge_weight-=bridge.poll();
            
            if (bridge_weight+truck_weights[index] > weight){
                bridge.add(0);
            } else{
                bridge.add(truck_weights[index]);
                bridge_weight+=truck_weights[index];
                index++;
            }
        }
        
        return answer+bridge_length;
    }
}