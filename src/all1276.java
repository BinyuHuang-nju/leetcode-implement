import java.util.*;

public class all1276 {
    static class Solution0 {
        public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
            List<Integer> list = new ArrayList<>();
            int tmp = tomatoSlices-2*cheeseSlices;
            if(tmp<0||tmp%2!=0)
                return list;
            int x = tmp/2;
            if(x>cheeseSlices)
                return list;
            int y = cheeseSlices-x;
            list.add(x);
            list.add(y);
            return list;
        }
    }

    static class Solution1 {
        public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
            List<Integer> list = new ArrayList<>();
            for(int i = 0;tomatoSlices-4*i>=0&&cheeseSlices-i>=0;i++){
                int y1 = tomatoSlices-4*i,y2=cheeseSlices-i;
                if(y1==2*y2){
                    list.add(i);
                    list.add(y2);
                    return list;
                }
            }
            return list;
        }
    }

    static class Solution {
        int x,y;
        public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
            List<Integer> list = new ArrayList<>();
            boolean can_allocate = allocate(0,0,tomatoSlices,cheeseSlices);
            if(can_allocate){
                list.add(x);
                list.add(y);
                return list;
            }
            return list;
        }
        boolean allocate(int big,int small,int remain_tomatos,int remain_cheeses){
            if(remain_tomatos==0&&remain_cheeses==0){
                x=big;
                y=small;
                return true;
            }
            if(remain_tomatos<0||remain_cheeses<0)
                return false;
            if(allocate(big+1,small,remain_tomatos-4,remain_cheeses-1))
                return true;
            if(allocate(big,small+1,remain_tomatos-2,remain_cheeses-1))
                return true;
            return false;
        }
    }
    public static void main(String[] args){
        Solution sol = new Solution();
        List<Integer> a =sol.numOfBurgers(16,7);
        System.out.println(a);
    }
}
