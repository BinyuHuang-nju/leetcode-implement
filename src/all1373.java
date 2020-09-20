public class all1373 {
    static public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() { }
        TreeNode(int val) {
            this.val = val;
        }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    static class Solution {  // false, look C++
        private int max;
        public int maxSumBST(TreeNode root) {
            max=0;
            subtree(root);
            return max;
        }
        private int subtree(TreeNode root){
            if(root==null)
                return 0;
            if(root.left==null&&root.right==null){
                max=Math.max(max,root.val);
                return root.val;
            }
            int l=subtree(root.left),r=subtree(root.right);
            if((root.left!=null&&root.left.val>root.val)||(root.right!=null&&root.right.val<root.val)||l==-1||r==-1)
                return -1;
            max=Math.max(max,root.val+l+r);
            return root.val+l+r;
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1373.Solution sol = new all1373.Solution();
        TreeNode p1=new TreeNode(1);
        TreeNode p2=new TreeNode(5);
        TreeNode p3=new TreeNode(10);
        TreeNode p4=new TreeNode(7);
        TreeNode p5=new TreeNode(5);
        TreeNode p6=new TreeNode(10);
        TreeNode p7=new TreeNode(7);
        TreeNode p8=new TreeNode(9);
        p1.right=p2;
        p2.left=p3;
        p2.right=p4;
        p4.left=p5;
        p4.right=p6;
        p5.right=p7;
        p7.right=p8;
        int result=sol.maxSumBST(p1);
        System.out.println(result);
    }
}
