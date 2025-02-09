/* 포도주 시식 */
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N=Integer.parseInt(br.readLine());
        int[] grape=new int[N+1];
        int[] drink=new int[N+1];

        for (int i=1; i<=N; i++){
            grape[i]=Integer.parseInt(br.readLine());
        }
        
        drink[1]=grape[1];
        if(N>1){
            drink[2]=grape[1]+grape[2];
        }
        for (int i=3; i<=N; i++){
            drink[i]=Math.max(drink[i-1], Math.max(drink[i-2]+grape[i], drink[i-3]+grape[i-1]+grape[i]));
        }

        System.out.println(drink[N]);

        br.close();
    }
}