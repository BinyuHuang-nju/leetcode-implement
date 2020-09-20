import java.util.*;
public class all1301 {
    static class Solution {
        public int[] pathsWithMaxScore(List<String> board) {
            final int M=(int)1e9+7;
            int n = board.size();
            long[][] cost=new long[n][n];
            long[][] paths=new long[n][n];
            paths[n-1][n-1]=1;
            for(int i = n-2;i>=0;i--){
                if(board.get(i).charAt(n-1)=='X')
                    cost[i][n-1]=-1;
                else{
                    if(cost[i+1][n-1]==-1)
                        cost[i][n-1]=-1;
                    else{
                        cost[i][n-1]=cost[i+1][n-1]+board.get(i).charAt(n-1)-'0';
                        paths[i][n-1]=1;
                    }
                }
            }
            for(int j = n-2;j>=0;j--){
                if(board.get(n-1).charAt(j)=='X')
                    cost[n-1][j]=-1;
                else{
                    if(cost[n-1][j+1]==-1)
                        cost[n-1][j]=-1;
                    else{
                        cost[n-1][j]=cost[n-1][j+1]+board.get(n-1).charAt(j)-'0';
                        paths[n-1][j]=1;
                    }
                }
            }
            for(int i=n-2;i>=0;i--){
                for(int j=n-2;j>=0;j--){
                    if(board.get(i).charAt(j)=='X'){
                        cost[i][j]=-1;
                    }
                    else{
                        int val=(i==0&&j==0)?0:board.get(i).charAt(j)-'0';
                        if(cost[i][j+1]==-1&&cost[i+1][j]==-1){
                            cost[i][j]=cost[i+1][j+1]==-1?-1:(cost[i+1][j+1]+val);
                            paths[i][j]=cost[i+1][j+1]==-1?0:paths[i+1][j+1];
                        }
                        else{
                            if(cost[i][j+1]!=-1&&cost[i+1][j]!=-1){
                                if(cost[i][j+1]==cost[i+1][j]){
                                    cost[i][j]=cost[i][j+1]+val;
                                    paths[i][j]=(paths[i+1][j]+paths[i][j+1])%M;
                                }
                                else{
                                    cost[i][j]=Math.max(cost[i][j+1],cost[i+1][j])+val;
                                    paths[i][j]=cost[i][j+1]>cost[i+1][j]?paths[i][j+1]:paths[i+1][j];
                                }
                            }
                            else{
                                cost[i][j]=(cost[i][j+1]==-1?cost[i+1][j]:cost[i][j+1])+val;
                                paths[i][j]=cost[i][j+1]==-1?paths[i+1][j]:paths[i][j+1];
                            }
                        }
                    }
                }
            }
            if(paths[0][0]==0)
                return new int[]{0, 0};
            return new int[]{(int)(cost[0][0]%M),(int)(paths[0][0])};
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1301.Solution sol = new all1301.Solution();
        List<String> a=new ArrayList<>();
        String a1="E999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"
                ,a2="9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999",
                a3="999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999S";
        a.add(a1);
        for(int i=0;i<98;i++)
            a.add(a2);
        a.add(a3);
        int[] result = sol.pathsWithMaxScore(a);
        System.out.println(result);
    }
}