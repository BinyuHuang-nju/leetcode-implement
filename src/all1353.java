import java.util.Arrays;
import java.util.PriorityQueue;

public class all1353 {
    static class Solution {
        public int maxEvents(int[][] events) {
            Arrays.sort(events,((o1, o2) -> o1[0]-o2[0]));
            int i=0,n=events.length,result=0,last=1;
            PriorityQueue<Integer> pq=new PriorityQueue<>();
            while(i<n||!pq.isEmpty()){
                while(i<n&&events[i][0]==last){
                    pq.offer(events[i][1]);
                    i++;
                }
                while(!pq.isEmpty()&&pq.peek()<last){
                    pq.poll();
                }
                if(!pq.isEmpty()){
                    pq.poll();
                    result++;
                }
                last++;
            }
            return result;
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1353.Solution sol = new all1353.Solution();
        int[][] a={{1,4},{4,4},{2,2},{3,4},{1,1}};
        int result = sol.maxEvents(a);
        System.out.println(result);
    }
}
