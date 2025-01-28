import java.io.*;

public class Main {
    static int[] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());
        dp=new int[N+1];
        
        System.out.println(solve(N));

        br.close();
    }
    static int solve(int N){
        if (N==1) return dp[1]=0;
        
        for (int i=2; i<=N; i++){
            dp[i] = dp[i-1]+1;
            if (i%2==0) dp[i]=Math.min(dp[i-1], dp[i/2])+1;
            if (i%3==0) dp[i]=Math.min(dp[i-1], dp[i/3])+1;
            if (i%6==0) dp[i]=Math.min(dp[i-1], Math.min(dp[i/2], dp[i/3]))+1;
        }

        return dp[N];
    }
}