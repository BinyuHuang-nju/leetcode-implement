import java.util.*;
public class all1370 {
    static class Solution {
        public String sortString(String s) {
            String result= "";
            char[] chars=s.toCharArray();
            int[] count=new int[26];
            for(char ch:chars){
                count[ch-'a']++;
            }
            int used=0;
            while(used< chars.length){
                for(int i=0;i<26;i++){
                    if(count[i]>0){
                        result=result+(char)(i+'a');
                        used++;
                        count[i]--;
                    }
                }
                for(int i=25;i>=0;i--){
                    if(count[i]>0){
                        result+=(char)(i+'a');
                        used++;
                        count[i]--;
                    }
                }
            }
            return result;
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1370.Solution sol = new all1370.Solution();
        String result=sol.sortString("leetcode");
        System.out.println(result);
    }
}
