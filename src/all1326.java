import java.util.Arrays;

public class all1326 {
    static class Solution1 {
        public int minTaps(int n, int[] ranges) {
            int[] prev=new int[n+1];
            for(int i=0;i<=n;i++)
                prev[i]=i;
            for(int i=0;i< ranges.length;i++){
                int l=Math.max(0,i-ranges[i]),r=Math.min(n,i+ranges[i]);
                prev[r]=Math.min(prev[r],l);
            }
            int[] dp=new int[n+1];
            Arrays.fill(dp,Integer.MAX_VALUE);
            dp[0]=0;
            for(int i=1;i<=n;i++){
                if(prev[i]==0)
                    dp[i]=1;
                else{
                    for(int j=prev[i];j<i;j++)
                        if(dp[j]!=Integer.MAX_VALUE)
                            dp[i]=Math.min(dp[i],dp[j]+1);
                }
            }
            return dp[n]==Integer.MAX_VALUE?-1:dp[n];
        }
    }
    static class Solution2 {
        public int minTaps(int n, int[] ranges) {
            int[] prev=new int[n+1];
            for(int i=0;i<=n;i++)
                prev[i]=i;
            for(int i=0;i< ranges.length;i++){
                int l=Math.max(0,i-ranges[i]),r=Math.min(n,i+ranges[i]);
                prev[r]=Math.min(prev[r],l);
            }
            int furthest=Integer.MAX_VALUE,breakpoint=n;
            int result = 0;
            for(int i=n;i>0;i--){
                furthest=Math.min(furthest,prev[i]);
                if(i==breakpoint){
                    if(furthest>=i)
                        return -1;
                    breakpoint=furthest;
                    result++;
                }
            }
            return result;
        }
    }
    static class Solution {
        public int minTaps(int n, int[] ranges) {
            int[] latter=new int[n+1];
            for(int i=0;i<=n;i++)
                latter[i]=i;
            for(int i=0;i< ranges.length;i++){
                int l=Math.max(0,i-ranges[i]),r=Math.min(n,i+ranges[i]);
                latter[l]=Math.max(latter[l],r);
            }
            int furthest=0,breakpoint=0;
            int result=0;
            for(int i=0;i<n;i++){
                furthest=Math.max(furthest,latter[i]);
                if(i==breakpoint){
                    if(furthest<=i)
                        return -1;
                    breakpoint=furthest;
                    result++;
                }
            }
            return result;
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1326.Solution sol = new all1326.Solution();
        int[] a={1,2,1,0,2,1,0,1};
        int result = sol.minTaps(7,a);
        System.out.println(result);
    }
}
