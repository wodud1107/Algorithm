import java.io.*;
import java.util.*;

public class Main {
    static int[][] color;
    static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());
        color=new int[N][3];
        dp=new int[N][3];

        StringTokenizer st;
        for (int i=0; i<N; i++){
            st=new StringTokenizer(br.readLine());
            color[i][0]=Integer.parseInt(st.nextToken()); //red
            color[i][1]=Integer.parseInt(st.nextToken()); //green
            color[i][2]=Integer.parseInt(st.nextToken()); //blue
        }

        dp[0][0]=color[0][0];
        dp[0][1]=color[0][1];
        dp[0][2]=color[0][2];

        paint(N);
        System.out.println(Math.min(dp[N-1][0], Math.min(dp[N-1][1], dp[N-1][2])));

        br.close();
    }
    static void paint(int N){
        for (int i=1; i<N; i++){
            dp[i][0]=Math.min(dp[i-1][1], dp[i-1][2])+color[i][0];
            dp[i][1]=Math.min(dp[i-1][0], dp[i-1][2])+color[i][1];
            dp[i][2]=Math.min(dp[i-1][0], dp[i-1][1])+color[i][2];
        }
        return;
    }
}
