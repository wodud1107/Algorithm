import java.io.*;

public class Main {
    static int[] fib;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());
        fib=new int[N+1];

        StringBuilder sb=new StringBuilder();
        sb.append(fibonacci(N)).append(' ').append(N-2);
        System.out.println(sb);

        br.close();
    }
    static int fibonacci(int n){
        fib[1]=1;
        fib[2]=1;
        for (int i=3; i<=n; i++){
            fib[i]=fib[i-1]+fib[i-2];
        }
        return fib[n];
    }
}