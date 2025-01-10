public class Stack <E>{ // array will double in size when full and halve when 1/4 full
    private Object[] stack;
    private int top;

    public Stack(){
        stack = new Object[1];
    }
    public void push(E item){
        stack[top++] = item;
        resize();
    }
    @SuppressWarnings("unchecked")
    public E pop(){
        E item = (E) stack[--top];
        stack[top] = null;
        resize();
        return item;
    }
    @SuppressWarnings("unchecked")
    public E peek(){
        return (E) stack[top - 1];
    }
    public int size(){
        return top;
    }
    public int length(){
        return stack.length;
    }
    public void resize(){
        if(top == stack.length){
            Object[] newStack = new Object[stack.length * 2];
            for(int i = 0; i < top; i++){
                newStack[i] = stack[i];
            }
            stack = newStack;
        }
        else if(top <= stack.length / 4){
            Object[] newStack = new Object[stack.length / 2];
            for(int i = 0; i < top; i++){
                newStack[i] = stack[i];
            }
            stack = newStack;
        }
    }
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for(int i = 0; i < top; i++){
            if(i < top - 1){
                sb.append(stack[i] + ", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}
