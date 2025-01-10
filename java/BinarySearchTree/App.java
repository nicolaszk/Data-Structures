public class App{
    public static void main(String[] args){
        BinarySearchTree<Integer> tree = new BinarySearchTree<>();
        tree.insert(5);
        tree.insert(3);
        tree.insert(7);
        tree.insert(2);
        tree.insert(4);
        tree.insert(6);
        tree.insert(8);
        tree.printTree();
        System.out.println();
        tree.delete(5);
        tree.printTree();
        System.out.println();
        tree.delete(3);
        tree.printTree();
    }
}