import java.io.*;

public class Main {
    static int[] chess;
    static int cnt=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());

        chess=new int[N];
        NQueen(N, 0);
        System.out.println(cnt);

        br.close();
    }
    static void NQueen(int N, int depth){
        if (depth==N){
            cnt++;
            return;
        }

        for (int i=0; i<N; i++){
            chess[depth]=i;
            if (isGood(depth)){
                NQueen(N, depth+1);
            }
        }
    }
    static boolean isGood(int depth){
        for (int i=0; i<depth; i++){
            //같은 행
            if (chess[depth]==chess[i]){
                return false;
            }
            //대각선
            else if (Math.abs(depth-i)==Math.abs(chess[depth]-chess[i])){
                return false;
            }
        }
        return true;
    }
}
