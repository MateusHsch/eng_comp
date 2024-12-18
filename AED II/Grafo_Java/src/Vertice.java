import java.util.ArrayList;

public class Vertice {
    private int id;
    private ArrayList<Aresta> arestas = new ArrayList<>();

    public Vertice(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public ArrayList<Aresta> getArestas() {
        return arestas;
    }

    public void setArestas(ArrayList<Aresta> arestas) {
        this.arestas = arestas;
    }

    @Override
    public String toString() {
        return "Vertice: " + id + "\n" + arestas;
    }

}