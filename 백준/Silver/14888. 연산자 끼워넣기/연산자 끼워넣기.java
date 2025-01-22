import java.io.*;
import java.util.*;

public class Main {
    static int[] num;
    static int[] ops=new int[4];
    static int max=Integer.MIN_VALUE;
    static int min=Integer.MAX_VALUE;
    static StringBuilder sb=new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());
        
        StringTokenizer st=new StringTokenizer(br.readLine());
        num=new int[N];
        for (int i=0; i<N; i++){
            num[i]=Integer.parseInt(st.nextToken());
        }
        
        st=new StringTokenizer(br.readLine());
        for (int i=0; i<4; i++){
            ops[i]=Integer.parseInt(st.nextToken());
        }
        
        dfs(N, num[0], 1);
        sb.append(max).append('\n');
        sb.append(min).append('\n');
        
        System.out.println(sb);
        
        br.close();
    }
    static void dfs(int N, int res, int index){
        if (index==N){
            max=Math.max(max, res);
            min=Math.min(min, res);
            return;
        }

        for (int i=0; i<4; i++){
            if (ops[i]>0){
                ops[i]--;
                if (i==0){
                    dfs(N, res+num[index], index+1);
                } else if (i==1){
                    dfs(N, res-num[index], index+1);
                } else if (i==2){
                    dfs(N, res*num[index], index+1);
                } else if (i==3){
                    dfs(N, res/num[index], index+1);
                }
                ops[i]++;
            }
        }
    }
}
