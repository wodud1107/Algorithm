import java.util.*;

class Solution {
    public int solution(String arr[]) {
        ArrayList<Integer> nums=new ArrayList<>();
        ArrayList<String> ops=new ArrayList<>();
        
        for (int i=0; i<arr.length; i++){
            if (i%2==0){
                nums.add(Integer.parseInt(arr[i]));
            } else {
                ops.add(arr[i]);
            }
        }
        
        int[][] maxDp=new int[nums.size()][nums.size()];
        int[][] minDp=new int[nums.size()][nums.size()];
        
        for (int i=0; i<nums.size(); i++){
            maxDp[i][i]=nums.get(i);
            minDp[i][i]=nums.get(i);
        }
        
        for (int len=1; len<nums.size(); len++){
            for (int i=0; i+len<nums.size(); i++){
                int j=i+len;
                maxDp[i][j]=Integer.MIN_VALUE;
                minDp[i][j]=Integer.MAX_VALUE;
                
                for (int k=i; k<j; k++){
                    String op=ops.get(k);
                    
                    int a=maxDp[i][k], b=maxDp[k+1][j];
                    int c=minDp[i][k], d=minDp[k+1][j];
                    
                    if (op.equals("+")) {
                        maxDp[i][j] = Math.max(maxDp[i][j], a + b);
                        minDp[i][j] = Math.min(minDp[i][j], c + d);
                    } else if (op.equals("-")) {
                        maxDp[i][j] = Math.max(maxDp[i][j], a - d);
                        minDp[i][j] = Math.min(minDp[i][j], c - b);
                    }
                }
            }
        }
        
        return maxDp[0][nums.size()-1];
    }
}