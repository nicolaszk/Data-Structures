public class App{
    public static void main(String[] args){
        // testing the arraylist methods
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i = 0; i < 50; i++){
            list.add(i);
            System.out.println(list);
            if(i % 5 == 0){
                System.out.println("length: " + list.length());
            }
        }
        for(int i = 0; i < 50; i++){
            list.get(i);
        }
        for(int i = 49; i >= 0; i--){
            list.remove(i);
            System.out.println(list);
        }
         System.out.println("length: " + list.length());
    }
}