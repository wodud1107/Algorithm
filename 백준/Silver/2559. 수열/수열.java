import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int N=Integer.parseInt(st.nextToken());
        int K=Integer.parseInt(st.nextToken());

        int[] temp=new int[N+1];
        st=new StringTokenizer(br.readLine());
        for (int i=1; i<=N; i++){
            temp[i]=temp[i-1]+Integer.parseInt(st.nextToken());
        }

        int max=Integer.MIN_VALUE;
        for (int i=0; i+K<=N; i++){
            int t=temp[i+K]-temp[i];
            if (max<t) max=t;
        }

        System.out.println(max);

        br.close();
    }
}
