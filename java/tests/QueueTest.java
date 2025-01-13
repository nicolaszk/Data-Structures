public class QueueTest{
    public static void main(String[] args){
        Queue<Integer> q = new Queue();
        for(int i = 0; i < 50; i++){
            q.enqueue(i);
            if(i % 10 == 0){
                System.out.println("queue capacity: " + q.getCapacity());
            }
        }
        System.out.println("testing peek:" + q.peek());
        for(int i = 49; i >= 0; i--){
            q.dequeue();
            if(i % 10 == 0){
                System.out.println("queue capacity: "+ q.getCapacity());
            }
        }
        System.out.println("end of testing");

    }
}