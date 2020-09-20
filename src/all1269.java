public class all1269 {
    static class Solution0 {
        long result = 0;
        int M=(int)1e9+7;
        public int numWays(int steps, int arrLen) {
            dfs(arrLen,0,steps);
            return (int)result;
        }
        void dfs(int arrLen,int site,int remain_steps){
            if(site>remain_steps)
                return;
            if(remain_steps==0){
                if(site==0)
                    result=(result+1)%M;
                return;
            }
            if(site>0)
                dfs(arrLen,site-1,remain_steps-1);
            dfs(arrLen,site,remain_steps-1);
            if(site<arrLen-1)
                dfs(arrLen,site+1,remain_steps-1);
        }
    }
    static class Solution {
        //long result = 0;
        int M=(int)1e9+7;
        public int numWays(int steps, int arrLen) {
            int frontier=Math.min(steps,arrLen-1);
            long[][] dp = new long[frontier+1][steps+1];
            dp[0][0]=1;
            dfs(frontier,0,steps,dp);
            return (int)dp[0][steps];
        }
        int dfs(int frontier,int site,int remain_steps,long[][] dp){
            if(site>remain_steps)
                return 0;
            if(remain_steps==0){ // site must be 0
                    return 1;
            }
            if(dp[site][remain_steps]>0)
                return (int)dp[site][remain_steps];
            if(site>0)
                dp[site][remain_steps]+=dfs(frontier,site-1,remain_steps-1,dp);
            dp[site][remain_steps]+=dfs(frontier,site,remain_steps-1,dp);
            if(site<frontier)
                dp[site][remain_steps]+=dfs(frontier,site+1,remain_steps-1,dp);
            dp[site][remain_steps]=dp[site][remain_steps]%M;
            return (int)dp[site][remain_steps];
        }
    }
    public static void main(String[] args){
        System.out.println("Hello world!");
        all1269.Solution sol=new all1269.Solution();
        int result = sol.numWays(4,2);
        System.out.println(result);
    }
}
