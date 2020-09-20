import java.util.*;
public class all1239 {
    static class Solution {
        public int maxLength(List<String> arr) {

            return traceback(arr,0,0);
        }
        private int traceback(List<String> arr,int start,int mp){
            if(start==arr.size())
                return 0;
            int tag=mp;
            for(int i=0;i<arr.get(start).length();i++){
                int index=arr.get(start).charAt(i)-'a';
                if((mp&(1<<index))>0)
                    return traceback(arr,start+1,tag);
                mp = mp|(1<<index);
            }
            return Math.max(arr.get(start).length()+traceback(arr,start+1,mp),traceback(arr,start+1,tag));
        }
    }
    public static void main(String[] args){
        System.out.println("Hello world!");
        all1239.Solution sol=new all1239.Solution();
        List<String> arr= new ArrayList<String>();
        arr.add("cha");
        arr.add("r");
        arr.add("act");
        arr.add("ers");
        int result = sol.maxLength(arr);
        System.out.println(result);
    }
}
