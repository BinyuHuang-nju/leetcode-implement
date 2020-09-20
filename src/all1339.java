import java.util.HashMap;
import java.util.Map;

public class all1339 {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    class Solution {
        private double total_sum;
        private double standard;
        private double minDiff;
        private long cur;
        private HashMap<TreeNode,Integer> subsum;
        public int maxProduct(TreeNode root) {
            subsum=new HashMap<>();
            final long M=(long)1e9+7;
            total_sum=computeSum(root);
            minDiff=Double.MAX_VALUE;
            standard=total_sum/2;
            for(Map.Entry<TreeNode,Integer> entry: subsum.entrySet()){
                int x = entry.getValue();
                if(Math.abs(standard-x)<minDiff){
                    minDiff=Math.abs(standard-x);
                    cur=x;
                }
            }
            long another = (long)total_sum-cur;
            return (int)((cur*another)%M);
        }
        private int computeSum(TreeNode root){
            if(root==null)
                return 0;
            subsum.put(root,root.val+computeSum(root.left)+computeSum(root.right));
            return subsum.get(root);
        }
    }
}
