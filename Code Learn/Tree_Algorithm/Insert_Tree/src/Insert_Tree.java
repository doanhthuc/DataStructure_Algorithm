import org.w3c.dom.Node;

import java.util.LinkedList;
import java.util.Queue;

public class Insert_Tree {
    static class Node {
        int key;
        Node left, right;

        //Constructor
        Node (int key) {
            this.key = key;
            left = null;
            right = null;
        }
    }
    static Node root;
    static Node temp;

    /* Inorder traversal of a binary tree*/
    static void inorder(Node temp)
    {
        if (temp == null)
            return;

        inorder(temp.left);
        System.out.print(temp.key + " ");
        inorder(temp.right);
    }

   // Function to insert element in binary tree
    static void insert(Node temp, int key){
        if (temp == null) {
            root = new Node(key);
            return;
        }
        Queue<Node> q = new LinkedList<>();
        q.add(temp);

        // Do level order traversal until we find an empty place
        while (!q.isEmpty()){
            temp = q.peek();
            q.remove();

            if(temp.left == null) {
                temp.left = new Node(key);
                break;
            }
            else q.add(temp.right);
        }
    }

    // Driver code
    public static void main(String[] args) {
        root = new Node(10);
        root.left = new Node(11);
        root.left.left = new Node(7);
        root.right = new Node(9);
        root.right.left = new Node(15);
        root.right.right = new Node(8);

        System.out.print(
                "Inorder traversal before insertion:");
        inorder(root);

        int key = 12;
        insert(root, key);

        System.out.print(
                "\nInorder traversal after insertion:");
        inorder(root);
    }
}
