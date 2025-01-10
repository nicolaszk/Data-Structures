// The arrayList will double in size when full, and halve in size when 1/4 full

public class ArrayList<E>{
    private Object[] array;
    private int size;

    public ArrayList(){
        this.array = new Object[1];
        this.size = 0;
    }
    public void add(E element){
        array[size] = element;
        size++;
        resize();
    }
    @SuppressWarnings("unchecked")
    public E get(int index){
        if(index < 0 || index >= size){
            throw new IndexOutOfBoundsException("Invalid index.");
        }
        return (E) array[index];
    }
    public int size(){
        return size;
    }
    public int length(){
        return array.length;
    }
    public void remove(int index){
        if(index < 0 || index >= size){
            throw new IndexOutOfBoundsException("Invalid index.");
        }
        for(int i = index; i < size -1; i++){
            array[i] = array[i+1];
            size--;
        }
        array[size] = null;
        resize();
    }
    private void resize(){
        if(size == array.length){
            Object[] newArray = new Object[array.length*2];
            for(int i = 0; i < size; i++){
                newArray[i] = array[i];       
            }
            this.array = newArray;
        }
        if(size <= array.length/4){
            Object[] newArray = new Object[array.length/2];
            for(int i = 0; i < size; i++){
                newArray[i] = array[i];
            }
            this.array = newArray;
        }
    }
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for(int i = 0; i < size; i++){
            sb.append(array[i]);
            if(i < size - 1){
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}