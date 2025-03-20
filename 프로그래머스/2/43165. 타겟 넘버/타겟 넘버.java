class Solution {
    static int[] numbers;
    static int target;
    public int solution(int[] numbers, int target) {
        this.numbers=numbers;
        this.target=target;
        
        return dfs(0,0);
    }
    static int dfs(int N, int sum){
        if (N==numbers.length){
            if (sum==target) return 1;
            else return 0;
        }
        
        return dfs(N+1,sum+numbers[N])+dfs(N+1,sum-numbers[N]);
    }
}