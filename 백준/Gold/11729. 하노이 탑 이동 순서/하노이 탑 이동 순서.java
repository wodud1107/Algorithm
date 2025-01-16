import java.io.*;

public class Main {
    static StringBuilder sb=new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());
        
        sb.append((1<<N)-1).append("\n");

        hanoi(N, 1, 2, 3);

        System.out.println(sb);

        br.close();
    }
    static void hanoi(int n, int a, int b, int c){
        if (n>=1){
            hanoi(n-1,a,c,b);
            sb.append(a).append(" ").append(c).append("\n");
            hanoi(n-1,b,a,c);
        }
    }
}
