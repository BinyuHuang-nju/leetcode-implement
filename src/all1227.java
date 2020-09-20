public class all1227 {
    static class Solution {
        public double nthPersonGetsNthSeat(int n) {
            if(n==1)
                return 1.0;
            if(n==2)
                return 0.5;
            return (double)1/n+(double)(n-2)/n*nthPersonGetsNthSeat(n-1);
        }
    }
    public static void main(String[] args){
        System.out.println("Hello world!");
        all1227.Solution sol=new all1227.Solution();
        double result = sol.nthPersonGetsNthSeat(15);
        System.out.println(result);
    }
}
