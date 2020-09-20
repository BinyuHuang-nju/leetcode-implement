import java.util.Arrays;

public class all1335 {
    static class Solution1 {
        public int minDifficulty(int[] jobDifficulty, int d) {
            int jobs= jobDifficulty.length;
            if(d>jobs)
                return -1;
            int[][] dp=new int[d][jobs];
            for(int j=0;j<jobs;j++){
                if(j==0)
                    dp[0][0]=jobDifficulty[0];
                else
                    dp[0][j]=Math.max(jobDifficulty[j],dp[0][j-1]);
            }
            for(int i=1;i<d;i++){
                Arrays.fill(dp[i],Integer.MAX_VALUE);
                for(int j=i;j<jobs;j++){
                    int maxVal=Integer.MIN_VALUE;
                    for(int k=j;k>=i;k--){
                        maxVal=Math.max(maxVal,jobDifficulty[k]);
                        dp[i][j]=Math.min(dp[i][j],dp[i-1][k-1]+maxVal);
                    }
                }
            }
            return dp[d-1][jobs-1];
        }
    }
    static class Solution {
        public int minDifficulty(int[] jobDifficulty, int d) {
            int jobs= jobDifficulty.length;
            if(d>jobs)
                return -1;
            int[][] dp=new int[d][jobs];
            for(int j=0;j<=jobs-d;j++){
                if(j==0)
                    dp[0][0]=jobDifficulty[0];
                else
                    dp[0][j]=Math.max(jobDifficulty[j],dp[0][j-1]);
            }
            for(int i=1;i<d;i++){
                Arrays.fill(dp[i],Integer.MAX_VALUE);
                for(int j=i;j<=i+jobs-d;j++){
                    int maxVal=Integer.MIN_VALUE;
                    for(int k=j;k>=i;k--){
                        maxVal=Math.max(maxVal,jobDifficulty[k]);
                        dp[i][j]=Math.min(dp[i][j],dp[i-1][k-1]+maxVal);
                    }
                }
            }
            return dp[d-1][jobs-1];
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1335.Solution sol = new all1335.Solution();
        int[] a={11,111,22,222,33,333,44,444};
        int result = sol.minDifficulty(a,6);
        System.out.println(result);
    }
}
