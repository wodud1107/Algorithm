import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int N=Integer.parseInt(st.nextToken());
        int K=Integer.parseInt(st.nextToken());
        int[][] arr=new int[N+1][2];
        int[] dp=new int[K+1];

        for (int i=1; i<=N; i++){
            st=new StringTokenizer(br.readLine());
            arr[i][0]=Integer.parseInt(st.nextToken());
            arr[i][1]=Integer.parseInt(st.nextToken());
        }

        for (int i=1; i<=N; i++){
            int W=arr[i][0];
            int V=arr[i][1];
            for (int j=K; j>=W; j--){
                dp[j]=Math.max(dp[j], dp[j-W]+V);
            }
        }

        System.out.println(dp[K]);

        br.close();
    }
}
