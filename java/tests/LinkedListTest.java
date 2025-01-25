import java.util.Scanner;
import src.LinkedList;
public class LinkedListTest{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        LinkedList<Integer> list = new LinkedList<Integer>();
        while(true){
            System.out.println("1. Insert\n2.Remove\n3.Display\n4.Exit");
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
                        list.add(element);
                    }
                    catch(Exception e){
                        System.out.println("Invalid input");
                        continue;
                    }
                    break;
                case 2: 
                    System.out.println("Enter the element to be removed: ");
    
                    int elementToBeRemoved = sc.nextInt();
                    

                    if(list.remove(elementToBeRemoved)){
                         System.out.println("Removed element");
                    }
                    else{
                        System.out.println("Didnt find element");
                    }
                   
                    break;
                case 3:
                    list.print();
                    break;
                case 4:
                    System.exit(0);
            } 
        }
        
    }
}