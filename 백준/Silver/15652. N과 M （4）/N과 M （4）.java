import java.io.*;
import java.util.*;

public class Main {
    static int[] num;
    static StringBuilder sb=new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());

        num=new int[M];
        dfs(N, M, 0);

        System.out.println(sb);

        br.close();
    }
    static void dfs(int N, int M, int depth){
        if (depth==M){
            for (int i=0; i<M; i++){
                sb.append(num[i]).append(' ');
            }
            sb.append('\n');
            return;
        }
        for (int i=1; i<=N; i++){
            if (depth>0 && num[depth-1]>i) continue;
            num[depth]=i;
            dfs(N, M, depth+1);
        }
    }
}
