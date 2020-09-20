import java.util.ArrayList;
import java.util.List;

public class all1286 {
    static class CombinationIterator {
        private List<String> results=new ArrayList<>();
        private String chars;
        private int cur = 0;

        public CombinationIterator(String characters, int combinationLength) {
            chars=characters;
            String temp = new String();
            backtrace(temp,combinationLength,0);
        }

        public String next() {
            String str=results.get(cur);
            cur++;
            return str;
        }

        public boolean hasNext() {
            return cur<results.size();
        }
        private void backtrace(String temp,int combineLength,int begin){
            if(temp.length()==combineLength){
                results.add(temp);
                return;
            }
            int m =chars.length()+1-combineLength+temp.length();
            for(int i=begin;i<m;i++){
                backtrace(temp+chars.charAt(i),combineLength,i+1);
            }
        }
    }
    public static void main(String[] args){
        all1286.CombinationIterator sol = new all1286.CombinationIterator("abcde",3);
        String param_1 = sol.next();
        boolean param_2 = sol.hasNext();
        String param_3 = sol.next();
        boolean param_4 = sol.hasNext();
        System.out.println(param_1);
        System.out.println(param_2);
        System.out.println(param_3);
        System.out.println(param_4);
    }
}
