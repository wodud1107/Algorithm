import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());
        int[][] dp=new int[N+1][10];

        for (int i=1; i<=9; i++){
            dp[1][i]=1;
        }

        for (int i=2; i<=N; i++){
            for (int j=0; j<=9; j++){
                if (j>0) dp[i][j]+=dp[i-1][j-1];
                if (j<9) dp[i][j]+=dp[i-1][j+1];
                dp[i][j]%=1000000000;
            }
        }

        int res=0;
        for (int i=0; i<=9; i++){
            res=(res+dp[N][i])%1000000000;
        }

        System.out.println(res);

        br.close();
    }
}
