import java.io.*;
import java.util.*;

public class Main {
    static int[][] dp;
    static int[][] triangle;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());
        dp=new int[N+1][N+1];
        triangle=new int[N+1][N+1];

        StringTokenizer st;
        for (int i=1; i<=N; i++){
            st=new StringTokenizer(br.readLine());
            for (int j=1; j<=i; j++){
                triangle[i][j]=Integer.parseInt(st.nextToken());
            }
        }

        for(int i=1; i<=N; i++){
            for (int j=1; j<=N; j++){
                dp[i][j]=Math.max(dp[i-1][j-1], dp[i-1][j])+triangle[i][j];
            }
        }

        int answer=dp[N][0];
        for (int i=1; i<=N; i++){
            answer=Math.max(answer, dp[N][i]);
        }
        System.out.println(answer);

        br.close();
    }
}