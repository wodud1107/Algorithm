import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        LinkedList<Integer> queue=new LinkedList<>();
        for (int i=0; i<priorities.length; i++){
            queue.add(priorities[i]);
        }

        int cnt=0;
        while(!queue.isEmpty()){
            int max=findMax(queue);
            int tmp=queue.poll();
            
            if (max!=tmp) queue.add(tmp);
            else cnt++;
            
            location--;
            if (location<0){
                if (max==tmp) break;
                else location=queue.size()-1;
            }
        }
        
        return cnt;
    }
    static int findMax(LinkedList<Integer> queue){
        int max=queue.peek();
        for (int i=1; i<queue.size(); i++){
            if (max < queue.get(i)){
                max=queue.get(i);
            }
        }
        return max;
    }
}