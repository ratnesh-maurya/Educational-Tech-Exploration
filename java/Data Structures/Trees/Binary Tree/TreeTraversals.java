//level order traversal of a binary tree
//zigzag traversal of a binary tree
//vertical order traversal of a binary tree

import java.util.*;

class Node {
  int data;
  Node left, right;

  public Node(int item) {
    data = item;
    left = right = null;
  }
}

// https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/114449/A-general-approach-to-level-order-traversal-questions-in-Java

// above is the sexiest post i have seen

class LevelOrderT {
  Node root;

  // constructer
  // public BinaryTreeLevelOrder() {
  // root = null;
  // }
  void printLevelOrder0n() {
    Queue<Node> q = new LinkedList<Node>();
    q.add(root);
    while (!q.isEmpty()) {
      Node now = q.poll();
      System.out.print(now.data + " ");
      if (now.left != null) q.add(now.left);
      if (now.right != null) q.add(now.right);
    }
  }

  void printlevelorder() {
    int h = height(root);

    for (int i = 1; i <= h; i++) {
      printCurrentLevel(root, i);
    }
  }

  int height(Node root) {
    if (root == null) return 0; else {
      int lheight = height(root.left);
      int rheight = height(root.right);
      if (lheight > rheight) return lheight + 1; else return rheight + 1;
    }
  }

  void printCurrentLevel(Node root, int level) {
    if (root == null) return;
    if (level == 1) {
      System.out.print(root.data + " ");
    } else if (level > 1) {
      printCurrentLevel(root.left, level - 1);
      printCurrentLevel(root.right, level - 1);
    }
  }
}

class ZigZagT {
  Node root;

  void PrintZigZagTreeTraversal() {
    if (root == null) return;
    Stack<Node> currentlevel = new Stack<>();
    Stack<Node> nextlevel = new Stack<>();

    currentlevel.push(root);
    boolean lefttoright = true;
    while (!currentlevel.isEmpty()) {
      Node node = currentlevel.pop();
      System.out.print(node.data + " ");

      if (lefttoright) {
        if (node.left != null) nextlevel.push(node.left);
        if (node.right != null) nextlevel.push(node.right);
      } else {
        if (node.right != null) nextlevel.push(node.right);
        if (node.left != null) nextlevel.push(node.left);
      }
      if (currentlevel.isEmpty()) {
        lefttoright = !lefttoright;
        Stack<Node> temp = currentlevel;
        currentlevel = nextlevel;
        nextlevel = temp;
      }
    }
  }
}

public class TreeTraversals {

  public static void main(String[] args) {
    LevelOrderT tree = new LevelOrderT();
    // ZigZagT tree = new ZigZagT();

    // org main
    tree.root = new Node(1);
    tree.root.left = new Node(2);
    tree.root.right = new Node(3);
    tree.root.left.left = new Node(7);
    tree.root.left.right = new Node(6);
    tree.root.right.left = new Node(5);
    tree.root.right.right = new Node(4);

    // System.out.println("zigzag traversal of binary tree is ");
    // tree.PrintZigZagTreeTraversal();

    System.out.println("level order traversal of binary tree is ");
    tree.printlevelorder();
    // level order traversal in o(n) worse case time complexity
    // System.out.println("level order traversal of binary tree is ");
    // tree.printLevelOrder0n();

  }
}

// tags
/*
 * construct binary tree from preorder and inorder traversal
 * construct binary tree from inorder and preorder traversal
 */
class ConstructTree {

  public static void main(String[] args) {}

  int pIndex; //preorder index
  Map<Integer, Integer> inordermap;

  public Node buildTree(int[] preorder, int[] inorder) {
    pIndex = 0;
    //map has value -> index
    inordermap = new HashMap<>();
    for (int i = 0; i < inorder.length; i++) {
      inordermap.put(inorder[i], i);
    }

    return constructed(preorder, 0, preorder.length - 1);
  }

  private Node constructed(int[] preorder, int left, int right) {
    if (left > right) return null;

    int rootval = preorder[pIndex++];
    Node root = new Node(rootval); // first is alwas a root

    int rootindex = inordermap.get(rootval);
    root.left = constructed(preorder, left, rootindex - 1);
    root.right = constructed(preorder, rootindex + 1, right);
    return root;
  }
}
