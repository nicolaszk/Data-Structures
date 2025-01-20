import java.util.Scanner;
public class QueueTest{
    public static void main(String[] args){
        Queue<Integer> q = new Queue();
        System.out.println("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        System.out.println("Enter your choice: ");
        int choice = -1;
        Scanner sc = new Scanner(System.in);
        while(choice != 4){
            System.out.println("Enter your choice: ");
            choice = sc.nextInt();
            switch(choice){
                case 1:
                    System.out.println("Enter the element to enqueue: ");
                    int element = sc.nextInt();
                    q.enqueue(element);
                    break;
                case 2:
                    System.out.println("Dequeued element: " + q.dequeue());
                    break;
                case 3:
                    System.out.println(q);
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