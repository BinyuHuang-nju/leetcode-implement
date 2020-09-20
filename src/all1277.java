import java.util.List;

public class all1277 {
    static class Solution {
        public int countSquares(int[][] matrix) {
            int m = matrix.length,n = matrix[0].length;
            int[][] dp = new int[m+1][n+1];
            int result = 0;
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    if(matrix[i-1][j-1]==1){
                        dp[i][j]=1+Math.min(Math.min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                        result += dp[i][j];
                    }
                }
            }
            return result;
        }
    }
    public static void main(String[] args){
        all1277.Solution sol = new all1277.Solution();
        int[][] matrix={{0,1,1,1},{1,1,1,1},{0,1,1,1}};
        int a =sol.countSquares(matrix);
        System.out.println(a);
    }
}
