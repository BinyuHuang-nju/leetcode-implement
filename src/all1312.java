import java.util.List;

public class all1312 {
    static class Solution {
        public int minInsertions(String s) {
            int len=s.length();
            int[][] dp=new int[len][len];
            for(int i=len-1;i>=0;i--){
                dp[i][i]=1;
                for(int j=i+1;j<len;j++){
                    if(s.charAt(i)==s.charAt(j))
                        dp[i][j]=dp[i+1][j-1]+2;
                    else
                        dp[i][j]=Math.max(dp[i+1][j],dp[i][j-1]);
                }
            }
            return len-dp[0][len-1];
        }
    }
    public static void main(String[] args){
        all1312.Solution sol = new all1312.Solution();
        int a= sol.minInsertions("mbadm");
        System.out.println(a);
    }
}
