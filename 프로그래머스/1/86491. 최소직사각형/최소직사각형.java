class Solution {
    public int solution(int[][] sizes) {
        int w_max=Integer.MIN_VALUE, h_max=Integer.MIN_VALUE;

        for (int[] length : sizes){
            int w=Math.max(length[0], length[1]);
            int h=Math.min(length[0], length[1]);

            w_max=Math.max(w_max, w);
            h_max=Math.max(h_max, h);
        }

        return w_max*h_max;
    }
}