

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
       TreeNode() {}
       TreeNode(int val) { this.val = val; }
       TreeNode(int val, TreeNode left, TreeNode right) {
           this.val = val;
           this.left = left;
           this.right = right;
       }
   }


public class SymmetricTree {
    public boolean isSymmetric(TreeNode root) {
        return isSymmetricHelper(root,root);
    }
    public boolean isSymmetricHelper(TreeNode lnode,TreeNode rnode){
        if(lnode==null && rnode==null) return true;
        if(lnode==null || rnode==null || lnode.val!=rnode.val) return false;
        
        boolean b1=isSymmetricHelper(lnode.left,rnode.right);
        if(b1==false || lnode==rnode) return b1;
        boolean b2=isSymmetricHelper(lnode.right,rnode.left);
        
        return b1 && b2;

}
}