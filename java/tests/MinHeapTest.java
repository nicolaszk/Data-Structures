import java.util.Scanner;
import src.MinHeap;
public class MinHeapTest{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        MinHeap minHeap = new MinHeap();
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
                        minHeap.add(element);
                    }
                    catch(Exception e){
                        System.out.println("Invalid input");
                        continue;
                    }
                    break;
                case 2: 
                    System.out.println("Polled element: " + minHeap.poll());
                    break;
                case 3:
                    minHeap.printHeap();
                    break;
                case 4:
                    System.exit(0);
            } 
        }
        
    }
}