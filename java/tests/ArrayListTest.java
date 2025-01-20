import src.ArrayList;
import java.util.Scanner;
public class ArrayListTest{
    public static void main(String[] args){
        // testing the arraylist methods
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<Integer>();
        System.out.println("1. Add\n2. Get\n3. Remove\n4. Display\n5. Exit");
        System.out.println("Enter your choice: ");
        int choice = -1;
        while(choice != 5){
            System.out.println("Enter your choice: ");
            choice = sc.nextInt();
            switch(choice){
                case 1:
                    System.out.println("Enter the element to add: ");
                    int element = sc.nextInt();
                    list.add(element);
                    break;
                case 2:
                    System.out.println("Enter the index to get: ");
                    int index = sc.nextInt();
                    System.out.println("Element at index " + index + ": " + list.get(index));
                    break;
                case 3:
                    System.out.println("Enter the value to remove: ");
                    int value = sc.nextInt();
                    list.remove(value);
                    break;
                case 4:
                    System.out.println(list);
                    break;
                case 5:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice");
                    break;
            }
        }
    }
}