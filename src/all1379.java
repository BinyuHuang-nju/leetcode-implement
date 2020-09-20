public class all1379 {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    class Solution {
        public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
            if(original==null)
                return null;
            if(original== target)
                return cloned;
            TreeNode node=null;
            if(original.left!=null){
                node = getTargetCopy(original.left,cloned.left,target);
                if(node!=null)
                    return node;
            }
            if(original.right!=null){
                node = getTargetCopy(original.right,cloned.right,target);
                if(node!=null)
                    return node;
            }
            return null;
        }
    }
}