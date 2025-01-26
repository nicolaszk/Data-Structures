package src;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
public class UndirectedGraph<T>{
    private Map<T, Set<T>> graph;
    public UndirectedGraph(){
        graph = new HashMap();
    }
    public boolean addVertex(T a){
        boolean found = graph.containsKey(a); // see if vertice already exists in map
        if(found == false){
            Set<T> connections = new HashSet<>(); // "set<t> is an interface, we cant initiate it directly, we must use hashSet<> insteaad"
            graph.put(a, connections);
            return true;
        }
        else{
            return false; // vertex already exists
        }
    }
    public boolean addConnection(T a, T b){ // will connect 2 nodes
        if(graph.containsKey(a) && graph.containsKey(b)){ // if both nodes are in the graph
            Set<T> aConnections = graph.get(a);
            Set<T> bConnections = graph.get(b);
            aConnections.add(b);
            bConnections.add(a);
            return true;
        }
        else{ // if they arent
            return false;
        }
    }
    public void printGraph() {
    for (Map.Entry<T, Set<T>> entry : graph.entrySet()) {
        T vertex = entry.getKey(); // Current vertex
        Set<T> neighbors = entry.getValue(); // Adjacent vertices

        System.out.println(vertex + " -> " + neighbors);
    }
}
}