import java.util.*;

public class all77 {
    static class Solution {
        List<List<Integer>> results=new ArrayList<>();
        List<Integer> temp=new ArrayList<>();
        public List<List<Integer>> combine(int n, int k) {
            List<List<Integer>> results=new ArrayList<>();
            List<Integer> temp=new ArrayList<>();
            backtrace(results,temp,n,k,1);
            return results;
        }
        private void backtrace(List<List<Integer>> results,List<Integer> temp,int n,int k,int start){
            if(temp.size()==k){
                results.add(new ArrayList<>(temp));
                return;
            }
            int m =n+1-k+temp.size();
            for(int i=start;i<=m;i++){
                temp.add(i);
                backtrace(results,temp,n,k,i+1);
                temp.remove(temp.size()-1);
            }
        }
    }
    public static void main(String[] args){
        all77.Solution sol = new all77.Solution();
        List<List<Integer>> a =sol.combine(5,3);
        System.out.println(a);
    }
}
