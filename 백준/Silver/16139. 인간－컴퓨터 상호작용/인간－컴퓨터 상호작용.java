import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String S=br.readLine();
        int q=Integer.parseInt(br.readLine());

        int[][] appear=new int[26][S.length()+1];
        int check;
        for (int i=0; i<26; i++){
            for (int j=1; j<=S.length(); j++){
                check=0;
                if (S.charAt(j-1)==i+'a'){
                    check=1;
                }
                appear[i][j]=appear[i][j-1]+check;
            }
        }

        StringTokenizer st;
        StringBuilder sb=new StringBuilder();
        while(q-- >0){
            st=new StringTokenizer(br.readLine());
            char find=st.nextToken().charAt(0);
            int l=Integer.parseInt(st.nextToken());
            int r=Integer.parseInt(st.nextToken());

            sb.append(appear[find-'a'][r+1]-appear[find-'a'][l]).append('\n');
        }
        
        System.out.println(sb);

        br.close();
    }
}
