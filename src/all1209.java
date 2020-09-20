import java.util.*;
public class all1209 {
    static class Solution {
        class Item{
            char present;
            int num;
            public Item(char p){
                present=p;
                num=1;
            }
        }
        public String removeDuplicates(String s, int k) {
            Stack<Item> st=new Stack<Item>();
            char[] chars=s.toCharArray();
            for(int i=0;i<chars.length;i++){
                if(st.empty()||st.peek().present!=chars[i]){
                    Item temp=new Item(chars[i]);
                    st.push(temp);
                }
                else{
                    st.peek().num++;
                    if(st.peek().num==k){
                        st.pop();
                    }
                }
            }
            String result="";
            while (!st.empty()) {
                for (int i = 0; i < st.peek().num; i++)
                    result = st.peek().present + result;
                st.pop();
            }
            return result;
        }
    }
    public static void main(String[] args){
        System.out.println("Hello world!");
        Solution sol=new Solution();
        String result = sol.removeDuplicates("pbbcggttciiippooaais",2);
        System.out.println(result);
    }
}