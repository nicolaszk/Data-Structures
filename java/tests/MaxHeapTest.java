import java.util.Scanner;
import src.MaxHeap;
public class MaxHeapTest{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        MaxHeap maxHeap = new MaxHeap();
        while(true){
            System.out.println("1. Insert\n2.Poll\n3.Display\n4.Exit");
            System.out.println("Enter your choice: ");
            int choice = 4;
            try{
                choice = sc.nextInt();
            }
            catch(Exception e){
                System.out.println("Invalid input");
                continue;
            }

            switch(choice){
                case 1:
                    System.out.println("Enter the element to insert: ");
                    try{
                        int element = sc.nextInt();
                        maxHeap.add(element);
                    }
                    catch(Exception e){
                        System.out.println("Invalid input");
                        continue;
                    }
                    break;
                case 2: 
                    System.out.println("Polled element: " + maxHeap.poll());
                    break;
                case 3:
                    maxHeap.printHeap();
                    break;
                case 4:
                    System.exit(0);
            } 
        }
        
    }
}