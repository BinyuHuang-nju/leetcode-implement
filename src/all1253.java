import java.util.*;
public class all1253 {
    static class Solution {
        public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
            int remain0 = upper,remain1 = lower;
            List<List<Integer>> result=new ArrayList<>();
            int[][] temp = new int[2][colsum.length];
            for(int i=0;i< colsum.length;i++){
                if(colsum[i]==2){
                    if(remain0==0||remain1==0)
                        return result;
                    temp[0][i]=temp[1][i]=1;
                    remain0--;
                    remain1--;
                }
                else if(colsum[i]==1){
                    if(remain0==0&&remain1==0)
                        return result;
                    if(remain0>=remain1){
                        temp[0][i]=1;
                        remain0--;
                    }
                    else{
                        temp[1][i]=1;
                        remain1--;
                    }
                }
            }
            if(remain0>0||remain1>0)
                return result;
            for(int[] tmp:temp){
                List<Integer> list = new ArrayList<>();
                for(int val:tmp)
                    list.add(val);
                result.add(list);
            }
            return result;
        }

    }
    public static void main(String[] args){
        System.out.println("Hello world!");
        all1253.Solution sol=new all1253.Solution();
        int[] a={2,1,2,0,1,0,1,2,0,1};
        List<List<Integer>> result = sol.reconstructMatrix(5,5,a);
        System.out.println(result);
    }
}
