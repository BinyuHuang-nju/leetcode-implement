public class all1262 {
    static class Solution {
        public int maxSumDivThree(int[] nums) {
            int len= nums.length;
            int[][] dp=new int[len][3];
            dp[0][nums[0]%3]=nums[0];
            for(int i=1;i<len;i++){
                if(nums[i]%3==0){
                    dp[i][0]=dp[i-1][0]+nums[i];
                    if(dp[i-1][1]!=0)
                        dp[i][1]=dp[i-1][1]+nums[i];
                    if(dp[i-1][2]!=0)
                        dp[i][2]=dp[i-1][2]+nums[i];
                }
                else if(nums[i]%3==1){
                    if(dp[i-1][2]==0)
                        dp[i][0]=dp[i-1][0];
                    else
                        dp[i][0]=Math.max(dp[i-1][0],dp[i-1][2]+nums[i]);
                    dp[i][1]=Math.max(dp[i-1][1],dp[i-1][0]+nums[i]);
                    if(dp[i-1][1]==0)
                        dp[i][2]=dp[i-1][2];
                    else
                        dp[i][2]=Math.max(dp[i-1][2],dp[i-1][1]+nums[i]);
                }
                else{
                    if(dp[i-1][1]==0)
                        dp[i][0]=dp[i-1][0];
                    else
                        dp[i][0]=Math.max(dp[i-1][0],dp[i-1][1]+nums[i]);
                    if(dp[i-1][2]==0)
                        dp[i][1]=dp[i-1][1];
                    else
                        dp[i][1]=Math.max(dp[i-1][1],dp[i-1][2]+nums[i]);
                    dp[i][2]=Math.max(dp[i-1][2],dp[i-1][0]+nums[i]);
                }
            }
            return dp[len-1][0];
        }
    }
    public static void main(String[] args){
        System.out.println("Hello world!");
        all1262.Solution sol=new all1262.Solution();
        int[] a={3,6,5,1,8};
        int result = sol.maxSumDivThree(a);
        System.out.println(result);
    }
}
