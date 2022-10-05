import java.util.ArrayList;
import java.util.Stack;

public class TwoSumInputIsBST {
    public boolean findTarget(TreeNode root, int k) {
        return M1(root, k);
        // return M2(root, k, root);
        // return M3(root, k);
    }

    void Inorder1(TreeNode node, ArrayList<Integer> list) {
        if (node == null)
            return;
        Inorder1(node.left, list);
        list.add(node.val);
        Inorder1(node.right, list);
    }
    boolean M1(TreeNode root, int target) {
        ArrayList<Integer> list = new ArrayList<>();
        Inorder1(root, list);
        int i = 0;
        int j = list.size() - 1;
        while (i < j) {
            if (list.get(i) + list.get(j) == target) {
                return true;
            } else if (list.get(i) + list.get(j) > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
    boolean M2(TreeNode root, int target, TreeNode oroot) {
        if (root == null)
            return false;
        int val = root.val;
        int b = target - val;
        if (b != val && find(oroot, b)) {
            return true;
        }
        return M2(root.left, target, oroot) || M2(root.right, target, oroot);
    }
    boolean find(TreeNode root, int target) {
        if (root == null)
            return false;
        if (root.val > target) {
            return find(root.left, target);
        } else if (root.val < target) {
            return find(root.right, target);
        } else {
            return true;
        }
    }
    private static class Pair {
        TreeNode node;
        int state;

        Pair(TreeNode node, int state) {
            this.node = node;
            this.state = state;
        }
    }
    boolean M3(TreeNode root, int target) {
        Stack<Pair> ls = new Stack<>();
        ls.push(new Pair(root, -1));

        Stack<Pair> rs = new Stack<>();
        rs.push(new Pair(root, -1));

        int v1 = next_From_Normal_Inorder(ls);
        int v2 = next_From_Reverse_Inorder(rs);

        while (v1 < v2) {
            if (v1 + v2 == target) {
                return true;
            } else if (v1 + v2 > target) {
                v2 = next_From_Reverse_Inorder(rs);
            } else {
                v1 = next_From_Normal_Inorder(ls);
            }
        }
        return false;
    }
    int next_From_Normal_Inorder(Stack<Pair> st) {
        while (st.size() != 0) {
            Pair peekp = st.peek();
            if (peekp.state == -1) {
                // preorder + state++ + push left child
                peekp.state++;
                if (peekp.node.left != null)
                    st.push(new Pair(peekp.node.left, -1));
            } else if (peekp.state == 0) {
                // Inorder + go to right child
                int val = peekp.node.val;
                peekp.state++;
                if (peekp.node.right != null)
                    st.push(new Pair(peekp.node.right, -1));
                return val;
            } else {
                st.pop();
            }
        }
        return -1;
    }
    int next_From_Reverse_Inorder(Stack<Pair> st) {
        while (st.size() != 0) {
            Pair peekp = st.peek();
            if (peekp.state == -1) {
                // preorder + state++ + push left child
                peekp.state++;
                if (peekp.node.right != null)
                    st.push(new Pair(peekp.node.right, -1));
            } else if (peekp.state == 0) {
                // Inorder + go to right child
                int val = peekp.node.val;
                peekp.state++;
                if (peekp.node.left != null)
                    st.push(new Pair(peekp.node.left, -1));
                return val;
            } else {
                st.pop();
            }
        }
        return -1;
    }

}
