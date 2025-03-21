class Solution {
    static final int MOD=1000000007;
    public int solution(int m, int n, int[][] puddles) {
        int[][] dp=new int[m+1][n+1];
        boolean[][] isPuddles=new boolean[m+1][n+1];
        
        for (int[] puddle : puddles){
            int x=puddle[0];
            int y=puddle[1];
            isPuddles[x][y]=true;
        }

        dp[1][1]=1;
        
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                if (isPuddles[i][j]){
                    dp[i][j]=0;
                    continue;
                }
                if (i==1 && j==1) continue;
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
            }
        }
        
        return dp[m][n];
    }
}