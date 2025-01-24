import java.io.*;

public class Main {
    static long[] arr=new long[101];
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int T=Integer.parseInt(br.readLine());

        StringBuilder sb=new StringBuilder();
        while (T-- >0){
            int N=Integer.parseInt(br.readLine());
            sb.append(P(N)).append('\n');
        }

        System.out.println(sb);

        br.close();
    }
    static long P(int N){
        arr[1]=1;
        arr[2]=1;
        arr[3]=1;
        for (int i=4; i<=N; i++){
            arr[i]=arr[i-2]+arr[i-3];
        }
        return arr[N];
    }
}
