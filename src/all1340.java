public class all1340 {
    static class Solution {
        private int[] memory;
        public int maxJumps(int[] arr, int d) {
            int len=arr.length;
            memory=new int[len];
            int max=1;
            for(int i=0;i<len;i++){
                if(memory[i]==0)
                    dfs(arr,d,i);
                max=Math.max(max,memory[i]);
            }
            return max;
        }
        private int dfs(int[] arr,int d,int pos){
            if(memory[pos]!=0)
                return memory[pos];
            int result = 1;
            for(int i=pos-1;i>=0 && pos-i<=d;i--){
                if(arr[i]>=arr[pos])
                    break;
                result=Math.max(result,1+dfs(arr,d,i));
            }
            for(int i=pos+1;i<arr.length&&i-pos<=d;i++){
                if(arr[i]>=arr[pos])
                    break;
                result=Math.max(result,1+dfs(arr,d,i));
            }
            memory[pos]=result;
            return result;
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1340.Solution sol = new all1340.Solution();
        int[] a={6,4,14,6,8,13,9,7,10,6,12};
        int result = sol.maxJumps(a,2);
        System.out.println(result);
    }
}
