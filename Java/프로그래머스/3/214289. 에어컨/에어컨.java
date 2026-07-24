class Solution {
    public int solution(int temperature, int t1, int t2, int a, int b, int[] onboard) {
        int OFFSET = 10;
        int MAX_TEMP = 50;
        temperature += OFFSET;
        t1 += OFFSET;
        t2 += OFFSET;
        
        int n = onboard.length;
        int[][] dp = new int[n][];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[MAX_TEMP + 1];
            for (int j = 0; j < MAX_TEMP + 1; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        dp[0][temperature] = 0;
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < MAX_TEMP + 1; j++) {
                if (dp[i][j] == Integer.MAX_VALUE) continue;
                
                int nxt_temp = j;
                if (j < temperature) nxt_temp = j + 1;
                else if (j > temperature) nxt_temp = j - 1;
                
                if ((onboard[i + 1] == 0) || (t1 <= nxt_temp && nxt_temp <= t2)) {
                    dp[i + 1][nxt_temp] = Math.min(dp[i + 1][nxt_temp], dp[i][j]);
                }
                
                if ((onboard[i + 1] == 0) || (t1 <= j && j <= t2)) {
                    dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j] + b);
                }
                
                if (j - 1 > 0) {
                    nxt_temp = j - 1;
                    if ((onboard[i + 1] == 0) || (t1 <= nxt_temp && nxt_temp <= t2)) {
                        dp[i + 1][nxt_temp] = Math.min(dp[i + 1][nxt_temp], dp[i][j] + a);
                    }
                }
                if (j + 1 <= MAX_TEMP) {
                    nxt_temp = j + 1;
                    if ((onboard[i + 1] == 0) || (t1 <= nxt_temp && nxt_temp <= t2)) {
                        dp[i + 1][nxt_temp] = Math.min(dp[i + 1][nxt_temp], dp[i][j] + a);
                    }
                }
            }
        }
        
        int answer = Integer.MAX_VALUE;
        for (int i = 0; i < MAX_TEMP + 1; i++) {
            answer = Math.min(answer, dp[n - 1][i]);
        }
        
        return answer;
    }
}