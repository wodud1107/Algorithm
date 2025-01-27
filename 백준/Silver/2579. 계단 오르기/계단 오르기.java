import java.io.*;

public class Main {
    static int[] step;
    static int[] dp;
    static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        N=Integer.parseInt(br.readLine());
        step=new int[N+1];
        dp=new int[N+1];

        for (int i=1; i<=N; i++){
            step[i]=Integer.parseInt(br.readLine());
        }

        System.out.println(dp(N));

        br.close();
    }
    static int dp(int N){
        dp[0]=0;
        dp[1]=step[1];

        if (N>=2){
            dp[2]=step[1]+step[2];
        }

        for (int i=3; i<=N; i++){
            dp[i]=Math.max(dp[i-2], dp[i-3]+step[i-1])+step[i];
        }

        return dp[N];
    }
}
