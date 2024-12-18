import java.util.ArrayList;
import java.util.List;

public class Grafo {
    private ArrayList<Vertice> grafo = new ArrayList<>();
    int[][] menorDist;
    int[][] predec;

    public void grafoiIni() {
        for (int i = 0; i < 4; i++) {
            Vertice v = new Vertice(i);
            this.grafo.add(v);
        }
        Aresta a = new Aresta(5);
        a.setDestino(grafo.get(1));
        grafo.get(0).getArestas().add(a); // 0 -> 1 (5)
        a = new Aresta(1);
        a.setDestino(grafo.get(3));
        grafo.get(0).getArestas().add(a); // 0 -> 3 (1)

        a = new Aresta(1);
        a.setDestino(grafo.get(2));
        grafo.get(1).getArestas().add(a); // 1 -> 2 (1)

        a = new Aresta(2);
        a.setDestino(grafo.get(1));
        grafo.get(3).getArestas().add(a); // 3 -> 1 (2)
        a = new Aresta(3);
        a.setDestino(grafo.get(2));
        grafo.get(3).getArestas().add(a); // 3 -> 2 (3)
    }

    public void adicionarvertice() {

    }

    public void imprimirGrafo() {
        for (Vertice v : this.grafo) {
            System.out.println(v.toString());
        }
        System.out.println("");
    }

    public int[][] floydWashall() {
        menorDist = new int[grafo.size()][grafo.size()];
        predec = new int[grafo.size()][grafo.size()];
        int INF = Integer.MAX_VALUE;
        int n = grafo.size();
        // Inicialize a matriz do grafo com pesos de aresta ou infinito
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    menorDist[i][j] = 0; // Distância de um vértice para ele mesmo é zero
                } else {
                    menorDist[i][j] = INF; // Inicialize com infinito
                }
            }
        }

        // Preencha a matriz com os pesos das arestas
        for (int i = 0; i < n; i++) {
            List<Aresta> arestas = grafo.get(i).getArestas();
            for (int j = 0; j < arestas.size(); j++) {
                Aresta aresta = arestas.get(j);
                int destino = aresta.getDestino().getId();
                int peso = aresta.getPeso();
                menorDist[i][destino] = peso;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (menorDist[i][j] != INF) {
                    predec[i][j] = i;
                } else {
                    predec[i][j] = 0;
                }
            }
        }
        // Passa por todos os vértices intermediários
        for (int k = 0; k < n; k++) {
            // Passa por todas as posições da matriz
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Se o vértice k for um caminho mais curto
                    // de i para j, então atualize o valor de dist[i][j]
                    if (menorDist[i][k] != INF && menorDist[k][j] != INF
                            && menorDist[i][k] + menorDist[k][j] < menorDist[i][j]) {
                        menorDist[i][j] = menorDist[i][k] + menorDist[k][j];
                        predec[i][j] = k;
                    }
                }
            }
        }

        // imprimirMat(menorDist);
        imprimirMenorDist(menorDist);

        return menorDist;
    }

    public void imprimirMat(int[][] mat) {
        // Imprima a matriz do grafo
        System.out.println("Matriz do Grafo:");
        for (int i = 0; i < grafo.size(); i++) {
            for (int j = 0; j < grafo.size(); j++) {
                if (mat[i][j] == Integer.MAX_VALUE) {
                    System.out.print("INF\t");
                } else {
                    System.out.print(mat[i][j] + "\t");
                }
            }
            System.out.println();
        }

    }

    public void imprimirMenorDist(int[][] mat) {
        int INF = Integer.MAX_VALUE;
        int n = grafo.size();
        System.err.println("");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("Do vertice " + i + " para " + j + " : ");
                if (mat[i][j] == INF) {
                    System.out.println("-");
                    continue;
                } else {
                    System.out.println(mat[i][j]);
                    getPath(i, j);
                    System.out.println("");
                }
            }
            System.out.println("");
        }
    }

    public void getPath(int a, int b) {
        if (predec[a][b] == b) {
            System.out.print(b + " ");
            return;
        }
        getPath(a, predec[a][b]);
        System.out.print(b + " ");
    }

    public void limparTerminal() {
        try {
            // Executa o comando "cls" no prompt de comando do Windows
            new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}