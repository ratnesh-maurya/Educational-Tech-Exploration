import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int key) {
        data = key;
        left = right = null;
    }
}

// a pair class to store the node and its level
class Pair<U, V> {
    public final U first;
    public final V second;

    // constructs a new pair with vaues first, second
    private Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }

    // static method for creating a typed Pair immutable instance
    public static <U, V> Pair<U, V> of(U a, V b) {
        // calls the above private constructer
        return new Pair<>(a, b);
    }
}

public class TreeViews {
    // dist is 0,-1,-2 etc(0Horizonta distance)
    private static void TopView(Node root, int dist, int level, Map<Integer, Pair<Integer, Integer>> map) {

        if (root == null)
            return;

        // if current level is less than the maximum level seen so far the same
        // horizontal distance, or if the horizontal distance is seen for the first time

        if (level < map.get(dist).second || !map.containsKey(dist)) {
            map.put(dist, Pair.of(root.data, level));
        }
        // left subtree with decreasing distance and incrase level
        TopView(root.left, dist - 1, level + 1, map);
        // left subtree with increasing distance and incrase level
        TopView(root.left, dist + 1, level + 1, map);
    }

    private static void TopView(Node root) {
        // key -> horizontal distance, value -> pair of node and level
        // sorted keys in tree map
        Map<Integer, Pair<Integer, Integer>> map = new TreeMap<>();
        TopView(root, 0, 0, map);

        // we only need the node ie, from value, value -> node , level
        for (Pair<Integer, Integer> it : map.values()) {
            System.out.print(it.first + " ");
        }
    }




    // Right view
    // 1) level order traversal, last node of the level is the right view
    private static void RightView(Node root) {
        if(root==null) return;
        Queue<Node> q = new ArrayDeque<>();
        q.add(root);
        Node curr=null;
        while(!q.isEmpty()){
            // total number of nodes in the level
            int size = q.size();
            
            int i=0;

            // process every node of the current level and enqueue its nonempty right and right child
            while(i++<size){
                curr = q.remove();
                // if this is the last node of the current level, print it
                /*
                    FOR LEFT VIEW OF TREE , (I==1)FIRST NODE OF THE LEVEL
                */
                if(i==size) System.out.print(curr.data+" ");
                if(curr.left!=null) q.add(curr.left);
                if(curr.right!=null) q.add(curr.right);
            }
        }
    }

}
