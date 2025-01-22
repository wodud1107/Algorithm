import java.io.*;
import java.util.*;

public class Main {
    static int[] sumRow;
    static int[] sumCol;
    static boolean[] visit;
    static int N;
    static int min=Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        N=Integer.parseInt(br.readLine());
        int sum=0;
        sumRow=new int[N];
        sumCol=new int[N];
        visit=new boolean[N];

        StringTokenizer st;
        for (int i=0; i<N; i++){
            st=new StringTokenizer(br.readLine());
            for (int j=0; j<N; j++){
                int status=Integer.parseInt(st.nextToken());
                sum+=status;
                sumRow[j]+=status;
                sumCol[i]+=status;
            }
        }

        dfs(0, 0, sum);
        System.out.println(min);
        
        br.close();
    }
    static void dfs(int pos, int depth, int diff){
        if (depth==N/2){
            min=Math.min(min, Math.abs(diff));
            return;
        }

        for (int i=pos; i<N; i++){
            if (!visit[i]){
                visit[i]=true;
                dfs(i+1, depth+1, diff-sumCol[i]-sumRow[i]);
                visit[i]=false;
            }
        }
    }
}
