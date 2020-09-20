import java.util.*;
public class all1267 {
    static class Solution {
        int[] parent;
        public int find(int x){
            while(parent[x]>=0)
                x=parent[x];
            return x;
        }
        public void union(int x1,int x2){
            int root1=find(x1),root2=find(x2);
            if(root1!=root2){
                parent[root1]=parent[root1]+parent[root2];
                parent[root2]=root1;
            }
        }
        public int countServers(int[][] grid) {
            int m= grid.length,n=grid[0].length;
            int[] count=new int[m+n];
            List<List<Integer>> computers=new ArrayList<>();
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        List<Integer> temp=new ArrayList<>();
                        temp.add(i);
                        temp.add(j);
                        count[i]++;
                        count[m+j]++;
                        computers.add(temp);
                    }
                }
            }
            int result=0;
            for(List<Integer> computer:computers){
                int x=computer.get(0),y=computer.get(1);
                if(count[x]>1||count[m+y]>1)
                    result++;
            }
            return result;
        }
    }
    public static void main(String[] args){
        System.out.println("Hello world!");
        all1267.Solution sol=new all1267.Solution();
        int[][] a={{1, 1, 0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
        int result = sol.countServers(a);
        System.out.println(result);
    }
}
