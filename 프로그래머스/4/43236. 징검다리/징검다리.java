import java.util.*;

class Solution {
    public int solution(int distance, int[] rocks, int n) {
        int answer = 0;
        int left=1;
        int right=distance;
        
        Arrays.sort(rocks);
        
        while (left<=right){
            int mid=(left+right)>>1;
            int count=0;
            int prev=0;
            
            for (int rock : rocks){
                int gap=rock-prev;
                
                if (gap < mid){
                    count++;
                } else prev=rock;
            }
            
            if (distance-prev < mid) count++;
            
            if (count > n) right=mid-1;
            else {
                answer=mid;
                left=mid+1;
            }
        }
        return answer;
    }
}