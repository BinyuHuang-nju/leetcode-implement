import java.util.*;
public class all1223 {
    static class Solution {
        public int dieSimulator(int n, int[] rollMax) {
            final int M=1000000007;
            int maxCount=1;
            for(int i=0;i<6;i++)
                maxCount=Math.max(maxCount,rollMax[i]);
            long[][][] dp=new long[n+1][6][maxCount+1];
            for(int j=0;j<6;j++)
                dp[1][j][1]=1;
            for(int i=2;i<=n;i++){
                for(int j=0;j<6;j++){
                    for(int m=0;m<6;m++){
                        if(m==j)
                            continue;
                        for(int k=1;k<=rollMax[m];k++)
                            dp[i][j][1]=(dp[i][j][1]+dp[i-1][m][k])%M;
                    }
                    for(int k=2;k<=rollMax[j];k++)
                        dp[i][j][k]=dp[i-1][j][k-1];
                }
            }
            long result=0;
            for(int j=0;j<6;j++){
                for(int k=1;k<=rollMax[j];k++)
                    result=(result+dp[n][j][k])%M;
            }
            return (int)result;
        }
    }
    public static void main(String[] args){
        System.out.println("Hello world!");
        all1223.Solution sol=new all1223.Solution();
        int[] a={1,1,1,2,2,3};
        int result = sol.dieSimulator(3,a);
        System.out.println(result);
    }
}
