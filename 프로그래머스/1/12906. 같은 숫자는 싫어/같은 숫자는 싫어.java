import java.util.*;

public class Solution {
    public ArrayDeque<Integer> solution(int[] arr){
        ArrayDeque<Integer> queue=new ArrayDeque<>();

        queue.add(arr[0]);
        for (int i=1; i<arr.length; i++){
            if (queue.peekLast()==arr[i]) continue;
            else queue.add(arr[i]);
        }

        return queue;
    }
}