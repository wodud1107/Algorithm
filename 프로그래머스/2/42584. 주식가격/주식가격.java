import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        
        Stack<Integer> stack=new Stack<>();
        for (int i=0; i<prices.length; i++){
            while(!stack.isEmpty() && prices[stack.peek()] > prices[i]){
                int top=stack.pop();
                answer[top]=i-top;
            }
            stack.push(i);
        }
        
        while(!stack.isEmpty()){
            int top=stack.pop();
            answer[top]=prices.length-1-top;
        }
        
        return answer;
    }
}