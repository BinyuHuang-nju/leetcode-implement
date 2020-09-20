import java.util.Arrays;

public class all1320 {
    static class Solution {
        public int minimumDistance(String word) {
            int[][] coor={
                    {0,0},{0,1},{0,2},{0,3},{0,4},{0,5},
                    {1,0},{1,1},{1,2},{1,3},{1,4},{1,5},
                    {2,0},{2,1},{2,2},{2,3},{2,4},{2,5},
                    {3,0},{3,1},{3,2},{3,3},{3,4},{3,5},
                    {4,0},{4,1}
            };
            int len=word.length();
            char[] chars=word.toCharArray();
            int[][] dp=new int[len][len];
            for(int i=1;i<len;i++){
                Arrays.fill(dp[i], Integer.MAX_VALUE);

                dp[i][i]=dp[i-1][i-1]+distance(coor[chars[i-1]-'A'],coor[chars[i]-'A']);
                dp[i][i-1]=dp[i-1][i-1];

                for(int j=0;j<i-1;j++){
                    dp[i][j]=Math.min(dp[i][j],dp[i-1][j]+distance(coor[chars[i-1]-'A'],coor[chars[i]-'A']));
                    dp[i][i-1]=Math.min(dp[i][i-1],dp[i-1][j]+distance(coor[chars[j]-'A'],coor[chars[i]-'A']));
                }
            }
            int result=Integer.MAX_VALUE;
            for(int i=0;i<len-1;i++)
                result=Math.min(result,dp[len-1][i]);
            return result;
        }
        private int distance(int[] p1,int[] p2){
            return Math.abs(p1[0]-p2[0])+Math.abs(p1[1]-p2[1]);
        }

    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1320.Solution sol = new all1320.Solution();

        int result = sol.minimumDistance("YEAR");
        System.out.println(result);
    }
}
