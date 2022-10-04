
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


public class BinaryTreePostorder {
    private List<Integer> list = new ArrayList();
    public List<Integer> postorderTraversal(TreeNode root) {
         if(root ==null){
            return list;
        }
       
        postorderTraversal(root.left);
        postorderTraversal(root.right);
         list.add(root.val);
        return list;
    
}
}