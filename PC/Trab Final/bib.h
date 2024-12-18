typedef struct Square {
  char entidade, display;
} Square;
int menuInicial();
int menuJogar();
void gerarMatriz(Square mat[][8]);
void copiar_matriz(Square mat[][8],Square matcopy[][8]);
void recopiar_matriz(Square mat[][8],Square matcopy[][8]);
void printMatriz(Square mat[][8], int debug);
int moverAgente(Square mat[][8],int *debug,int *movimentos);
int moverMonstro(Square mat[][8]);
int atirarFlecha(Square mat[][8],int *flecha,int *debug);
void testa_dica (Square mat[][8],int *debug);
void Salvar_Jogo(char nome_jogador[], int pontos);
void testarSentido(Square mat[][8]);