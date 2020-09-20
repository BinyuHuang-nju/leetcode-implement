public class all1359 {
    static class Solution1 {
        private long result =0;
        private long M=(long)1e9+7;
        public int countOrders(int n) {
            int[] order=new int[n];
            backtrace(order,0,n);
            return (int)result;
        }
        void backtrace(int[] order,int steps,int len){
            if(steps==2*len){
                result=(result+1)%M;
                return;
            }
            for(int i=0;i<len;i++){
                if(order[i]==2)
                    continue;
                order[i]++;
                backtrace(order,steps+1,len);
                order[i]--;
            }
        }
    }

    static class Solution {
        public int countOrders(int n) {
            long M=(long)1e9+7;
            long result = 1;
            for(int i=2;i<=n;i++){
                result = result*i%M*(2*i-1)%M;
            }
            return (int)result;
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1359.Solution sol = new all1359.Solution();
        int result = sol.countOrders(3);
        System.out.println(result);
    }
}
