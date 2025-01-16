import java.io.*;

public class Main {
    static char[][] pattern;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());
        pattern=new char[N][N];

        star(0, 0, N,false);

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
    static void star(int x, int y, int N, boolean space){
        if (space){
            for (int i=x; i<x+N; i++){
                for (int j=y; j<y+N; j++){
                    pattern[i][j]=' ';
                }
            }
            return;
        }

        if (N==1){
            pattern[x][y]='*';
            return;
        }

        int size=N/3;
        int count=0;
        for (int i=x; i<x+N; i+=size){
            for (int j=y; j<y+N; j+=size){
                count++;
                if (count==5){
                    star(i, j, size, true);
                } else {
                    star(i, j, size, false);
                }
            }
        }
    }
}
