import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String S=br.readLine();
        int q=Integer.parseInt(br.readLine());

        StringTokenizer st;
        StringBuilder sb=new StringBuilder();
        while(q-- >0){
            st=new StringTokenizer(br.readLine());
            char find=st.nextToken().charAt(0);
            int l=Integer.parseInt(st.nextToken());
            int r=Integer.parseInt(st.nextToken());

            int check;
            int[] appear=new int[S.length()+1];
            for (int i=1; i<=S.length(); i++){
                check=0;
                if (S.charAt(i-1)==find){
                    check=1;
                }
                appear[i]=appear[i-1]+check;
            }

            sb.append(appear[r+1]-appear[l]).append('\n');
        }
        
        System.out.println(sb);

        br.close();
    }
}
