public class Aresta {
    private int peso;
    private Vertice destino;

    public Aresta(int peso) {
        this.peso = peso;
    }

    public int getPeso() {
        return peso;
    }

    public void setPeso(int peso) {
        this.peso = peso;
    }

    public Vertice getDestino() {
        return destino;
    }

    public void setDestino(Vertice destino) {
        this.destino = destino;
    }

    @Override
    public String toString() {
        return "Aresta [Destino: " + destino.getId() + ", peso: " + peso + "]";
    }
}
