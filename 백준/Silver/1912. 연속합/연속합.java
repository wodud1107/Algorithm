import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());

        int[] num=new int[n];
        int[] dp=new int[n];
        StringTokenizer st=new StringTokenizer(br.readLine());
        for (int i=0; i<n; i++){
            num[i]=Integer.parseInt(st.nextToken());
        }

        dp[0]=num[0];
        int max=num[0];

        for (int i=1; i<n; i++){
            dp[i]=Math.max(dp[i-1]+num[i], num[i]);
            max=Math.max(max, dp[i]);
        }
        System.out.println(max);

        br.close();
    }
}
