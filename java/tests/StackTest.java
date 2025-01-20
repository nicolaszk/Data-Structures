import src.Stack;
import java.util.Scanner;
public class StackTest{
    public static void main(String[] args){
        Stack<Integer> stack = new Stack<>();
        Scanner sc = new Scanner(System.in);
        System.out.println("1. Push\n2. Pop\n3. Display\n4. Exit");
        System.out.println("Enter your choice: ");
        int choice = -1;
        while(choice != 4){
            System.out.println("Enter your choice: ");
            choice = sc.nextInt();
            switch(choice){
                case 1:
                    System.out.println("Enter the element to push: ");
                    int element = sc.nextInt();
                    stack.push(element);
                    break;
                case 2:
                    System.out.println("Popped element: " + stack.pop());
                    break;
                case 3:
                    System.out.println(stack);
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