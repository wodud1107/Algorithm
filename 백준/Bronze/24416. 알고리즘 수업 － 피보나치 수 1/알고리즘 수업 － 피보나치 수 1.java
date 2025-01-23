import java.io.*;

public class Main {
    static int cnt1;
    static int cnt2;
    static int[] fib;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());
        fib=new int[N+1];

        StringBuilder sb=new StringBuilder();
        fib1(N);
        fib2(N);
        sb.append(cnt1).append(' ').append(cnt2);
        System.out.println(sb);

        br.close();
    }
    static int fib1(int n){
        if (n<=2){
            cnt1++;
            return 1;
        }
        else return fib1(n-1)+fib1(n-2);
    }
    static int fib2(int n){
        fib[1]=1;
        fib[2]=1;
        for (int i=3; i<=n; i++){
            cnt2++;
            fib[i]=fib[i-1]+fib[i-2];
        }
        return fib[n];
    }
}