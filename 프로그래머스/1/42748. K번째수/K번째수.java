import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {        
        int[] answer=new int[commands.length];
        
        for (int i=0; i<commands.length; i++){
            ArrayList<Integer> tmp=new ArrayList<>();
            int start=commands[i][0]-1;
            while (start<commands[i][1]){
                tmp.add(array[start++]);
            }
            Collections.sort(tmp);
            answer[i]=tmp.get(commands[i][2]-1);
        }

        return answer;
    }
}