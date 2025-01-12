public class Queue {
    private int[] Queue;
    private int size;
    private int front;
    private int rear;
    private final int default_capacity = 10;
    public Queue() {
        this.size = 0;
        this.Queue = new int[default_capacity];
        this.front = 0;
        this.rear = 0;
    }   

    public void enqueue(int value){
        if (size == Queue.length) {
            resize();
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % Queue.length;
        }
        Queue[rear] = value;
        size++;
    }

    public int dequeue(){
        if (isEmpty()) {
            throw new IllegalStateException("A fila está vazia");
        }
        
        int value = Queue[rear];
        rear = (rear + 1) % Queue.length; // Circular wrap-around
        size--;
        resize();
        return value;
    }
    public void resize(){
        if(size == Queue.length) {
            int[] newQueue = new int[Queue.length * 2];
            for(int i = 0; i < size; i++) {
                newQueue[i] = Queue[(front + i) % Queue.length];
            }
            front = 0;
            rear = size - 1;
            Queue = newQueue;
        }
        else if(size < Queue.length / 4 && Queue.length > default_capacity) {
            int[] newQueue = new int[Queue.length / 2];
            for(int i = 0; i < size; i++) {
                newQueue[i] = Queue[(front + i) % Queue.length];
            }
            front = 0;
            rear = size - 1;
            Queue = newQueue;
        }
    }

    public boolean isEmpty(){
        return size == 0;
    }
    public int size(){
        return size;
    }
    public int capacity(){
        return Queue.length;
    }
    public int peek(){
        return Queue[front];
    }
    public int front(){
        return front;
    }
    public int rear(){
        return rear;
    }
    public boolean contains(int value){
        for(int i = 0; i < size; i++) {
            if(Queue[rear + i] == value) {
                return true;
            }
        }
        return false;
    }
    public void printQueue(){
        System.out.print("[");
        for(int i = 0; i < size; i++) {
            if(i == size - 1) {
                System.out.print(Queue[front + i]);
                break;
            }
            System.out.print(Queue[front + i] + ", ");
        }
        System.out.println("]");
    }
}