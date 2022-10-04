public class ValidateBST {
    Integer previous = null;
public boolean isValidBST(TreeNode root) {
	return inorder(root);   
}

private boolean inorder(TreeNode root) {
	if (root == null)
		return true;

	if (!inorder(root.left))
		return false;

	if (previous != null && root.val <= previous)
		return false;

	previous = root.val;

	return inorder(root.right);

}
}