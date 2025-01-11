import src.Stack;

public class StackTest{
    public static void main(String[] args){
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < 50; i++){ // testing pushing and resizing (growing)
            stack.push(i);
            System.out.println(stack);
            if(i % 10 == 0){
                System.out.println("length of stack: " + stack.length());
            }
        }

        System.out.println(stack.peek()); // peeking 

        for(int i = 49; i >= 0; i--){ // testing popping and resizing (shrinking)
            stack.pop();
            System.out.println(stack);
            if(i % 10 == 0){
                System.out.println("length of stack: " + stack.length());
            }
        }
    }
}