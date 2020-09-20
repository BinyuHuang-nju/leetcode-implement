import java.util.Arrays;
import java.util.HashMap;

public class all1296 {
    static class Solution {
        public boolean isPossibleDivide(int[] nums, int k) {
            HashMap<Integer,Integer> map=new HashMap<>();
            for(int num:nums){
                if(!map.containsKey(num))
                    map.put(num,1);
                else
                    map.put(num,map.get(num)+1);
            }
            Arrays.sort(nums);
            for(int i=0;i< nums.length;i++){
                if(map.get(nums[i])==0)
                    continue;
                for(int j=nums[i];j<nums[i]+k;j++){
                    if(!map.containsKey(j)||map.get(j)==0)
                        return false;
                    map.put(j,map.get(j)-1);
                }
            }
            return true;
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1296.Solution sol = new all1296.Solution();
        int[] a={3,2,1,2,3,4,3,4,5,9,10,11};
        boolean result = sol.isPossibleDivide(a,3);
        System.out.println(result);
    }
}
