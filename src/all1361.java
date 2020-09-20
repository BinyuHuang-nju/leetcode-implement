import java.util.Arrays;

public class all1361 {
    static class Solution {
        private int[] parent;
        int find(int x){
            while(parent[x]>=0)
                x=parent[x];
            return x;
        }
        boolean union(int x1,int x2){
            int root1=find(x1),root2=find(x2);
            if(root1==root2)
                return false;
            parent[root1]=parent[root1]+parent[root2];
            parent[root2]=root1;
            return true;
        }
        public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
            parent=new int[n];
            Arrays.fill(parent,-1);
            for(int i=0;i<n;i++){
                if(leftChild[i]!=-1){
                    if(!union(i, leftChild[i]))
                        return false;
                }
                if(rightChild[i]!=-1){
                    if(!union(i,rightChild[i]))
                        return false;
                }
            }
            int branches=0;
            for(int i=0;i<n;i++) {
                if (parent[i] < 0)
                    branches++;
            }
            return (branches==1);
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1361.Solution sol = new all1361.Solution();
        //int[] a={1,-1,3,-1},b={2,3,-1,-1};
        int[] a={1,0},b={-1,-1};
        boolean result = sol.validateBinaryTreeNodes(2,a,b);
        System.out.println(result);
    }
}
