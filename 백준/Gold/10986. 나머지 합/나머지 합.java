import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());
        int[] residueCount=new int[M];

        long sum=0;
        long result=0;
        st=new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++){
            sum+=Integer.parseInt(st.nextToken());
            int residue=(int)(sum%M);

            if (residue==0) result++;
            
            residueCount[residue]++;
        }

        for (int count:residueCount){
            if (count>1){
                result+=(long) count*(count-1)/2;
            }
        }

        System.out.println(result);
        
        br.close();
    }
}
