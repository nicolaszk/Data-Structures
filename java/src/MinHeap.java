package src;
public class MinHeap {
    private int[] heap;
    private int size;
    private int capacity;
    private final int DEFAULT_CAPACITY = 10;
    public MinHeap() {
        heap = new int[DEFAULT_CAPACITY];
        size = 0;
        capacity = DEFAULT_CAPACITY;
    }
    public void add(int value){
        if(size == heap.length){
            resize();
        }
        heap[size] = value;
        size++;
        bubbleUp(size-1);
        
    }
    public void bubbleUp(int index){
        int parent = parent(index);
        if(index > 0 && heap[index] < heap[parent]){ // if value is less than parent, swap and continue bubbling up
            swap(index, parent);
            bubbleUp(parent); // continue bubbling up until heap property is restored
        }
    }
    public int leftChild(int index){
         return 2 * index + 1;
    }
    public int rightChild(int index){
        return 2 * index + 2;
    }
    public int parent(int index){
        return (index - 1)/2;
    }
    public void swap(int index1, int index2){
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }
    public void resize(){
        if(size == heap.length){
            int[] newHeap = new int[heap.length * 2];
            for(int i = 0; i < heap.length; i++){
            newHeap[i] = heap[i];
            }
            capacity *=2;
            heap = newHeap;
        }
        if(size < heap.length/4){
            int[] newHeap = new int[heap.length/2];
            for(int i = 0; i < size; i++){
                newHeap[i] = heap[i];
            }
            heap = newHeap;
            capacity /= 2;
        }
    

    }
    public boolean isEmpty(){
        return size == 0;
    }
    public void remove(int value){
        int index = -1;
        for(int i = 0; i < size; i++){
            if(heap[i] == value){
                index = i;
                break;
            }
        }
    if(index == -1){
        return;
    }
        heap[index] = heap[size-1]; //exchange values with last leaf, and then bubble down to restore heap property
        heap[size-1] = 0;
        size--;
        bubbleDown(index);
        resize();
    }
    public int getCapacity(){
        return capacity;
    }
    public void bubbleDown(int index){ // bubble down: swap with smaller child until heap property is restored
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;
        if(left < size && heap[left] < heap[smallest]){
            smallest = left;
        }
        if(right < size && heap[right] < heap[smallest]){
            smallest = right;
        }
        if(smallest != index){ // if changed, swap and continue bubbling down
            swap(index, smallest);
            bubbleDown(smallest);
        }
    }
    public int poll(){
        if(isEmpty()){
            throw new IndexOutOfBoundsException("Heap is empty");
        }
        int result = heap[0];
        heap[0] = heap[size-1];
        heap[size-1] = 0;
        size--;
        if(!isEmpty()){
            bubbleDown(0);
        }
        return result;
    }
    public void printHeap(){
        if (isEmpty()) {
            System.out.println("Heap vazio");
            return;
        }
        
        int level = 0;
        int itemsInLevel = 1;
        
        while (Math.pow(2, level) <= size) {
            int startIndex = (int)Math.pow(2, level) - 1;
            int endIndex = Math.min(startIndex + itemsInLevel, size);
            
            // Imprime espaços para centralizar
            for (int i = 0; i < Math.pow(2, (int)Math.log(size)) - Math.pow(2, level); i++) {
                System.out.print(" ");
            }
            
            // Imprime elementos do nível atual
            for (int i = startIndex; i < endIndex; i++) {
                System.out.print(heap[i] + " ");
            }
            System.out.println();
            
            level++;
            itemsInLevel *= 2;
        }
    }
    }
