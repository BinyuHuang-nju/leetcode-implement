public class all1314 {
    static class Solution {
        public int[][] matrixBlockSum(int[][] mat, int K) {
            int m= mat.length,n=mat[0].length;
            int[][] partSum=new int[m+1][n+1];
            for(int i=1;i<=m;i++){
                int part=0;
                for(int j=1;j<=n;j++){
                    part+=mat[i-1][j-1];
                    partSum[i][j]=partSum[i-1][j]+part;
                }
            }
            int[][] result=new int[m][n];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    int up=Math.max(0,i-K),down=Math.min(m-1,i+K);
                    int left=Math.max(0,j-K),right=Math.min(n-1,j+K);
                    result[i][j]=partSum[down+1][right+1]+partSum[up][left]-partSum[up][right+1]-partSum[down+1][left];
                }
            }
            return result;
        }
    }
    public static void main(String[] args){
        all1314.Solution sol = new all1314.Solution();
        int[][] matrix={{1,2,3},{4,5,6},{7,8,9}};
        int[][] a =sol.matrixBlockSum(matrix,2);
        System.out.println(a);
    }
}
