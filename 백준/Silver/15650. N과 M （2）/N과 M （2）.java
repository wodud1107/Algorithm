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

        dfs(N, M, 0, 0);
        System.out.println(sb);
        
        br.close();
    }
    static void dfs(int N, int M, int depth, int pos){
        if (depth==M){
            for (int n : num){
                sb.append(n).append(' ');
            }
            sb.append('\n');
            return;
        }

        for (int i=pos; i<N; i++){
            num[depth]=i+1;
            dfs(N, M, depth+1, i+1);
        }
    }
}
