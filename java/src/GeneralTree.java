package src;
import java.util.ArrayList;
public class GeneralTree<E>{
    private Node<E> root;

    private static class Node<E>{
        public ArrayList<Node<E>> subTree;
        public E data;
        public Node(E elem){
            data = elem;
            subTree = new ArrayList<Node<E>>();
        }
        public void add(E elem){
            Node<E> subTreeNode = new Node<>(elem);
            subTree.add(subTreeNode);
        }
    }
    public GeneralTree(){
        root = null;
    }
    public boolean add(E value){
        if(root == null){
            root = new Node<>(value);
            return true;
        }
        return false;
    }
    public boolean add(E src, E trgt){
        if(root == null){
            return false;
        }
        Node source = searchNode(src);
        if(source == null){
            return false;
        }
        Node<E> newNode = new Node<>(trgt);
        source.subTree.add(newNode);
        return true;
    }
    public Node<E> searchNode(E value){
        return searchNodeAux(root, value);
    }
    public Node<E> searchNodeAux(Node<E> x, E value){
        if(x != null){
            if(x.data.equals(value)){
                return x;
            }
            for(Node<E> c: x.subTree){
                Node<E> y = searchNodeAux(c, value);
                if(y != null){
                    return y;
                }
            }
        }
        return null;
    }
    public void preOrderTraversal() {
        if (root == null) {
            System.out.println("The tree is empty.");
        } else {
            preOrderTraversalAux(root, 0);
        }
    }

   
    private void preOrderTraversalAux(Node<E> node, int depth) {
        if (node == null) {
            return;
        }
       
        System.out.println("  ".repeat(depth) + node.data);
        for (Node<E> child : node.subTree) {
            preOrderTraversalAux(child, depth + 1);
        }
    }
}
