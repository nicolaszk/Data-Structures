package src;
public class LinkedList<E>{
    private int size;
    private Node<E> head;
    private Node<E> tail;
    @SuppressWarnings("hiding")
    public class Node<E>{
        private E data;
        private Node<E> next;
        public Node(E data){
            this.data = data;
            next = null;
        }
    }
    public LinkedList(){
        size = 0;
        head = null;
        tail = null;
    }
    public boolean add(E data){
        if(head == null){
            head = new Node<E>(data);
            tail = head;
            size++;
            return true;
        }
        // if not empty, add to tail
        tail.next = new Node<E>(data);
        tail = tail.next;
        size++;
        return true;
    }
    public boolean remove(E data){
        // check if its head
       
        Node<E> current = head;
        if(current.data.equals(data)){
            head = head.next;
            size--;
            return true;
        }
        while(current.next != null){
            if(current.next.data.equals(data)){
                if(current.next == tail){
                    tail = current;
                    current.next = null; 
                    size--;
                    return true;
                }
                current.next = current.next.next;
                size--;
                return true;
            }
            current = current.next;
        }
        return false;
       
    }
    public void print(){
        Node<E> current = head;
        while(current != null){
            System.out.print("[" + current.data + "] -> ");
            current = current.next;
        }
        System.out.print("[null]");
        System.out.println();
    }
}