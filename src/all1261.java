import java.util.HashMap;

public class all1261 {
      public class TreeNode {
          int val;
          TreeNode left;
          TreeNode right;

          TreeNode(int x) {
              val = x;
          }
      }

    class FindElements {
        HashMap<Integer, Integer> mp=new HashMap<Integer, Integer>();
        void changeVal(TreeNode root,int val){
            if(root==null)
                return;
            root.val=val;
            mp.put(val,1);
            changeVal(root.left,2*val+1);
            changeVal(root.right,2*val+2);
        }
        public FindElements(TreeNode root) {
            changeVal(root,0);
        }

        public boolean find(int target) {
            return mp.containsKey(target);
        }
    }
}
