import java.util.HashMap;

public class all1372 {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    static class Solution {
        private HashMap<TreeNode,Integer> longestLeft;
        private HashMap<TreeNode,Integer> longestRight;
        private int max;
        public int longestZigZag(TreeNode root) {
            longestLeft=new HashMap<>();
            longestRight=new HashMap<>();
            max=0;
            longest(root,1);
            return max;
        }
        private int longest(TreeNode root,int left){
            if(root==null)
                return 0;
            if(!longestRight.containsKey(root)) {
                if (root.right == null) {
                    longestRight.put(root, 0);
                } else
                    longestRight.put(root, 1+longest(root.right, 2));
                max = Math.max(max, longestRight.get(root));
            }

            if(!longestLeft.containsKey(root)) {
                if (root.left == null)
                    longestLeft.put(root, 0);
                else {
                    longestLeft.put(root, 1+longest(root.left, 1));
                }
                max = Math.max(max, longestLeft.get(root));
            }
            if(left==1)
                return longestRight.get(root);
            return longestLeft.get(root);

        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1372.Solution sol = new all1372.Solution();
        TreeNode p1=new TreeNode(1);
        TreeNode p2=new TreeNode(1);
        TreeNode p3=new TreeNode(1);
        TreeNode p4=new TreeNode(1);
        TreeNode p5=new TreeNode(1);
        TreeNode p6=new TreeNode(1);
        TreeNode p7=new TreeNode(1);
        TreeNode p8=new TreeNode(1);
        p1.right=p2;
        p2.left=p3;
        p2.right=p4;
        p4.left=p5;
        p4.right=p6;
        p5.right=p7;
        p7.right=p8;
        int result=sol.longestZigZag(p1);
        System.out.println(result);
    }
}
