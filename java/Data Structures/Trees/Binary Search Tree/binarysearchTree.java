
class Node {
    int data;
    Node left, right;

    public Node(int key) {
        data = key;
        left = right = null;
    }
}

public class binarysearchTree {
    // root bc
    Node root;

    // cosntructer
    binarysearchTree() {
        root = null;
    }

    public Node search(Node root, int key) {
        if (root == null || root.data == key)
            return root;
        if (root.data < key) {
            return search(root.right, key);
        } else
            return search(root.left, key);
    }

    public static Node insertRecursive(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }
        if (key < root.data) {
            root.left = insertRecursive(root.left, key);
        } else if (key > root.data) {
            root.right = insertRecursive(root.right, key);
        }
        return root;
    }

    public static Node insertIterative(Node root, int key) {
        Node curr = root;
        Node parent = null;
        if (root == null) {
            return new Node(key);
        }
        while (curr != null) {
            parent = curr;
            if (key < curr.data) {
                curr = curr.left;
            } else {
                curr = curr.right;
            }
        }
        if (key < parent.data) {
            parent.left = new Node(key);
        } else {
            parent.right = new Node(key);

        }
        return root;
    }

    static Node remove(Node root, int k) { // remove or delete Node
        // base case
        if (root == null)
            return null;

        // recursive calls for ansestor of node to be delelted
        if (root.data > k) {
            root.left = remove(root.left, k);
            return root;
        } else if (root.data < k) {
            root.right = remove(root.right, k);
            return root;
        }

        /* apan pahuch gaya, now the root is the node to be deleted */
        // if node is leaf

        // if node has one child
        if (root.left == null) {
            Node temp = root.right;
            return temp;
        }
        if (root.right == null) {
            Node temp = root.left;
            return temp;
        }

        // if node has two children
        /* largest element in (left) subtree will be the successor */
        // OR
        /* smallest element in (right) subtree will be the successor */
        else {
            Node succParent = root;
            Node succ = root.right;

            // we are searching for the smallest element in the right subtree
            while (succ.left != null) {
                succParent = succ;
                succ = succ.left;
            }

            if (succParent != root)
                succParent.left = succ.right;
            else
                succParent.right = succ.right;

            root.data = succ.data;
            return root;
        }
    }

    // driver code
    public static void main(String[] args) {
        Node root = null;
        root = insertRecursive(root, 50);
        root = insertRecursive(root, 30);
        root = insertRecursive(root, 20);
        root = insertRecursive(root, 40);
        root = insertRecursive(root, 70);
        root = insertRecursive(root, 60);
        root = insertRecursive(root, 80);
        root = remove(root, 30);
    }
}
