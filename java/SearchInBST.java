public class SearchInBST {
    public TreeNode searchBST(TreeNode root, int val) {
        //if any node is null mean we have reached the end and not found ,
        //so it will return null as the node will be null or
        //if the root node itself is null we will also return null as the root is null.
           if(root==null)       
               return root;
               
            if(root.val==val)     //if we found the val we return the root.
                return root;
            if(root.val>val)     //else we utillise the property of bst to traverse.
                return searchBST(root.left,val);
            else
              return searchBST(root.right,val);
        
        }
    
}
