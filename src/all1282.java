import java.util.*;
public class all1282 {
    static class Solution {
        public List<List<Integer>> groupThePeople(int[] groupSizes) {
            HashMap<Integer,List<Integer>> map=new HashMap<>();
            for(int i=0;i< groupSizes.length;i++){
                map.get(groupSizes[i]).add(i);
            }
            List<List<Integer>> result=new ArrayList<>();
            for(Map.Entry<Integer,List<Integer>> entry:map.entrySet()){
                int group_size=entry.getKey();
                int cur=0;
                List<Integer> list = entry.getValue();
                List<Integer> l =new ArrayList<>();
                for(Integer x:list){
                    l.add(x);
                    cur++;
                    if(cur==group_size){
                        result.add(l);
                        l.clear();
                        cur=0;
                    }
                }
            }
            return result;
        }
    }
    public static void main(String[] args){
        System.out.println("Hello world!");
        all1282.Solution sol=new all1282.Solution();
        int[] a={3,3,3,3,3,1,3};
        List<List<Integer>> result = sol.groupThePeople(a);
        System.out.println(result);
    }
}
