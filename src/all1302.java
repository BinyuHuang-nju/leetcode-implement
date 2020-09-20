import java.util.*;

public class all1302 {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    class Solution {
        public int deepestLeavesSum(TreeNode root) {
            if(root==null)
                return 0;
            Queue<TreeNode> queNode=new LinkedList<>();
            TreeNode tag=new TreeNode(-1);
            int sum=0;
            TreeNode p;
            queNode.offer(root);
            queNode.offer(tag);
            while(!queNode.isEmpty()){
                p=queNode.poll();
                sum+=p.val;
                if(p.left!=null)
                    queNode.offer(p.left);
                if(p.right!=null)
                    queNode.offer(p.right);
                if(!queNode.isEmpty()&&queNode.peek()==tag){
                    queNode.poll();
                    if(!queNode.isEmpty()){
                        sum=0;
                        queNode.offer(tag);
                    }
                }
            }
            return sum;
        }
    }
}
