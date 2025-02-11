import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());
        int[] arr=new int[N];
        int[] i_dp=new int[N];
        int[] d_dp=new int[N];

        StringTokenizer st=new StringTokenizer(br.readLine());
        for (int i=0; i<N; i++){
            arr[i]=Integer.parseInt(st.nextToken());
        }

        for (int i=0; i<N; i++){
            i_dp[i]=1;
            for (int j=0; j<i; j++){
                if (arr[j]<arr[i] && i_dp[i]<i_dp[j]+1){
                    i_dp[i]=i_dp[j]+1;
                }
            }
        }

        for (int i=N-1; i>-1; i--){
            d_dp[i]=1;
            for (int j=N-1; j>i-1; j--){
                if (arr[j]<arr[i] && d_dp[i]<d_dp[j]+1){
                    d_dp[i]=d_dp[j]+1;
                }
            }
        }

        int[] res=new int[N];
        for (int i=0; i<N; i++){
            res[i]=i_dp[i]+d_dp[i]-1;
        }

        int max=Integer.MIN_VALUE;
        for (int i=0; i<N; i++){
            if (res[i]>max) max=res[i];
        }

        System.out.println(max);

        br.close();
    }
}
