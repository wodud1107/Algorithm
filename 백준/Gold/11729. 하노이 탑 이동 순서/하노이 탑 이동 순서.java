import java.io.*;

public class Main {
    static int cnt=0;
    static StringBuilder sb=new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());
        
        hanoi(N, 1, 2, 3);

        System.out.println(cnt);
        System.out.println(sb);

        br.close();
    }
    static void hanoi(int n, int a, int b, int c){
        cnt++;
        if (n==1) sb.append(a).append(" ").append(c).append("\n");
        else{
            hanoi(n-1,a,c,b);
            sb.append(a).append(" ").append(c).append("\n");
            hanoi(n-1,b,a,c);
        }
    }
}