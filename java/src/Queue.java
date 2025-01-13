public class Queue <E>{

    private Object[] data;
    private int size;
    private int capacity;
    private int front;
    private int rear;

    public Queue(){
        data = new Object[10];
        rear = -1;
        front = -1;
        capacity = 10;
        size = 0;
    }

    public void enqueue(E value){
        if(size == 0){
            rear = 0;
            front = 0;
        }
        if(size == capacity){
            resize();
        }
        data[rear] = value;
        rear = (rear+1) % capacity;
        size++;
    }
    @SuppressWarnings("unchecked")
    public E dequeue(){
        if(size == 0){
            throw new IndexOutOfBoundsException("The queue is empty");
        }
        if(size < capacity/4){
            resize();
        }
        Object value = data[front];
        front = (front + 1) % capacity;
        size--;
        return (E) value;
    }
    @SuppressWarnings("unchecked")
    public E peek(){
        if(size == 0){
            throw new IndexOutOfBoundsException("The queue is empty");
        }
        return (E) data[front];
    }
    public void resize(){
        if(size == capacity){
            Object[] newData = new Object[capacity*2];
            for(int i = 0; i < size; i++){
                int index = (front + i) % capacity;
                newData[i] = data[index];
            }
            data = newData;
            capacity = capacity*2;
            front = 0;
            rear = size - 1;

        }
        if(size < capacity/4 && capacity > 10){
            Object[] newData = new Object[capacity/2];
            for(int i = 0; i < size; i++){
                int index = (front + i) % capacity;
                newData[i] = data[index];
            }
            data = newData;
            capacity = capacity/2;
            front = 0;
            rear = size - 1;
        }


    }
    public int getCapacity(){
        return capacity;

    }
    public int getSize(){
        return size;
    }
    public boolean isEmpty(){
        return size == 0; 
    }
    public boolean contains(E value){
        for(int i = 0; i < size; i++){
            int index = (front + i) % capacity;
            if(data[index].equals(value)){
                return true;
            }
        }
        return false;
    }
}