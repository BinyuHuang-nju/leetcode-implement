import java.util.*;
public class all1235 {
    static class Solution {

        class Job{
            int starttime;
            int endtime;
            int profit;
            public Job(){
                starttime=endtime=profit=0;
            }
            public Job(int s,int e,int p){
                starttime=s;
                endtime=e;
                profit=p;
            }
        }
        public Comparator<Job> comparatorJob=new Comparator<Job>() {
            @Override
            public int compare(Job o1, Job o2) {
                if(o1.endtime>o2.endtime)
                    return 1;
                else if(o1.endtime<o2.endtime)
                    return -1;
                return 0;
            }
        };
        public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
            int len= startTime.length;
            Job[] jobs=new Job[len];
            for(int i=0;i<len;i++){
                jobs[i]=new Job(startTime[i],endTime[i],profit[i]);
            }
            Arrays.sort(jobs,comparatorJob);
            int[] dp=new int[len];
            dp[0]=jobs[0].profit;
            for(int i=1;i<len;i++){
                int j=i-1;
                for(;j>=0;j--){
                    if(jobs[j].endtime<=jobs[i].starttime)
                        break;
                }
                if(j<0)
                    dp[i]=Math.max(jobs[i].profit,dp[i-1]);
                else
                    dp[i]=Math.max(dp[i-1],dp[j]+jobs[i].profit);
            }
            return dp[len-1];
        }
    }
    public static void main(String[] args){
        System.out.println("Hello world!");
        all1235.Solution sol=new all1235.Solution();
        int[] a={1,2,3,4,6};
        int[] b ={3,5,10,6,9};
        int[] c={20,20,100,70,60};
        int result = sol.jobScheduling(a,b,c);
        System.out.println(result);
    }
}
