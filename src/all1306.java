public class all1306 {
    static class Solution {
        public boolean canReach(int[] arr, int start) {
            if(start<0||start>=arr.length||arr[start]<0)
                return false;
            if(arr[start]==0)
                return true;
            int l=start-arr[start],r=start+arr[start];
            arr[start]=-arr[start];
            return canReach(arr,l)||canReach(arr,r);
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1306.Solution sol = new all1306.Solution();
        int[] a={4,2,3,0,3,1,2};
        boolean result = sol.canReach(a,5);
        System.out.println(result);
    }
}
