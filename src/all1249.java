import java.util.*;
public class all1249 {
    static class Solution {
        public String minRemoveToMakeValid(String s) {
            Stack<Integer> st=new Stack<Integer>();
            StringBuilder result = new StringBuilder();
            boolean[] wasted = new boolean[s.length()];
            char[] chars = s.toCharArray();
            for(int i = 0;i< chars.length;i++){
                if(chars[i]=='('){
                    st.push(i);
                }
                else if(chars[i] == ')'){
                    if(st.empty())
                        wasted[i]=true;
                    else
                        st.pop();
                }
            }
            while(!st.empty()){
                wasted[st.pop()] = true;
            }
            for(int i = 0;i< chars.length;i++) {
                if (!wasted[i])
                    result.append(chars[i]);
            }
            return result.toString();
        }
    }
    public static void main(String[] args){
        System.out.println("Hello world!");
        all1249.Solution sol=new all1249.Solution();
        String result = sol.minRemoveToMakeValid("a)b(c)d");
        System.out.println(result);
    }
}
