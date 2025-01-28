import java.util.Scanner;
import src.GeneralTree;
public class GenericTreeTest{
    public static void main(String[] args){
        GeneralTree<String> tree = new GeneralTree<>();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to GeneralTree Tester!");
        System.out.println("Press 1 to add a value as a child of an existing node, or if there arent any, as the root.");
        System.out.println("Press 2 to display the tree (pre-order traversal).");
        System.out.println("Press 0 to exit.");

        while (true) {
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                System.out.print("Enter value to add");
                    String value = scanner.nextLine();
                    if (tree.add(value)) {
                        System.out.println("Added value to root");
                    }
                    else{
                        System.out.println("To what node do you want to add it to?");
                        String base = scanner.nextLine();
                        if(tree.add(base, value)){
                             System.out.println("Value added successfully!");
                        }
                        else{
                            System.out.println("Error");
                        }
                    }
            

                case 2:
                    System.out.println("Displaying tree (pre-order):");
                    tree.preOrderTraversal();
                    break;

                case 0:
                    System.out.println("Exiting. Goodbye!");
                    scanner.close();
                    return;

                default:
                    System.out.println("Invalid choice. Try again.");
                    break;
        
        
                    }        }
    }
}