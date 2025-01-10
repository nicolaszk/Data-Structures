public class BinarySearchTree<E extends Comparable<E>>{
    private Node root;
    private class Node{
        private E element;
        private Node left;
        private Node right;
        public Node(E element){
            this.element = element;
            left = null;
            right = null;
        }
    }
    public BinarySearchTree(){
        root = null;
    }
    public void insert(E element){
        if(root == null){
            root = new Node(element);
            return;
        }
        Node current = root;
        while(current != null){
            if(element.compareTo(current.element) < 0){
                if(current.left == null){
                    current.left = new Node(element);
                    return;
                }
                else{
                    current = current.left;
                    continue;
                }
            }
            else{
                if(current.right == null){
                    current.right = new Node(element);
                    return;
                }
                else{
                    current = current.right;
                    continue;
                }
            }
        }
    }
    public void delete(E element) {
        if (root != null && element.compareTo(root.element) == 0) {  // if the element is the root
            if (root.left == null) { // if the root has no left child
                root = root.right;
            } else if (root.right == null) { // if the root has no right child
                root = root.left;
            } else { // if the root has both children
                Node successor = findSuccessor(root); // find the inorder successor
                root.element = successor.element;
                deleteSuccessor(root, root.right); // delete the inorder successor
            }
            return;
        }

        Node current = root;
        Node parent = null;
        while(current != null) { // find the node to delete
            int cmp = element.compareTo(current.element);
            if(cmp < 0) {
                parent = current;
                current = current.left;
            }
            else if(cmp > 0) {
                parent = current; 
                current = current.right;
            }
            else { // found the node to delete
                if(current.left == null || current.right == null) { // if the node to delete has no children or only one child
                    Node child = (current.left != null) ? current.left : current.right; // get the child
                    if(parent.left == current) parent.left = child; // if the node to delete is the left child of its parent, set the parent's left child to the child
                    else parent.right = child; // if the node to delete is the right child of its parent, set the parent's right child to the child
                }
                else { // if the node to delete has both children
                    Node successor = findSuccessor(current); // find the inorder successor
                    current.element = successor.element; // replace the node to delete with the inorder successor
                    deleteSuccessor(current, current.right); // delete the inorder successor
                }
                return;
            }
        }
    }
    private Node findSuccessor(Node node){ // find the smallest node in the right subtree(inorder successor)
        Node successor = node.right;
        while(successor.left != null){
            successor = successor.left;
        }
        return successor;
    }
    private void deleteSuccessor(Node parent, Node current) { // delete the inorder successor
        while (current.left != null) { // find the smallest node in the right subtree
            parent = current;
            current = current.left;
        }
        
        if (parent.left == current) { // if the inorder successor is the left child of its parent
            parent.left = current.right; // set the parent's left child to the inorder successor's right child
        } else { // if the inorder successor is the right child of its parent
            parent.right = current.right; // set the parent's right child to the inorder successor's right child
        }
    }
    public void printTree(){
        printTree(root, 0);
    }
    private void printTree(Node node, int level){ // print the tree in tree format
        if(node == null){
            return;
        }
        printTree(node.right, level + 1);
        System.out.println(" ".repeat(level * 2) + node.element);
        printTree(node.left, level + 1);
    }
}