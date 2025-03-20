import java.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        boolean[] visited = new boolean[words.length];
        
        Queue<String> queue=new LinkedList<>();
        queue.add(begin);
        
        while(!queue.isEmpty()){
            int size=queue.size();
            
            for (int i=0; i<size; i++){
                String str=queue.poll();
                
                if (target.equals(str)){
                    return answer;
                }
                
                for (int j=0; j<words.length; j++){
                    if (!visited[j] && check(str, words[j])){
                        visited[j]=true;
                        queue.add(words[j]);
                    }
                }
            }
            answer++;
        }
        
        return 0;
    }
    static boolean check(String word1, String word2){
        int cnt=0;
        
        for (int i=0; i<word1.length(); i++){
            if (word1.charAt(i)!=word2.charAt(i)){
                cnt++;
            }
            if (cnt>1) return false;
        }
        
        return cnt==1;
    }
}