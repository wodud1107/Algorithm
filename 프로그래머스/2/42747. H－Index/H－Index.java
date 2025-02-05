import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        int N=citations.length;

        Arrays.sort(citations);

        for (int i=0; i<N; i++){
            if (citations[i] >= N-i){
                answer=N-i;
                break;
            }
        }

        return answer;
    }
}