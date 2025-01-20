import src.BinarySearchTree;
import java.util.Scanner;
public class BinarySearchTreeTest{
    public static void main(String[] args){
        BinarySearchTree<Integer> tree = new BinarySearchTree<>();
        Scanner sc = new Scanner(System.in);
        System.out.println("1. Insert\n2. Delete\n3. Display\n4. Exit");
        System.out.println("Enter your choice: ");
        int choice = -1;
        while(choice != 4){
            System.out.println("Enter your choice: ");
            choice = sc.nextInt();
            switch(choice){
                case 1:
                    System.out.println("Enter the element to insert: ");
                    int element = sc.nextInt();
                    tree.insert(element);
                    break;
                case 2:
                    System.out.println("Enter the value to delete: ");
                    element = sc.nextInt();
                    tree.delete(element);
                    break;
                case 3:
                    tree.printTree();
                    break;
                case 4:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice");
                    break;
            }
        }
    }
}