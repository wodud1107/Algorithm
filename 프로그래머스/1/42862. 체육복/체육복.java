import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int[] cloth=new int[n+1];
        Arrays.fill(cloth, 1);
        
        for (int _lost : lost){
            cloth[_lost]=0;
        }
        for (int _reserve : reserve){
            if (cloth[_reserve]==0){
               cloth[_reserve]=1; 
            }
            else cloth[_reserve]=2;
        }
        
        for (int i=1; i<=n; i++){
            if (cloth[i]==0){
                if (i>1 && cloth[i-1]==2){
                    cloth[i]=1;
                    cloth[i-1]=1;
                } else if (i<n && cloth[i+1]==2){
                    cloth[i]=1;
                    cloth[i+1]=1;
                }
            }
        }
        
        int answer=0;
        for (int i=1; i<=n; i++){
            if (cloth[i]>0) answer++;
        }
        return answer;
    }
}