import src.UndirectedGraph;
import java.util.Scanner;
public class UndirectedGraphTest{
    public static void main(String[] args){
        int choice = -1;
        String s = "";
        Scanner in = new Scanner(System.in);
        UndirectedGraph<Integer> graph = new UndirectedGraph<Integer>();
        while(true){
            System.out.println("Choose an option:\n 1. Add Vertex\n 2. Add Connection \n 3. Print graph \n 4.Exit\n Enter choice: ");
            choice = in.nextInt();
            switch(choice){
                case 1: 
                System.out.println("Choose integer to add to the map: ");
                int chosenInteger = in.nextInt();
                s = (graph.addVertex(chosenInteger)) ? "Vertex added successfully!": "Vertex already in the map";
                System.out.println(s);
                break;
                case 2:
                System.out.println("Choose two integers to add a connection in between them\n");
                System.out.println("first choice: ");
                int first = in.nextInt();
                System.out.println("second choice: ");
                int second = in.nextInt();
                s = (graph.addConnection(first, second)) ? "Connection added successfuly": "One or more integers aren't already in the graph. Please try again or add them to the graph.";
                System.out.println(s);
                break;
                case 3:
                graph.printGraph();
                break;
                case 4:
                System.exit(0);
                default:
                System.out.println("Invalid choice! try again!");
                break;
            }


        }

    
        
    }
}