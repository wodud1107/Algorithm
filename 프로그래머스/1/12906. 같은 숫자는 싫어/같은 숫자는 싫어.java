import java.util.*;

public class Solution {
    public Stack<Integer> solution(int[] arr){
        Stack<Integer> stack=new Stack<>();

        stack.add(arr[0]);
        for (int i=1; i<arr.length; i++){
            if (stack.peek()==arr[i]) continue;
            else stack.add(arr[i]);
        }

        return stack;
    }
}