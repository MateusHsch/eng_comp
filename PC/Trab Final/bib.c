#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "bib.h"

int menuJogar(){
    int op,bool;
    do{
      printf("1 - Para mover o agente.\n");
      printf("2 - Disparar flecha.\n");
      printf("3 - Dica.\n");
      printf("4 - Encerrar jogo.\n");
      printf("Insira a opcao do menu que deseja:\n");
      scanf("%d", &op); 
      getchar();
      if (op >= 1 && op <= 4) {
        bool = 1;
      } else {
        printf("Opcao invalida!!!\n");
      }
    }while(bool!=1);
    
  return op;
}
void gerarMatriz(Square mat[][8]) {
  int i, j;
  int abismos = 0, ouro = 0, flecha = 0, monstro = 0;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      mat[i][j].display = 'X';
      mat[i][j].entidade = 'X';
    }
  }
  mat[7][0].entidade = 'A';
  mat[7][0].display = 'A';
  while (abismos < 5) {
    i = rand() % 8 + 1;
    j = rand() % 8 + 1;
    if (mat[i][j].entidade == 'X') {
      mat[i][j].entidade = 'P';
      abismos++;
    }
  }
  while (ouro < 1) {
    i = rand() % 8 + 1;
    j = rand() % 8 + 1;
    if (mat[i][j].entidade == 'X') {
      mat[i][j].entidade = 'O';
      ouro++;
    }
  }
  while (flecha < 1) {
    i = rand() % 8 + 1;
    j = rand() % 8 + 1;
    if (mat[i][j].entidade == 'X') {
      mat[i][j].entidade = 'F';
      flecha++;
    }
  }
  while (monstro < 1) {
    i = rand() % 8 + 1;
    j = rand() % 8 + 1;
    if (mat[i][j].entidade == 'X') {
      mat[i][j].entidade = 'W';
      monstro++;
    }
  }
}
void printMatriz(Square mat[][8], int debug) {
  int i, j;
  if (debug == 1) {
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        mat[i][j].display = mat[i][j].entidade;
      }
    }
  }
  for (i = 0; i < 10; i++) {
    switch (i) {
    case 0:
      printf("H | ");
      break;
    case 1:
      printf("G | ");
      break;
    case 2:
      printf("F | ");
      break;
    case 3:
      printf("E | ");
      break;
    case 4:
      printf("D | ");
      break;
    case 5:
      printf("C | ");
      break;
    case 6:
      printf("B | ");
      break;
    case 7:
      printf("A | ");
      break;
    case 8:
      printf("   ");
      break;
    case 9:
      printf("    ");
      break;
    default:
      break;
    }
    for (j = 0; j < 8; j++) {
      if (i == 8) {
        printf("--");
      } else if (i == 9) {
        printf("%d ", j + 1);
      } else {
        printf("%c ", mat[i][j].display);
      }
    }
    printf("\n");
  }
}
int moverAgente(Square mat[][8],int *debug,int *movimentos) {
  int i, j, situacao = 0, ok = 0,bool;
  char move;
  *movimentos+=1;
  do{
    bool=1;
    fflush(stdin);
    printf("w - cima\n");
    printf("a - esquerda\n");
    printf("s - baixo\n");
    printf("d - direita\n");
    printf("Para onde o agente deve se mover:\n");
    scanf("%c", &move);
    switch (move) {
    case 'w':
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          if (mat[i][j].entidade == 'A' && ok == 0) {
            if (i - 1 != -1) { // Testa a borda do mapa
              if (mat[i - 1][j].entidade == 'P') {
                printf("O agente caiu em um abismo!\n");
                situacao = 1; // morte
                break;
              } else if (mat[i - 1][j].entidade == 'W') {
                printf("O agente foi pego pelo Wumpus!\n");
                situacao = 1; // morte
                break;
              } else if (mat[i - 1][j].entidade == 'O') {
                printf("O agente achou o ouro!\n");
                situacao = 2; // ouro
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i - 1][j].entidade = 'A';
                mat[i - 1][j].display = 'A';
                ok = 1;
                break;
              } else if (mat[i - 1][j].entidade == 'F') {
                printf("O agente achou uma flecha!\n");
                situacao = 3; // flecha
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i - 1][j].entidade = 'A';
                mat[i - 1][j].display = 'A';
                ok = 1;
                break;
              } else {
                printf("O agente se moveu!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i - 1][j].entidade = 'A';
                mat[i - 1][j].display = 'A';
                ok = 1;
                break;
              }
            } else {
              printf("O agente bate em uma parede!\n");
              break;
            }
          }
        }
      }
      break;
    case 'a':
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          if (mat[i][j].entidade == 'A' && ok == 0) {
            if (j - 1 != -1) { // Testa a borda do mapa
              if (mat[i][j - 1].entidade == 'P') {
                printf("O agente caiu em um abismo!\n");
                situacao = 1; // morte
                break;
              } else if (mat[i][j - 1].entidade == 'W') {
                printf("O agente foi pego pelo Wumpus!\n");
                situacao = 1; // morte
                break;
              } else if (mat[i][j - 1].entidade == 'O') {
                printf("O agente achou o ouro!\n");
                situacao = 2; // ouro
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j - 1].entidade = 'A';
                mat[i][j - 1].display = 'A';
                ok = 1;
                break;
              } else if (mat[i][j - 1].entidade == 'F') {
                printf("O agente achou uma flecha!\n");
                situacao = 3; // flecha
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j - 1].entidade = 'A';
                mat[i][j - 1].display = 'A';
                ok = 1;
                break;
              } else {
                printf("O agente se moveu!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j - 1].entidade = 'A';
                mat[i][j - 1].display = 'A';
                ok = 1;
                break;
              }
            } else {
              printf("O agente bate em uma parede!\n");
              break;
            }
          }
        }
      }
      break;
    case 's':
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          if (mat[i][j].entidade == 'A' && ok == 0) {
            if (i + 1 != 8) { // Testa a borda do mapa
              if (mat[i + 1][j].entidade == 'P') {
                printf("O agente caiu em um abismo!\n");
                situacao = 1; // morte
                break;
              } else if (mat[i + 1][j].entidade == 'W') {
                printf("O agente foi pego pelo Wumpus!\n");
                situacao = 1; // morte
                break;
              } else if (mat[i + 1][j].entidade == 'O') {
                printf("O agente achou o ouro!\n");
                situacao = 2; // ouro
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i + 1][j].entidade = 'A';
                mat[i + 1][j].display = 'A';
                ok = 1;
                break;
              } else if (mat[i + 1][j].entidade == 'F') {
                printf("O agente achou uma flecha!\n");
                situacao = 3; // flecha
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i + 1][j].entidade = 'A';
                mat[i + 1][j].display = 'A';
                ok = 1;
                break;
              } else {
                printf("O agente se moveu!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i + 1][j].entidade = 'A';
                mat[i + 1][j].display = 'A';
                ok = 1;
                break;
              }
            } else {
              printf("O agente bate em uma parede!\n");
              break;
            }
          }
        }
      }
      break;
    case 'd':
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          if (mat[i][j].entidade == 'A' && ok == 0) {
            if (j + 1 != 8) { // Testa a borda do mapa
              if (mat[i][j + 1].entidade == 'P') {
                printf("O agente caiu em um abismo!\n");
                situacao = 1; // morte
                break;
              } else if (mat[i][j + 1].entidade == 'W') {
                printf("O agente foi pego pelo Wumpus!\n");
                situacao = 1; // morte
                break;
              } else if (mat[i][j + 1].entidade == 'O') {
                printf("O agente achou o ouro!\n");
                situacao = 2; // ouro
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j + 1].entidade = 'A';
                mat[i][j + 1].display = 'A';
                ok = 1;
                break;
              } else if (mat[i][j + 1].entidade == 'F') {
                printf("O agente achou uma flecha!\n");
                situacao = 3; // flecha
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j + 1].entidade = 'A';
                mat[i][j + 1].display = 'A';
                ok = 1;
                break;
              } else {
                printf("O agente se moveu!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j + 1].entidade = 'A';
                mat[i][j + 1].display = 'A';
                ok = 1;
                break;
              }
            } else {
              printf("O agente bate em uma parede!\n");
              break;
            }
          }
        }
      }
      break;
    default:
      printf("direcao invalida.\n");
      bool=0;
      system("cls");
      printMatriz(mat,*debug);
      break;
    }
  }while (bool != 1);
  sleep(1);
  return situacao;
}
int moverMonstro(Square mat[][8]){
  int i,j,move,situacao=0,ok=0,bool;
  do{
    bool=1;
    move = rand()%4 +1;
    switch (move){
    case 1:
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          if (mat[i][j].entidade == 'W' && ok == 0) {
            if (i - 1 != -1 && mat[i-1][j].entidade != 'P' && mat[i-1][j].entidade != 'O') { // Testa a borda do mapa
              if (mat[i-1][j].entidade == 'F') {
                printf("O Wumpus destroiu uma flecha!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i-1][j].entidade = 'W';
                ok = 1;
                break;
              } else if (mat[i-1][j].entidade == 'A'){
                printf("O Wumpus matou o agente!\n");
                situacao = 1;
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i-1][j].entidade = 'W';
                ok = 1;
              }else {
                printf("O Wumpus se moveu!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i-1][j].entidade = 'W';
                ok = 1;
                break;
              }
            } else {
              bool=0;
              break;
            }
          }
        }
      }
      break;
    case 2:
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          if (mat[i][j].entidade == 'W' && ok == 0) {
            if (j - 1 != -1 && mat[i][j-1].entidade != 'P' && mat[i][j-1].entidade != 'O') { // Testa a borda do mapa
              if (mat[i][j - 1].entidade == 'F') {
                printf("O Wumpus destroiu uma flecha!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j-1].entidade = 'W';
                ok = 1;
                break;
              } else if (mat[i][j - 1].entidade == 'A'){
                printf("O Wumpus matou o agente!\n");
                situacao = 1;
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j-1].entidade = 'W';
                ok = 1;
              }else {
                printf("O Wumpus se moveu!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j-1].entidade = 'W';
                ok = 1;
                break;
              }
            } else {
              bool=0;
              break;
            }
          }
        }
      }
      break;
    case 3:
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          if (mat[i][j].entidade == 'W' && ok == 0) {
            if (i + 1 != 8 && mat[i+1][j].entidade != 'P' && mat[i+1][j].entidade != 'O') { // Testa a borda do mapa
              if (mat[i+1][j].entidade == 'F') {
                printf("O Wumpus destroiu uma flecha!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i+1][j].entidade = 'W';
                ok = 1;
                break;
              } else if (mat[i+1][j].entidade == 'A'){
                printf("O Wumpus matou o agente!\n");
                situacao = 1;
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i+1][j].entidade = 'W';
                ok = 1;
              }else {
                printf("O Wumpus se moveu!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i+1][j].entidade = 'W';
                ok = 1;
                break;
              }
            } else {
              bool=0;
              break;
            }
          }
        }
      }
      break;
    case 4:
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          if (mat[i][j].entidade == 'W' && ok == 0) {
            if (j + 1 != 8 && mat[i][j+1].entidade != 'P' && mat[i][j+1].entidade != 'O') { // Testa a borda do mapa
              if (mat[i][j+1].entidade == 'F') {
                printf("O Wumpus destroiu uma flecha!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j+1].entidade = 'W';
                ok = 1;
                break;
              } else if (mat[i][j+1].entidade == 'A'){
                printf("O Wumpus matou o agente!\n");
                situacao = 1;
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j+1].entidade = 'W';
                ok = 1;
              }else {
                printf("O Wumpus se moveu!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j+1].entidade = 'W';
                ok = 1;
                break;
              }
            } else {
              bool=0;
              break;
            }
          }
        }
      }
      break;
    }
  } while (bool != 1);
  sleep(1);
  return situacao;
}
int atirarFlecha(Square mat[][8],int *flecha,int *debug){
  int i, j, ok,morte_monstro=0;
  char direcao;
  if ((*flecha) > 0){
    do{
      ok=1;
      fflush(stdin);
      printf("w - cima\n");
      printf("a - esquerda\n");
      printf("s - baixo\n");
      printf("d - direita\n");
      printf("Para onde deseja atirar sua flecha:\n");
      scanf("%c", &direcao);
      switch (direcao) {
      case 'w':
        for (i = 0; i < 8; i++) {
          for (j = 0; j < 8; j++) {
            if (mat[i][j].entidade == 'A') {
              if (i - 1 != -1) { // Testa a borda do mapa
                if(mat[i-1][j].entidade == 'W'){
                  mat[i-1][j].entidade = 'X';
                  mat[i-1][j].display = 'X';
                  printf("O Wumpus morreu!\n");
                  morte_monstro++;
                }else {
                  printf("A flecha acertou o nada.\n");
                }
              } else {
                printf("Desperdicou a flecha!\n");
                break;
              }
              *flecha -= 1;
            }
          }
        }
        break;
      case 'a':
        for (i = 0; i < 8; i++) {
          for (j = 0; j < 8; j++) {
            if (mat[i][j].entidade == 'A') {
              if (j - 1 != -1) { // Testa a borda do mapa
                if(mat[i][j-1].entidade == 'W'){
                  mat[i][j-1].entidade = 'X';
                  mat[i][j-1].display = 'X';
                  printf("O Wumpus morreu!\n");
                  morte_monstro++;
                }else {
                  printf("A flecha acertou o nada.\n");
                }
              } else {
                printf("Desperdicou a flecha!\n");
                break;
              }
              *flecha -= 1;
            }
          }
        }
        break;
      case 's':
        for (i = 0; i < 8; i++) {
          for (j = 0; j < 8; j++) {
            if (mat[i][j].entidade == 'A') {
              if (i + 1 != 8) { // Testa a borda do mapa
                if(mat[i+1][j].entidade == 'W'){
                  mat[i+1][j].entidade = 'X';
                  mat[i+1][j].display = 'X';
                  printf("O Wumpus morreu!\n");
                  morte_monstro++;
                }else {
                  printf("A flecha acertou o nada.\n");
                }
              } else {
                printf("Desperdicou a flecha!\n");
                break;
              }
              *flecha -= 1;
            }
          }
        }
        break;
      case 'd':
        for (i = 0; i < 8; i++) {
          for (j = 0; j < 8; j++) {
            if (mat[i][j].entidade == 'A') {
              if (j + 1 != 8) { // Testa a borda do mapa
                if(mat[i][j+1].entidade == 'W'){
                  mat[i][j+1].entidade = 'X';
                  mat[i][j+1].display = 'X';
                  printf("O Wumpus morreu!\n");
                  morte_monstro++;
                }else {
                  printf("A flecha acertou o nada.\n");
                }
              } else {
                printf("Desperdicou a flecha!\n");
                break;
              }
              *flecha -= 1;
            }
          }
        }
        break;
      default:
        printf("direcao invalida.\n");
        ok=0;
        system("cls");
        printMatriz(mat,*debug);
        break;
      }
    }while (ok != 1);
  }else {
    printf("Voce nao tem mais flechas!!!\n");
    sleep(2);
  }
  sleep(1);
  return morte_monstro;
}
void testa_dica (Square mat[][8],int *debug){
  int i,j,bool=1,verificador=0;
  char direcao;
  do{
    bool=1;
    printf("Qual direcao voce deseja saber?\n");
    printf("w - cima\n");
    printf("a - esquerda\n");
    printf("s - baixo\n");
    printf("d - direita\n");
    scanf("%c",&direcao);
    switch (direcao){
    case 'w':
      for(i=0;i<8;i++){
        for(j=0;j<8;j++){
          if((mat[i][j].entidade=='A')&&(mat[i-1][j].entidade=='W')){
            verificador=1;
          }
        }
      }
      break;
    case 's':
      for(i=0;i<8;i++){
        for(j=0;j<8;j++){
          if((mat[i][j].entidade=='A')&&(mat[i+1][j].entidade=='W')){
            verificador=1;
          }
        }
     }
      break;
    case 'a':
      for(i=0;i<8;i++){
        for(j=0;j<8;j++){
          if((mat[i][j].entidade=='A')&&(mat[i][j-1].entidade=='W')){
            verificador=1;
          }
        }
      }
      break;
    case 'd':
      for(i=0;i<8;i++){
        for(j=0;j<8;j++){
          if((mat[i][j].entidade=='A')&&(mat[i][j+1].entidade=='W')){
            verificador=1;
          }
        }
      }
      break;
    default:
      fflush(stdin);
      printf("==================\n");
      printf("Opcao invalida!!!\n");
      printf("==================\n");
      sleep(2);
      system("cls");
      printMatriz(mat,*debug);
      bool=0;
      break;
    }
  }while(bool!=1);
  if(verificador==1){
    printf("O monstro esta nesta direcao\n");
  }else{
    printf("O montro nao esta nesta direcao\n");
  }
  sleep(2);
}
void copiar_matriz(Square mat[][8],Square matcopy[][8]){
  int i,j;
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      matcopy[i][j]=mat[i][j];
    }
  }
}
void recopiar_matriz(Square mat[][8],Square matcopy[][8]){
  int i,j;
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      mat[i][j]=matcopy[i][j];
    }
  }
}
void Salvar_Jogo(char nome_jogador[], int pontos){
  FILE *Lista_Jogadores;
  Lista_Jogadores=fopen("Lista_Jogadores.txt","a");
  if(Lista_Jogadores==NULL){
    printf("Arquivo nao encontrado\n");
    printf("Crie um arquivo chamado: Lista_Jogadores.txt");
    exit(0);
  }
  fprintf(Lista_Jogadores,"Apelido: %s // Pontuacao: %d \n",nome_jogador,pontos);
  fclose(Lista_Jogadores);
}
void testarSentido(Square mat[][8]){
  int i,j,brisa=0,fedor=0;
  for (i=0;i<8;i++){
    for (j=0;j<8;j++){
      if (mat[i][j].entidade == 'A'){
        if (i-1 != -1) { // Testa a borda do mapa{
          if (mat[i-1][j].entidade == 'P'){
            brisa = 1;
          }else if (mat[i-1][j].entidade == 'W'){
            fedor = 1;
          }
        }
        if (j-1 != -1) { // Testa a borda do mapa{
          if (mat[i][j-1].entidade == 'P'){
            brisa = 1;
          }else if (mat[i][j-1].entidade == 'W'){
            fedor = 1;
          }
        } 
        if (i+1 != 8) { // Testa a borda do mapa{
          if (mat[i+1][j].entidade == 'P'){
            brisa = 1;
          }else if (mat[i+1][j].entidade == 'W'){
            fedor = 1;
          }
        }
        if (j+1 != 8) { // Testa a borda do mapa{
          if (mat[i][j+1].entidade == 'P'){
            brisa = 1;
          }else if (mat[i][j+1].entidade == 'W'){
            fedor = 1;
          }
        } 
      }
    }
  }
  if (brisa == 1){
    printf ("O agente sentiu uma brisa.\n");
  }
  if (fedor == 1){
    printf ("O agente sentiu um fedor.\n");
  }
  printf ("\n");
}