/* 전깃줄 */
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());
        int[][] wire=new int[N][2];

        StringTokenizer st;
        for (int i=0; i<N; i++){
            st=new StringTokenizer(br.readLine());
            wire[i][0]=Integer.parseInt(st.nextToken());
            wire[i][1]=Integer.parseInt(st.nextToken());
        }

        Arrays.sort(wire, (e1, e2)->{
           return Integer.compare(e1[0], e2[0]); 
        });

        int[] dp=new int[N];
        for (int i=0; i<N; i++){
            dp[i]=1;
            for (int j=0; j<i; j++){
                if (wire[j][1]<wire[i][1] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
        }

        int max=Integer.MIN_VALUE;
        for (int i=0; i<N; i++){
            if (dp[i]>max) max=dp[i];
        }

        System.out.println(N-max);

        br.close();
    }
}
