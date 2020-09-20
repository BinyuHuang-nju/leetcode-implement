public class all1319 {
    static class Solution {
        private int[] parent;
        private int find(int x){
            while(parent[x]>=0)
                x=parent[x];
            return x;
        }
        private void union(int x1,int x2){
            int root1=find(x1),root2=find(x2);
            if(root1!=root2){
                int temp=parent[root1]+parent[root2];
                if(parent[root1]<parent[root2]){
                    parent[root1]=temp;
                    parent[root2]=root1;
                }
                else{
                    parent[root2]=temp;
                    parent[root1]=root2;
                }
            }
        }
        public int makeConnected(int n, int[][] connections) {
            if(connections.length<n-1)
                return -1;
            parent=new int[n];
            for(int i=0;i<n;i++)
                parent[i]=-1;
            for(int[] connection:connections){
                union(connection[0],connection[1]);
            }
            int count=0;
            for(int i=0;i<n;i++)
                if(parent[i]<0)
                    count++;
            return count-1;
        }
    }
    public static void main(String[] args){
        all1319.Solution sol = new all1319.Solution();
        int[][] matrix={{0,1},{0,2},{1,2}};
        int a =sol.makeConnected(4,matrix);
        System.out.println(a);
    }
}
