import java.util.Collections;
import java.util.PriorityQueue;

public class all1354 {
    static class Solution {
        public boolean isPossible(int[] target) {
            PriorityQueue<Integer> pq=new PriorityQueue<>(Collections.reverseOrder());
            int sum=0;
            for(int digit:target){
                sum=sum+digit;
                pq.offer(digit);
            }
            while(sum!= target.length){
                int max= pq.poll();
                int pre = max-(sum-max);
                if(pre>=max||pre<1)
                    return false;
                pq.offer(pre);
                sum=max;
            }
            return true;
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1354.Solution sol = new all1354.Solution();
        int[] a={9,3,5};
        boolean result = sol.isPossible(a);
        System.out.println(result);
    }
}
