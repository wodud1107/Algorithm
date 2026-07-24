class Solution {
    int[] dx = { 1, -1, 0, 0 };
    int[] dy = { 0, 0, 1, -1 };
    int MOD = 1_000_000_007;
    
    public int solution(int[][] grid, int[] d, int k) {
        int n = grid.length;
        int m = grid[0].length;
        int size = n * m;
        
        long[][] T = new long[size][size];
        for (int start = 0; start < size; start++) {
            int sx = start / m;
            int sy = start % m;
            
            int[][] dp = new int[n][m];
            dp[sx][sy] = 1;
            
            for (int targetSlope : d) {
                int[][] nextDp = new int[n][m];
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if (dp[x][y] == 0) continue;
                        for (int i = 0; i < 4; i++) {
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            
                            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                                if (grid[nx][ny] - grid[x][y] == targetSlope) {
                                    nextDp[nx][ny] = (nextDp[nx][ny] + dp[x][y]) % MOD;
                                }
                            }
                        }
                    }
                }
                dp = nextDp;
            }
            
            for (int end = 0; end < size; end++) {
                int ex = end / m;
                int ey = end % m;
                T[start][end] = dp[ex][ey];
            }
        }
        
        long[][] result = pow(T, k, size);
        long answer = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                answer = (answer + result[i][j]) % MOD;
            }
        }
        
        return (int) answer;
    }
    
    private long[][] multiply(long[][] A, long[][] B, int size) {
        long[][] C = new long[size][size];
        for (int i = 0; i < size; i++) {
            for (int k = 0; k < size; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < size; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
    
    private long[][] pow(long[][] A, int exp, int size) {
        long[][] res = new long[size][size];
        for (int i = 0; i < size; i++) {
            res[i][i] = 1;
        }
        
        long[][] base = A;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = multiply(res, base, size);
            }
            base = multiply(base, base, size);
            exp /= 2;
        }
        return res;
    }
}