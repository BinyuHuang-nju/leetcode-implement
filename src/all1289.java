public class all1289 {
    static class Solution {
        public int minFallingPathSum(int[][] arr) {
            int len1=arr.length,len2=arr[0].length;
            int[][] dp=new int[len1][len2];
            for(int j=0;j<len2;j++)
                dp[0][j]=arr[0][j];
            for(int i=1;i<len1;i++){
                for(int j=0;j<len2;j++){
                    dp[i][j]=Integer.MAX_VALUE;
                    for(int k=0;k<len2;k++)
                        if(j!=k)
                            dp[i][j]=Math.min(dp[i][j],dp[i-1][k]+arr[i][j]);
                }
            }
            int min_path = Integer.MAX_VALUE;
            for(int j=0;j<len2;j++)
                min_path=Math.min(min_path,dp[len1-1][j]);
            return min_path;
        }
    }
    public static void main(String[] args){
        System.out.println("Hello world!");
        all1289.Solution sol=new all1289.Solution();
        int[][] a={{1, 2,3},{4,5,6},{7,8,9}};
        int result = sol.minFallingPathSum(a);
        System.out.println(result);
    }
}
