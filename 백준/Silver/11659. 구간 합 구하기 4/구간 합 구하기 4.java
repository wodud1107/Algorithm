/* 구간 합 구하기 4 */
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());

        int[] prefixSum=new int[N+1];
        st=new StringTokenizer(br.readLine(), " ");
        for (int i=1; i<=N; i++){
            prefixSum[i]=prefixSum[i-1]+Integer.parseInt(st.nextToken());
        }

        StringBuilder sb=new StringBuilder();
        while (M-- > 0){
            st=new StringTokenizer(br.readLine(), " ");
            int start=Integer.parseInt(st.nextToken());
            int end=Integer.parseInt(st.nextToken());

            sb.append(prefixSum[end]-prefixSum[start-1]).append('\n');
        }

        System.out.println(sb);

        br.close();
    }
}