#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int alocacoes = 0;    // Var. Global: Conta as alocações
int desalocacoes = 0; // Var. Global: Conta as desalocações
/* -----------< struct matrix.c >---------- */
struct matrix {
  struct matrix *direita; // Ponteiro para o nó à direita
  struct matrix *abaixo;  // Ponteiro para o nó à esquerda
  int linha;              // Linha do elemento
  int coluna;             // Coluna do elemento
  float informacao;       // Informação do elemento
};
typedef struct matrix Matrix;
/* --------------< matrix.h >-------------- */
Matrix *matrix_create(void); // Cria a matriz a partir da entrada (matrix.txt)
void matrix_destroy(Matrix *m); // Destroi a matriz
void matrix_print(Matrix *m);   // Imprime a matriz
Matrix *matrix_add(Matrix *m, Matrix *n);
Matrix *matrix_multiply(Matrix *m, Matrix *n);
Matrix *matrix_transpose(Matrix *m);
float matrix_getelem(Matrix *m, int x, int y);
void matrix_setelem(Matrix *m, int x, int y, float elem);
Matrix* matrix_create_rand(unsigned int m);
float** matrix_bruta(unsigned int m); 
void matrix_destroy_bruta(float **mat,unsigned int m);
float** matrix_multiplica_bruta(float **m,float **n,unsigned int t);
float** matrix_soma_bruta(float **m,float **n,unsigned int t);
float** matrix_bruta_transposta(float **m,unsigned int t);
void print_bruta(float **m, unsigned int t);
/* ---------------< main.c >--------------- */
//8180x8180
//66912400
//720
int main() {
  srand(time(NULL));
  clock_t inicio_bruta,fim_bruta,inicio,fim;
  double tempo_bruta,tempo;
  inicio = clock();
  Matrix *A = matrix_create_rand(25000000);
  matrix_print( A );
  Matrix *B = matrix_create_rand(25000000);
  matrix_print( B );
  Matrix *C = matrix_add( A, B );
  matrix_print( C );
  matrix_destroy( C );
  C = matrix_multiply( A, B );
  matrix_print( C );
  matrix_destroy( C );
  C = matrix_transpose( A );
  matrix_print( C );
  matrix_destroy( C );
  matrix_destroy( A );
  matrix_destroy( B );
  fim = clock();
  tempo = (double) (fim-inicio)/CLOCKS_PER_SEC;
  FILE* f = fopen("matrix.txt","a");
  fprintf(f,"\nTempo por lista: %.2lf\n",tempo);
  fprintf(f,"Alocacoes: %d\n",alocacoes);
  fprintf(f,"Desalocacoes: %d\n\n",desalocacoes);
  fclose(f);
  return 0;
  /*  
  float **mat1,**mat2,**mat3;
  inicio_bruta=clock();
  mat1=matrix_bruta(25000000);
  print_bruta(mat1,25000000);
  mat2=matrix_bruta(25000000);
  print_bruta(mat2,25000000);
  mat3=matrix_soma_bruta(mat1,mat2,25000000);
  print_bruta(mat3,25000000);
  matrix_destroy_bruta(mat3,25000000);
  mat3=matrix_multiplica_bruta(mat1,mat2,25000000);
  print_bruta(mat3,25000000);
  matrix_destroy_bruta(mat3,25000000);
  mat3=matrix_bruta_transposta(mat1,25000000);
  print_bruta(mat3,25000000);
  matrix_destroy_bruta(mat3,25000000);  
  matrix_destroy_bruta(mat1,25000000);  
  matrix_destroy_bruta(mat2,25000000);  
  fim_bruta = clock();
  FILE* f2 = fopen("prints_bruta.txt","a");
  tempo_bruta=(double)(fim_bruta-inicio_bruta)/CLOCKS_PER_SEC;
  fprintf(f2,"\nTempo por forca bruta: %.2lf\n",tempo_bruta);
  fclose(f2);
  return 0;
  */
}
/* --------------< matrix.c >-------------- */
Matrix *matrix_create(void) {
  int linhas, colunas, aux,verificador=1;
  float valor;
  FILE *d=fopen("prints.txt","r");
  if(fscanf(d,"%d %d",&linhas,&colunas) == EOF){
    verificador=0;
  }
  fclose(d);
  if(verificador==0){
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    alocacoes++;
    if (m == NULL) {
      printf("\nMalloc devolveu NULL.\n");
      exit(1);
    }
    m->linha = -1;
    m->coluna = -1;
    Matrix *aponta = m;
    FILE *f = fopen("matrix.txt", "r");
    fscanf(f, "%d %d", &linhas, &colunas);
    while (linhas != 0) {
      aponta->abaixo = (Matrix *)malloc(sizeof(Matrix));
      if (aponta->abaixo) {
        alocacoes++;
        aponta = aponta->abaixo;
        aponta->direita = aponta;
        aponta->linha = -1;
        aponta->abaixo = m;
        linhas--;
      } else {
        printf("\nMalloc devolveu NULL.\n");
        exit(1);
      }
    }
    aponta = m;
    while (colunas != 0) {
      aponta->direita = (Matrix *)malloc(sizeof(Matrix));
      if (aponta->direita) {
        alocacoes++;
        aponta = aponta->direita;
        aponta->abaixo = aponta;
        aponta->coluna = -1;
        aponta->direita = m;
        colunas--;
      } else {
        printf("\nMalloc devolveu NULL\n");
        exit(1);
      }
    }
    float valor;
    Matrix *cabeca;
    while ((fscanf(f, "%d %d %f", &linhas, &colunas, &valor) != EOF)&&((linhas!=0)||(colunas!=0)||(valor!=0.0))) { // Erro
      Matrix *novo = malloc(sizeof(Matrix));

      if (novo) {
        alocacoes++;
        cabeca = m;
        aux = -1;
        while (aux != colunas) { // Percorre o cabeçalho das linhas até a linha do elemento
          cabeca = cabeca->direita;
          aux++;
        }
        aponta = cabeca;
        while (aponta->abaixo != cabeca) { // Percorre até o ultimo elemento da linha
          aponta = aponta->abaixo;
        }
        aponta->abaixo = novo;
        aponta = aponta->abaixo;
        novo->abaixo = cabeca;
        novo->informacao = valor;
        novo->linha=linhas;
        novo->coluna=colunas;
        cabeca = m;
        aux = -1;
        while (aux != linhas) {
          cabeca = cabeca->abaixo;
          aux++;
        }
        aponta = cabeca;
        while (aponta->direita != cabeca) { // Percorre até o ultimo elemento da linha
          aponta = aponta->direita;
        }
        aponta->direita = novo;
        novo->direita = cabeca;
      } else {
        printf("\nMalloc devolveu NULL\n");
      }
    }
    fclose(f);
    return m;
  }else{
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    alocacoes++;
    if (m == NULL) {
      printf("\nMalloc devolveu NULL.\n");
      exit(1);
    }
    m->linha = -1;
    m->coluna = -1;
    Matrix *aponta = m;
    FILE *f = fopen("matrix.txt", "r");
    fscanf(f, "%d %d", &linhas, &colunas);
    int l1,j1;
    float v;
    l1=linhas;
    j1=colunas;
    v = 1.0;
    while((l1!=0)||(j1!=0)||(v!=0.0)){
      fscanf(f,"%d %d %f",&l1,&j1,&v);
    }
    fscanf(f, "%d %d", &linhas, &colunas);
    while (linhas != 0) {
      aponta->abaixo = (Matrix *)malloc(sizeof(Matrix));
      if (aponta->abaixo) {
        alocacoes++;
        aponta = aponta->abaixo;
        aponta->direita = aponta;
        aponta->linha = -1;
        aponta->abaixo = m;
        linhas--;
      } else {
        printf("\nMalloc devolveu NULL.\n");
        exit(1);
      }
    }
    aponta = m;
    while (colunas != 0) {
      aponta->direita = (Matrix *)malloc(sizeof(Matrix));
      if (aponta->direita) {
        alocacoes++;
        aponta = aponta->direita;
        aponta->abaixo = aponta;
        aponta->coluna = -1;
        aponta->direita = m;
        colunas--;
      } else {
        printf("\nMalloc devolveu NULL\n");
        exit(1);
      }
    }
    Matrix *cabeca;
    while ((fscanf(f, "%d %d %f", &linhas, &colunas, &valor) != EOF)&&((linhas!=0)||(colunas!=0)||(valor!=0.0))) { // Erro
      Matrix *novo = malloc(sizeof(Matrix));

      if (novo) {
        alocacoes++;
        cabeca = m;
        aux = -1;
        while (aux != colunas) { // Percorre o cabeçalho das linhas até a linha do elemento
          cabeca = cabeca->direita;
          aux++;
        }
        aponta = cabeca;
        while (aponta->abaixo != cabeca) { // Percorre até o ultimo elemento da linha
          aponta = aponta->abaixo;
        }
        aponta->abaixo = novo;
        aponta = aponta->abaixo;
        novo->abaixo = cabeca;
        novo->informacao = valor;
        novo->linha=linhas;
        novo->coluna=colunas;
        cabeca = m;
        aux = -1;
        while (aux != linhas) {
          cabeca = cabeca->abaixo;
          aux++;
        }
        aponta = cabeca;
        while (aponta->direita != cabeca) { // Percorre até o ultimo elemento da linha
          aponta = aponta->direita;
        }
        aponta->direita = novo;
        novo->direita = cabeca;
      } else {
        printf("\nMalloc devolveu NULL\n");
      }
    }
    fclose(f);
    return m;
  }
}
void matrix_destroy(Matrix* m){
  if(m){
    if(m->abaixo != NULL){
        Matrix *anterior,*aponta,*cabeca = m->abaixo;
        while(cabeca!=m){
          aponta = cabeca;
          while(aponta->direita!=cabeca){
            anterior = aponta;
            aponta=aponta->direita;
            if(anterior != cabeca){ 
              free(anterior);
              desalocacoes++;
            }
          }
          if(aponta != cabeca){
            free(aponta);
            desalocacoes++;
          }
          aponta = cabeca;
          cabeca = cabeca->abaixo;
          free(aponta);
          desalocacoes++;
        }
        cabeca=m->direita;
        while(cabeca!=m){
            anterior=cabeca;
            cabeca=cabeca->direita;
            free(anterior);
            desalocacoes++;
        }
        free(m);
        desalocacoes++; 
    }
  }else{
    printf("\nNada para desalocar\n");
  }
}
void matrix_print(Matrix *m){
  if(m){
    FILE *f = fopen("prints.txt", "a");
    Matrix *cabeca=m,*aponta;
    int linhas=0,colunas=0;
    while(cabeca->abaixo!=m){
      cabeca = cabeca->abaixo;
      linhas++;
    }
    cabeca = m;
    while(cabeca->direita!=m){
      cabeca = cabeca->direita;
      colunas++;
    }
    fprintf(f,"%d %d\n",linhas,colunas);
    cabeca = m;
    while(cabeca->abaixo!=m){
      cabeca = cabeca->abaixo;
      aponta = cabeca;
      while(aponta->direita!=cabeca){
        aponta=aponta->direita;
        fprintf(f,"%d %d %.1f\n",aponta->linha,aponta->coluna,aponta->informacao);
      }
    }
    fprintf(f,"\n\n\n");
    fclose(f);
  }else{
    printf("\nNada para mostrar\n");
  }
}
Matrix* matrix_add(Matrix* m, Matrix* n){
  Matrix *aponta,*cabeca;
  int linhas1=0,colunas1=0;
  cabeca = m;
  while(cabeca->abaixo!=m){
    cabeca=cabeca->abaixo;
    linhas1++;
  }    
  cabeca = m;
  while(cabeca->direita!=m){
    cabeca=cabeca->direita;
    colunas1++;
  }
  int linhas2=0,colunas2=0;
  cabeca = n;
  while(cabeca->abaixo!=n){
    cabeca=cabeca->abaixo;
    linhas2++;
  }    
  cabeca = n;
  while(cabeca->direita!=n){
    cabeca=cabeca->direita;
    colunas2++;
  }
  if((linhas1==linhas2) && (colunas1 == colunas2)){
    float *mat1 = (float*)malloc(linhas1*colunas1*sizeof(float));
    if(mat1 == NULL){
      printf("\nMalloc devolveu NULL\n");
    }
    int i,j;
    for(i=0;i<linhas1;i++){
      for(j=0;j<colunas1;j++){
        mat1[i*colunas1+j]=0;
      }
    }
    cabeca = m;
    while(cabeca->abaixo != m){
      cabeca=cabeca->abaixo;
      aponta = cabeca;
      while(aponta->direita != cabeca){
        aponta = aponta->direita;
        i=aponta->linha;
        j=aponta->coluna;
        mat1[i*colunas1+j] = aponta->informacao;
      }
    }
    float *mat2 = (float*)malloc(linhas2*colunas2*sizeof(float));
    if(mat2 == NULL){
      printf("\nMalloc devolveu NULL\n");
    }
    for(i=0;i<linhas2;i++){
      for(j=0;j<colunas2;j++){
        mat2[i*colunas2+j]=0;
      }
    }
    cabeca = n;
    while(cabeca->abaixo != n){
      cabeca=cabeca->abaixo;
      aponta = cabeca;
      while(aponta->direita != cabeca){
        aponta = aponta->direita;
        i = aponta->linha;
        j=aponta->coluna;
        mat2[i*colunas2+j] = aponta->informacao;
      }
    }
    float *mat3 = (float*)malloc(linhas2*colunas2*sizeof(float));
    for(i=0;i<linhas1;i++){
      for(j=0;j<colunas1;j++){
        mat3[i*colunas1+j] = mat1[i*colunas1+j] + mat2[i*colunas1+j];
      }
    }
    Matrix *matrix_soma =(Matrix*)malloc(sizeof(Matrix));
    if (matrix_soma == NULL) {
      printf("\nMalloc devolveu NULL.\n");
      exit(1);
    }
    alocacoes++;
    matrix_soma->linha = -1;
    matrix_soma->coluna = -1;
    aponta = matrix_soma;
    int aux=0;
    while (aux != linhas1) {
      aponta->abaixo = (Matrix *)malloc(sizeof(Matrix));
      if (aponta->abaixo) {
        alocacoes++;
        aponta = aponta->abaixo;
        aponta->direita = aponta;
        aponta->linha = -1;
        aponta->abaixo = matrix_soma;
        aux++;
      } else {
        printf("\nMalloc devolveu NULL.\n");
        exit(1);
      }
    }
    aux=0;
    aponta = matrix_soma;
    while (aux != colunas1) {
      aponta->direita = (Matrix *)malloc(sizeof(Matrix));
      if (aponta->direita) {
        alocacoes++;
        aponta = aponta->direita;
        aponta->abaixo = aponta;
        aponta->coluna = -1;
        aponta->direita = matrix_soma;
        aux++;
      } else {
        printf("\nMalloc devolveu NULL\n");
        exit(1);
      }
    }
    Matrix *cabeca;
    for(i=0;i<linhas1;i++){
      for(j=0;j<colunas1;j++){
        if(mat3[i*colunas1+j] != 0){
          Matrix *novo = malloc(sizeof(Matrix));
          if (novo) {
            alocacoes++;
            cabeca = matrix_soma;
            aux = -1;
            while (aux != j) { // Percorre o cabeçalho das linhas até a linha do elemento
              cabeca = cabeca->direita;
              aux++;
            }
            aponta = cabeca;
            while (aponta->abaixo != cabeca) { // Percorre até o ultimo elemento da linha
              aponta = aponta->abaixo;
            }
            aponta->abaixo = novo;
            aponta = aponta->abaixo;
            novo->abaixo = cabeca;
            novo->linha=i;
            novo->coluna=j;
            novo->informacao=mat3[i*colunas1+j];
            cabeca = matrix_soma;
            aux = -1;
            while (aux != i) {
              cabeca = cabeca->abaixo;
              aux++;
            }
            aponta = cabeca;
            while (aponta->direita != cabeca) { // Percorre até o ultimo elemento da linha
              aponta = aponta->direita;
            }
            aponta->direita = novo;
            novo->direita = cabeca;
          } else {
            printf("\nMalloc devolveu NULL\n");
          }
        }
      }
    }
    free(mat1);
    free(mat2);
    free(mat3);
    return matrix_soma;
  }else{
    printf("\nNao e possivel somar matrizes de ordens diferentes!\n");
    return NULL;
  }
}
Matrix *matrix_multiply(Matrix *m, Matrix *n){
  if((m!=NULL)&&(n!=NULL)){
    Matrix *aponta,*cabeca;
    // Conta as linhas e colunas da matriz m
    int linhas1=0,colunas1=0;
    cabeca = m;
    while(cabeca->abaixo!=m){
      cabeca=cabeca->abaixo;
      linhas1++;
    }    
    cabeca = m;
    while(cabeca->direita!=m){
      cabeca=cabeca->direita;
      colunas1++;
    }
    // Conta as linhas e colunas da matriz n
    int linhas2=0,colunas2=0;
    cabeca = n;
    while(cabeca->abaixo!=n){
      cabeca=cabeca->abaixo;
      linhas2++;
    }    
    cabeca = n;
    while(cabeca->direita!=n){
      cabeca=cabeca->direita;
      colunas2++;
    }
    // Checa se é possivel fazer a multiplicação
    if(colunas1==linhas2){
      float *mat1 = (float*)malloc(linhas1*colunas1*sizeof(float));
      if(mat1 == NULL){
        printf("\nMalloc devolveu NULL\n");
      }
      int i,j,k;
      for(i=0;i<linhas1;i++){
        for(j=0;j<colunas1;j++){
          mat1[i*colunas1+j]=0;
        }
      }
      cabeca = m;
      while(cabeca->abaixo != m){
        cabeca=cabeca->abaixo;
        aponta = cabeca;
        while(aponta->direita != cabeca){
          aponta = aponta->direita;
          i=aponta->linha;
          j=aponta->coluna;
          mat1[i*colunas1+j] = aponta->informacao;
        }
      }
      float *mat2 = (float*)malloc(linhas2*colunas2*sizeof(float));
      if(mat2 == NULL){
        printf("\nMalloc devolveu NULL\n");
      }
      for(i=0;i<linhas2;i++){
        for(j=0;j<colunas2;j++){
          mat2[i*colunas2+j]=0;
        }
      }
      cabeca = n;
      while(cabeca->abaixo != n){
        cabeca=cabeca->abaixo;
        aponta = cabeca;
        while(aponta->direita != cabeca){
          aponta = aponta->direita;
          i = aponta->linha;
          j=aponta->coluna;
          mat2[i*colunas2+j] = aponta->informacao;
        }
      }
      float *mat3 = (float*)malloc(linhas1*colunas2*sizeof(float));
      for(i=0;i<linhas1;i++){
        for(j=0;j<colunas2;j++){
          mat3[i*colunas2+j]=0;
          for(k=0;k<colunas2;k++){
            mat3[i*colunas2+j]+=mat1[i*colunas1+k]*mat2[k*colunas2+j];
          }
        }
      }//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
      Matrix *matrix_multiplicada=(Matrix*)malloc(sizeof(Matrix));
      if (matrix_multiplicada == NULL) {
        printf("\nMalloc devolveu NULL.\n");
        exit(1);
      }
      alocacoes++;
      matrix_multiplicada->linha = -1;
      matrix_multiplicada->coluna = -1;
      aponta = matrix_multiplicada;
      int aux=0;
      while (aux != linhas1) {
        aponta->abaixo = (Matrix *)malloc(sizeof(Matrix));
        if (aponta->abaixo) {
          alocacoes++;
          aponta = aponta->abaixo;
          aponta->direita = aponta;
          aponta->linha = -1;
          aponta->abaixo = matrix_multiplicada;
          aux++;
        } else {
          printf("\nMalloc devolveu NULL.\n");
          exit(1);
        }
      }
      aux=0;
      aponta = matrix_multiplicada;
      while (aux != colunas2) {
        aponta->direita = (Matrix *)malloc(sizeof(Matrix));
        if (aponta->direita) {
          alocacoes++;
          aponta = aponta->direita;
          aponta->abaixo = aponta;
          aponta->coluna = -1;
          aponta->direita = matrix_multiplicada;
          aux++;
        } else {
          printf("\nMalloc devolveu NULL\n");
          exit(1);
        }
      }
      for(i=0;i<linhas1;i++){
        for(j=0;j<colunas2;j++){
          if(mat3[i*colunas2+j] != 0){
            Matrix *novo = malloc(sizeof(Matrix));
            if (novo) {
              alocacoes++;
              cabeca = matrix_multiplicada;
              aux = -1;
              while (aux != j) { // Percorre o cabeçalho das colunas até a linha do elemento
                cabeca = cabeca->direita;
                aux++;
              }
              aponta = cabeca;
              while (aponta->abaixo != cabeca) { // Percorre até o ultimo elemento da coluna
                aponta = aponta->abaixo;
              }
              aponta->abaixo = novo;
              aponta = aponta->abaixo;
              novo->abaixo = cabeca;
              novo->linha=i;
              novo->coluna=j;
              novo->informacao=mat3[i*colunas2+j];
              cabeca = matrix_multiplicada;
              aux = -1;
              while (aux != i) {
                cabeca = cabeca->abaixo;
                aux++;
              }
              aponta = cabeca;
              while (aponta->direita != cabeca) { // Percorre até o ultimo elemento da linha
                aponta = aponta->direita;
              }
              aponta->direita = novo;
              novo->direita = cabeca;
            } else {
              printf("\nMalloc devolveu NULL\n");
            }
          }
        }
      }
      free(mat1);
      free(mat2);
      free(mat3);
      return matrix_multiplicada;
    }else{
      printf("\nNao e possivel\n");
      exit(1);
    }
  }else{
    printf("\nNao e possivel multiplicar\n");
    exit(1);
  }

}
Matrix *matrix_transpose(Matrix *m){
  Matrix *aponta,*cabeca=m;
  int aux=0,linhas1=0,colunas1=0;
  cabeca = m;
  while(cabeca->abaixo!=m){
    cabeca=cabeca->abaixo;
    linhas1++;
  }    
  cabeca = m;
  while(cabeca->direita!=m){
    cabeca=cabeca->direita;
    colunas1++;
  }
  Matrix* t = (Matrix*) malloc(sizeof(Matrix));
  if(t == NULL){
    printf("\nMalloc devolveu NULL\n");
    exit(1);
  }
  alocacoes++;
  aponta = t;
  while (aux != colunas1) {
    aponta->abaixo = (Matrix *)malloc(sizeof(Matrix));
    if (aponta->abaixo) {
      alocacoes++;
      aponta = aponta->abaixo;
      aponta->direita = aponta;
      aponta->linha = -1;
      aponta->abaixo = t;
      aux++;
    } else {
      printf("\nMalloc devolveu NULL.\n");
      exit(1);
    }
  }
  aux=0;
  aponta = t;
  while (aux != linhas1) {
    aponta->direita = (Matrix *)malloc(sizeof(Matrix));
    if (aponta->direita) {
      alocacoes++;
      aponta = aponta->direita;
      aponta->abaixo = aponta;
      aponta->coluna = -1;
      aponta->direita = t;
      aux++;
    } else {
      printf("\nMalloc devolveu NULL.\n");
      exit(1);
    }
  }
  float *mat1 = (float*)malloc(linhas1*colunas1*sizeof(float));
  int i,j;
  for(i=0;i<linhas1;i++){
    for(j=0;j<colunas1;j++){
      mat1[i*colunas1+j]=0;
    }
  }
  cabeca = m;
  while(cabeca->abaixo != m){
    cabeca=cabeca->abaixo;
    aponta = cabeca;
    while(aponta->direita != cabeca){
      aponta = aponta->direita;
      i=aponta->linha;
      j=aponta->coluna;
      mat1[i*colunas1+j] = aponta->informacao;
    }
  }
  float *transposta = (float*)malloc(linhas1*colunas1*sizeof(float));
  for(i=0;i<colunas1;i++){
    for(j=0;j<linhas1;j++){
      transposta[i*linhas1+j]=mat1[j*colunas1+i];
    }
  }
  free(mat1);
  for(i=0;i<colunas1;i++){
    for(j=0;j<linhas1;j++){
      if(transposta[i*linhas1+j] != 0){
        Matrix *novo = malloc(sizeof(Matrix));
        if (novo) {
          alocacoes++;
          cabeca = t;
          aux = -1;
          while (aux != j) { // Percorre o cabeçalho das colunas até a linha do elemento
            cabeca = cabeca->direita;
            aux++;
          }
          aponta = cabeca;
          while (aponta->abaixo != cabeca) { // Percorre até o ultimo elemento da linha
            aponta = aponta->abaixo;
          }
          aponta->abaixo = novo;
          aponta = aponta->abaixo;
          novo->abaixo = cabeca;
          novo->linha=i;
          novo->coluna=j;
          novo->informacao=transposta[i*linhas1+j];
          cabeca = t;
          aux = -1;
          while (aux != i) {
            cabeca = cabeca->abaixo;
            aux++;
          }
          aponta = cabeca;
          while (aponta->direita != cabeca) { // Percorre até o ultimo elemento da linha
            aponta = aponta->direita;
          }
          aponta->direita = novo;
          novo->direita = cabeca;
        } else {
          printf("\nMalloc devolveu NULL\n");
        }
      }
    }
  }
  free(transposta);
  return t;
}
float matrix_getelem(Matrix *m, int x, int y){
  Matrix *aponta,*cabeca=m;
  if(m){
    float valor;
    int aux=-1;
    while(aux!=x){
      cabeca = cabeca->abaixo;
      aux++;
    }
    aux=-1;
    aponta = cabeca;
    while((aponta->direita != cabeca)&&(aponta->coluna!=y)){
      aponta = aponta->direita;
    }
    if(aponta->direita!=cabeca){
      valor = aponta->informacao;
    }else{
      valor=0.0;
    }
    return valor;
  }else{
    printf("\nNada para procurar\n");
    exit(1);
  }
}
void matrix_setelem(Matrix *m, int x, int y, float elem){
  Matrix *anterior,*aponta,*cabeca=m;
  if(m){
    int aux=-1;
    while(aux!=x){
      cabeca = cabeca->abaixo;
      aux++;
    }
    if(cabeca->direita != cabeca){
      aponta = cabeca->direita;
      anterior = cabeca;
    }
    while((aponta!=cabeca)&&(aponta->coluna<y)){
      anterior = aponta;
      aponta = aponta->direita;
    }
    if(aponta->coluna==y){
      aponta->informacao = elem;
    }else{
      Matrix *novo=malloc(sizeof(Matrix));
      if(novo){
        alocacoes++;
        anterior->direita = novo;
        novo->linha=x;
        novo->coluna=y;
        novo->direita = aponta;
        novo->informacao = elem;
      }else{
        printf("\nMalloc retornou NULL\n");
      }
    }
  }else{
    printf("\nNada para procurar\n");
    exit(1);
  }
}
Matrix* matrix_create_rand(unsigned int m){
  int i;
  Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
  if (mat == NULL) {
    printf("\nMalloc devolveu NULL.\n");
    exit(1);
  }
  alocacoes++;
  mat->linha = -1;
  mat->coluna = -1;
  Matrix *cabeca,*aponta = mat;
  int linhas = (int) sqrt(m),colunas = (int) sqrt(m);
  int l = linhas,c = colunas;
  while (l != 0) {
    aponta->abaixo = (Matrix *)malloc(sizeof(Matrix));
    if (aponta->abaixo) {
      alocacoes++;
      aponta = aponta->abaixo;
      aponta->direita = aponta;
      aponta->linha = -1;
      aponta->abaixo = mat;
      l--;
    } else {
      printf("\nMalloc devolveu NULL.\n");
      exit(1);
    }
  }
  aponta = mat;
  while (c != 0) {
    aponta->direita = (Matrix *)malloc(sizeof(Matrix));
    if (aponta->direita) {
      alocacoes++;
      aponta = aponta->direita;
      aponta->abaixo = aponta;
      aponta->coluna = -1;
      aponta->direita = mat;
      c--;
    } else {
      printf("\nMalloc devolveu NULL\n");
      exit(1);
    }
  }
  float valor;
  int aux,j;
  for(i=0;i<linhas;i++){
    for(j=0;j<colunas;j++){
      valor = rand()%201-100;
      if(valor!=0){
        Matrix *novo=malloc(sizeof(Matrix));
        if (novo) {
          alocacoes++;
          cabeca = mat;
          aux = -1;
          while (aux != j) { // Percorre o cabeçalho das linhas até a linha do elemento
            cabeca = cabeca->direita;
            aux++;
          }
          aponta = cabeca;
          while (aponta->abaixo != cabeca) { // Percorre até o ultimo elemento da linha
            aponta = aponta->abaixo;
          }
          aponta->abaixo = novo;
          aponta = aponta->abaixo;
          novo->abaixo = cabeca;
          novo->informacao = valor;
          novo->linha=i;
          novo->coluna=j;
          cabeca = mat;
          aux = -1;
          while (aux != i) {
            cabeca = cabeca->abaixo;
            aux++;
          }
          aponta = cabeca;
          while (aponta->direita != cabeca) { // Percorre até o ultimo elemento da linha
            aponta = aponta->direita;
          }
          aponta->direita = novo;
          novo->direita = cabeca;
        } else {
          printf("\nMalloc devolveu NULL\n");
        }
      }
    }
  }
  return mat;
}
float** matrix_bruta(unsigned int m){
  int i,j;
  int n = (int) sqrt(m);
  float **mat = (float**) malloc(n*sizeof(float*));
  for(i=0;i<n;i++){
    mat[i]=(float*)malloc(n*sizeof(float));
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      mat[i][j]=rand()%200-100;
    }
  }
  return mat;
}
void matrix_destroy_bruta(float **mat,unsigned int m){
  int i;
  for(i=0;i<sqrt(m);i++){
    free(mat[i]);
  }
  free(mat);
  printf("\nDesalocada com sucesso!\n");
}
float** matrix_multiplica_bruta(float **m,float **n,unsigned int t){
  int i,j,k;
  float** matr = (float**) malloc(sqrt(t)*sizeof(float*));
  for(i=0;i<sqrt(t);i++){
    matr[i]=(float*)malloc(sqrt(t)*sizeof(float));
  }
  for(i=0;i<sqrt(t);i++){
    for(j=0;j<sqrt(t);j++){
      matr[i][j] = 0;
      for(k=0;k<sqrt(t);k++){
        matr[i][j] = m[i][k]*n[k][j];
      }
    }
  }
  return matr;
}
float** matrix_soma_bruta(float **m,float **n,unsigned int t){
  int i,j;
  float** matr = (float**) malloc(sqrt(t)*sizeof(float*));
  for(i=0;i<sqrt(t);i++){
    matr[i]=(float*)malloc(sqrt(t)*sizeof(float));
  }
  for(i=0;i<sqrt(t);i++){
    for(j=0;j<sqrt(t);j++){
      matr[i][j] = m[i][j] + n[i][j];
    }
  }
  return matr;
}
void print_bruta(float **m, unsigned int t){
  FILE* f = fopen("prints_bruta.txt","a");
  int i,j;
  int n = (int) sqrt(t);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      fprintf(f,"%.1f\t",m[i][j]);
    }
    fprintf(f,"\n");
  }
  fprintf(f,"\n\n");
  fclose(f);
}
float** matrix_bruta_transposta(float **m,unsigned int t){
  int i,j;
  float** matr = (float**) malloc(sqrt(t)*sizeof(float*));
  for(i=0;i<sqrt(t);i++){
    matr[i]=(float*)malloc(sqrt(t)*sizeof(float));
  }
  for(i=0;i<sqrt(t);i++){
    for(j=0;j<sqrt(t);j++){
      matr[i][j] = m[j][i];
    }
  }
  return matr;
}
