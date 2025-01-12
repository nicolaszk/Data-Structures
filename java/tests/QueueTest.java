

public class QueueTest{
    public static void main(String[] args){
        Queue queue = new Queue();
        for(int i = 0; i < 50; i++){ // testing pushing and resizing (growing)
            queue.enqueue(i);
          
            if(i % 10 == 0){
                System.out.println("capacity of queue: " + queue.capacity());
            }
        }
        queue.printQueue();
        System.out.println(queue.peek()); // peeking 

        for(int i = 49; i >= 0; i--){ // testing popping and resizing (shrinking)
            queue.dequeue();
          
            if(i % 10 == 0){
                System.out.println("capacity of queue: " + queue.capacity());
            }
        }
    }
}