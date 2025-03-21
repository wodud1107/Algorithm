import java.util.*;

class Solution {
    public long solution(int n, int[] times) {        
        Arrays.sort(times);
        
        long left=0;
        long right= (long) times[times.length-1] * n;
        
        while (left < right){
            long mid=(left+right)>>1;
            long count=0;
            
            for (int time : times){
                count+=mid/time;
            }
            
            if (count>=n){
                right=mid;
            } else {
                left=mid+1;
            }
        }
        
        return left;
    }
}