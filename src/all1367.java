public class all1367 {
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    class Solution {
        public boolean isSubPath(ListNode head, TreeNode root) {
            if(head==null)
                return true;
            if(root==null)
                return false;
            boolean sub=isSubPath(head,root.left)||isSubPath(head,root.right);
            if(root.val!=head.val)
                return sub;
            return sub||isSubPath(head.next,root.left)||isSubPath(head.next,root.right);
        }
    }
}
