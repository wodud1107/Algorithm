import java.io.*;
import java.util.*;

public class Main {
    static char[][] pattern;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());
        pattern=new char[N][N];
        for (int i=0; i<N; i++){
            Arrays.fill(pattern[i], ' ');
        }
        star(0, 0, N);

        StringBuilder sb=new StringBuilder();
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                sb.append(pattern[i][j]);
            }
            sb.append("\n");
        }

        System.out.println(sb);

        br.close();
    }
    static void star(int x, int y, int N){
        if (N==1){
            pattern[x][y]='*';
            return;
        }

        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (!(i==1 && j==1)){
                    star(x+i*(N/3),y+j*(N/3),N/3);
                }
            }
        }
    }
}
