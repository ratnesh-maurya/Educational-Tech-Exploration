import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
}

public class burnBinaryTree {

    // static class Node {
    // int data;
    // Node left, right;

    // Node(int data) {
    // this.data = data;
    // left = right = null;
    // }
    // }

    static class Depth {
        int d;

        public Depth(int d) {
            this.d = d;
        }
    }

    static int ans;

    // returns minimum time to burn the binary tree, from target
    public static int minTime(Node root, int target) {
        Depth depth = new Depth(-1);
        burn(root, target, depth);
        return ans;
    }

    public static int burn(Node root, int target, Depth depth) {
        if (root == null)
            return 0;
        if (root.data == target) {
            depth.d = 0;
        }
        Depth ld = new Depth(-1);
        Depth rd = new Depth(-1);

        int lh = burn(root.left, target, ld); // left and right height
        int rh = burn(root.right, target, rd);

        if (ld.d != -1) {
            ans = Math.max(ans, ld.d + 1 + rh);
        } else if (rd.d != -1) {
            ans = Math.max(ans, rd.d + 1 + lh);
        }

        return Math.max(lh, rh) + 1;
    }
}

// parent tree method

class timeToBurnBinaryTreeStriver {
    private static Node bfsToMapParents(Node root, HashMap<Node, Node> parents,
            int start) {

        Queue<Node> q = new LinkedList<>();
        q.offer(root);

        Node result = new Node(-1);
        while (!q.isEmpty()) {
            Node curr = q.poll();
            if (curr.data == start)
                result = curr;
            if (curr.left != null) {
                // children -> parent
                parents.put(curr.left, curr);
            }
            if (curr.right != null) {
                parents.put(curr.right, curr);
            }
        }
        return result;
    }

    private static int findMaxDistance(HashMap<Node, Node> parents, Node target) {
        Queue<Node> q = new LinkedList<>();
        q.offer(target);
        // imporove by adding set here
        Set<Node> visited = new HashSet<>();
        visited.add(target);
        int maxi = 0;
        while (!q.isEmpty()) {
            // number of elements we have to traverse in one unit time

            int sz = q.size();

            boolean done = false;

            for (int i = 0; i < sz; i++) {
                Node curr = q.poll();

                if (curr.left != null && !visited.contains(curr.left)) {
                    done = true;
                    visited.add(curr.left);
                    q.offer(curr.left);
                }
                if (curr.right != null && !visited.contains(curr.right)) {
                    done = true;
                    visited.add(curr.right);
                    q.offer(curr.right);
                }
                if (parents.get(curr) != null && !visited.contains(parents.get(curr))) { // parent of the current node is added 
                    done = true;
                    visited.add(parents.get(curr));
                    q.offer(parents.get(curr));
                }
            }
            if (done)
                maxi++;
        }
        return maxi;
    }

    public static int timeToBurn(Node root, int start) {
        HashMap<Node, Node> parents = new HashMap<>();
        Node target = bfsToMapParents(root, parents, start);
        return findMaxDistance(parents, target);
    }
}