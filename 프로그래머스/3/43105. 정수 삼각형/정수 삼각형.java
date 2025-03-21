class Solution {
    static int[][] dp;
    public int solution(int[][] triangle) {
        dp=new int[triangle.length+1][triangle.length+1];
        
        for (int i=1; i<=triangle.length; i++){
            for (int j=1; j<=i; j++){
                dp[i][j]=Math.max(dp[i-1][j-1], dp[i-1][j])+triangle[i-1][j-1];
            }
        }
        
        int answer=dp[triangle.length][0];
        for (int i=0; i<triangle.length+1; i++){
            answer=Math.max(answer, dp[triangle.length][i]);
        }
        
        return answer;
    }
}