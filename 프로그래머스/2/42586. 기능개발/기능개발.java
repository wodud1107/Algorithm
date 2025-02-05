import java.util.*;

class Solution {
    public ArrayList<Integer> solution(int[] progresses, int[] speed){
        ArrayList<Integer> answer=new ArrayList<>();
        int N=progresses.length;
        Queue<Integer> queue=new LinkedList<>();
        for (int i=0; i<N; i++){
            int left=100-progresses[i];
            if (left%speed[i] == 0){
                queue.add(left/speed[i]);
            } else {
                queue.add(left/speed[i]+1);
            }
        }

        int prev=queue.poll();
        int cnt=1;
        while (!queue.isEmpty()){
            if (prev>=queue.peek()){
                cnt++;
                queue.poll();
            } else {
                answer.add(cnt);
                cnt=1;
                prev=queue.poll();
            }
        }
        answer.add(cnt);

        return answer;
    }
}