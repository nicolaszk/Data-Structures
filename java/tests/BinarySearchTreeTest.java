import src.BinarySearchTree;

public class BinarySearchTreeTest{
    public static void main(String[] args){
        BinarySearchTree<Integer> tree = new BinarySearchTree<>();
        
        System.out.println("Testing insertion and tree printing:");
        int[] values = {4, 2, 6, 1, 3, 5, 7}; // More balanced insertion order
        for(int value : values) {
            tree.insert(value);
            System.out.println("\nAfter inserting " + value + ":");
            tree.printTree();
        }

        System.out.println("\nTesting contains():");
        System.out.println("Contains 4? " + tree.contains(4)); // Should be true
        System.out.println("Contains 8? " + tree.contains(8)); // Should be false
        System.out.println("Contains 1? " + tree.contains(1)); // Should be true
        System.out.println("Contains 7? " + tree.contains(7)); // Should be true

        System.out.println("\nTesting deletion of leaf nodes:");
        tree.delete(7);
        System.out.println("\nAfter deleting 7 (leaf node):");
        tree.printTree();
        System.out.println("Contains 7? " + tree.contains(7)); // Should be false
        
        System.out.println("\nTesting deletion of nodes with one child:");
        tree.insert(7);
        tree.delete(6);
        System.out.println("\nAfter deleting 6 (node with one child):");
        tree.printTree();
        System.out.println("Contains 6? " + tree.contains(6)); // Should be false
        
        System.out.println("\nTesting deletion of nodes with two children:");
        tree.insert(6);
        tree.delete(4);
        System.out.println("\nAfter deleting 4 (node with two children):");
        tree.printTree();
        System.out.println("Contains 4? " + tree.contains(4)); // Should be false
        
        System.out.println("\nTesting deletion of root:");
        tree.delete(1);
        System.out.println("\nAfter deleting 1 (root):");
        tree.printTree();
        System.out.println("Contains 1? " + tree.contains(1)); // Should be false
        
        System.out.println("\nTesting edge cases:");
        BinarySearchTree<Integer> emptyTree = new BinarySearchTree<>();
        System.out.println("Empty tree:");
        emptyTree.printTree();
        System.out.println("Empty tree contains 1? " + emptyTree.contains(1)); // Should be false
        
        emptyTree.delete(1); // Should handle gracefully
        System.out.println("\nAfter trying to delete from empty tree:");
        emptyTree.printTree();
        System.out.println("End of tests");
    }
}