import java.util.*;
public class all1221 {
    static class Solution {
        public int balancedStringSplit(String s) {
            int result=0;
            int l=0,r=0;
            char[] chs=s.toCharArray();
            for(char ch:chs){
                if(ch=='L')
                    l++;
                else
                    r++;
                if(l==r){
                    result++;
                    l=r=0;
                }
            }
            return result;
        }
    }
    public static void main(String[] args){
        System.out.println("Hello world!");
        all1221.Solution sol=new all1221.Solution();
        int result = sol.balancedStringSplit("RLLLLRRRLR");
        System.out.println(result);
    }
}
