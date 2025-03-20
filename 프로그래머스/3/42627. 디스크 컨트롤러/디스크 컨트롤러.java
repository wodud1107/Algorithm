import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        Arrays.sort(jobs, Comparator.comparingInt(a->a[0]));
        PriorityQueue<int[]> pq=new PriorityQueue<>(Comparator.comparingInt(a->a[1]));
        int currentTime=0;
        int totalWait=0;
        int index=0;
        int complete=0;
        
        while(complete < jobs.length){
            while (index < jobs.length && jobs[index][0] <= currentTime){
                pq.add(jobs[index]);
                index++;
            }
            
            if (!pq.isEmpty()){
                int[] job=pq.poll();
                currentTime+=job[1];
                totalWait+=currentTime-job[0];
                complete++;
            }else{
                currentTime=jobs[index][0];
            }
        }
        
        return totalWait/jobs.length;
    }
}