import java.io.*;
import java.util.*;

public class Main {
    static boolean[] visit;
    static int[] num;
    static StringBuilder sb=new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());

        num=new int[M];
        visit=new boolean[N];

        dfs(N, M, 0);
        System.out.println(sb);

        br.close();
    }
    static void dfs(int N, int M, int depth){
        if (depth==M){
            for (int val: num){
                sb.append(val).append(' ');
            }
            sb.append('\n');
            return;
        }

        for (int i=0; i<N; i++){
            if (!visit[i]){
                visit[i]=true;
                num[depth]=i+1;
                dfs(N,M,depth+1);
                visit[i]=false;
            }
        }
        return;
    }
}