import java.util.*;

class Solution {
    public ArrayList<Integer> solution(int[] answers){
        int[] first={1,2,3,4,5};
        int[] second={2,1,2,3,2,4,2,5};
        int[] third={3,3,1,1,2,2,4,4,5,5};

        int[] result=new int[3];
    
        result[0]=comp(first, answers);
        result[1]=comp(second, answers);
        result[2]=comp(third, answers);

        int max=Math.max(result[0], Math.max(result[1], result[2]));

        ArrayList<Integer> ans=new ArrayList<>();
        for (int i=0; i<result.length; i++){
            if (max==result[i]){
                ans.add(i+1);
            }
        }

        return ans;
    }
    static int comp(int[] arr, int[] answers){
        int result=0;
        for (int i=0; i<answers.length; i++){
            int j=i%arr.length;
            if (answers[i]==arr[j]) result++;
        }
        return result;
    }
}