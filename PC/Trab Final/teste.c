#include "bib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int menuInicial();
int menuJogar();
void gerarMatriz(Square mat[][8]);
void copiar_matriz(Square mat[][8], Square matcopy[][8]);
void recopiar_matriz(Square mat[][8], Square matcopy[][8]);
void printMatriz(Square mat[][8], int debug);
int moverAgente(Square mat[][8], int *debug, int *movimentos);
int moverMonstro(Square mat[][8]);
int atirarFlecha(Square mat[][8], int *flecha, int *debug);
void testa_dica(Square mat[][8], int *debug);
void Salvar_Jogo(char nome_jogador[], int pontos);
void testarSentido(Square mat[][8]);

int main() {
  srand(time(NULL));
  int i, j, debug = 0, situacao, op, ouro = 0, flecha = 1, dica_utilizada = 0,
            escolha = 2, morte_monstro = 0, movimentos = 0, pontos = 100;
  char nome_jogador[10], leitor[1000];
  Square mat[8][8], matcopy[8][8];
  FILE *Lista_Jogadores;
  do {
    movimentos = 0;
    flecha = 1;
    dica_utilizada = 0;
    ouro = 0;
    morte_monstro = 0;
    pontos = 100;
    op = menuInicial(); // Menu inicial do jogo
    switch (op) {
    case 1: // Jogar
      if (escolha == 1) {
        recopiar_matriz(mat, matcopy);
      } else {
        if (escolha == 2) {
          gerarMatriz(mat);
          copiar_matriz(mat, matcopy);
        }
      }
      do {
        situacao = 0;
        system("cls");
        printMatriz(mat, debug);
        printf("Voce possui %d flechas\n", flecha);
        printf("Voce possui %d ouros\n", ouro);
        testarSentido(mat);
        op = menuJogar(); // Menu dentro do jogo
        switch (op) {
        case 1: // Mover agente
          system("cls");
          printMatriz(mat, debug);
          situacao = moverAgente(mat, &debug, &movimentos);
          if (situacao == 0) {
            situacao = moverMonstro(mat);
          }
          break;
        case 2: // Atirar flecha
          system("cls");
          printMatriz(mat, debug);
          morte_monstro = atirarFlecha(mat, &flecha, &debug);
          situacao = moverMonstro(mat);
          break;
        case 3: // Usar dica
          if (dica_utilizada == 0) {
            testa_dica(mat, &debug);
            dica_utilizada++;
          } else {
            printf("Voce ja utilizou a dica");
            sleep(1);
          }
          break;
        case 4: // sair
          if (morte_monstro == 1) {
            pontos = pontos - movimentos + 50 - 20;
            printf("Voce comecou com 100 pontos\n");
            printf("Voce perdeu 1 ponto por movimento, perdendo %d pontos\n",
                   movimentos);
            printf("Voce ganhou 50 pontos por matar o monstro\n");
            printf("Voce perdeu 20 pontos por parar de jogar\n");
            printf("Sua pontuacao: %d\n", pontos);
          } else {
            pontos = pontos - movimentos - 50 - 20;
            printf("Voce comecou com 100 pontos\n");
            printf("Voce perdeu 1 ponto por movimento, perdendo %d pontos\n",
                   movimentos);
            printf("Voce perdeu 50 pontos por nao matar o monstro\n");
            printf("Voce perdeu 20 pontos por parar de jogar\n");
            printf("Sua pontuacao: %d\n", pontos);
          }
          printf("Digite o seu apelido ");
          scanf("%s", nome_jogador);
          Salvar_Jogo(nome_jogador, pontos);
          exit(0);
          break;
        default:
          printf("==================\n");
          printf("Opcao invalida!!!\n");
          printf("==================\n");
          sleep(2);
          system("cls");
          break;
        }
        if (situacao == 3) {
          flecha++;
        } else if (situacao == 2) {
          ouro++;
        }
        // aqui
        if ((mat[7][0].entidade == 'A') && (ouro == 1)) {
          situacao = 4;
        }
      } while ((situacao != 1) && (situacao != 4));
      break;
    case 2: // Debug
      if (debug == 0) {
        debug = 1;
      } else if (debug == 1) {
        debug = 0;
      }
      break;
    case 3: // Lista de Jogadores
      Lista_Jogadores = fopen("Lista_Jogadores.txt", "r");
      while (fgets(leitor, 1000, Lista_Jogadores) != NULL) {
        printf("%s", leitor);
      }
      printf("\n");
      fclose(Lista_Jogadores);
      break;
    case 4: // Sair
      exit(0);
      break;
    default:
      break;
    }
    getchar();
    if (situacao == 4) {
      system("cls");
      printMatriz(mat, debug);
      printf("=====================\n");
      printf("Voce ganhou o jogo!!!\n");
      printf("=====================\n\n");
      printf("Placar:\n");
      printf("Voce comecou com 100 pontos\n");
      printf(
          "Voce perdeu 1 ponto por movimento, perdendo um total de %d pontos\n",
          movimentos);
      if (morte_monstro == 1) {
        printf("Voce ganhou 10 pontos por matar o monstro\n");
        pontos = pontos - movimentos + 10;
        printf("Pontuacao: %d\n", pontos);
      } else {
        printf("Voce perdeu 10 pontos por nao matar o monstro\n");
        pontos = pontos - movimentos - 10;
        printf("Pontuacao: %d\n", pontos);
      }
      printf("Digite o seu apelido ");
      scanf("%s", nome_jogador);
      Salvar_Jogo(nome_jogador, pontos);
      do {
        printf("Digite 1 para reiniciar a fase\n");
        printf("Digite 2 para jogar um novo jogo\n");
        printf("Digite 3 para encerrar\n");
        scanf("%d", &escolha);
      } while ((escolha < 1) || (escolha > 3));

    } else if (situacao == 1) {
      system("cls");
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          if (mat[i][j].entidade == 'A') {
            mat[i][j].entidade = 'X';
          }
        }
      }
      printMatriz(mat, debug);
      printf("===============\n");
      printf("Voce morreu!!!\n");
      printf("===============\n");
      printf("Placar:\n");
      printf("Voce comecou com 100 pontos\n");
      printf(
          "Voce perdeu 1 ponto por movimento, perdendo um total de %d pontos\n",
          movimentos);
      printf("Voce perdeu 50 pontos por morrer\n");
      if (morte_monstro == 1) {
        printf("Voce ganhou 10 pontos por matar o monstro\n");
        pontos = pontos - movimentos + 10 - 50;
        printf("Pontuacao: %d\n", pontos);
      } else {
        printf("Voce perdeu 10 pontos por nao matar o monstro\n");
        pontos = pontos - movimentos - 10 - 50;
        printf("Pontuacao: %d\n", pontos);
      }
      printf("Digite o seu apelido ");
      scanf("%s", nome_jogador);
      Salvar_Jogo(nome_jogador, pontos);
      do {
        printf("Digite 1 para reiniciar a fase\n");
        printf("Digite 2 para jogar um novo jogo\n");
        printf("Digite 3 para encerrar\n");
        scanf("%d", &escolha);
        getchar();
      } while ((escolha < 1) || (escolha > 3));
    }
  } while (escolha != 3);
  return 0;
}

int menuInicial() {
  int op = 0, bool = 0;
  printf("Ola jogador! Boas vindas ao Mundo de Wumpus!\n");
  do {
    printf("1 - Jogar.\n");
    printf("2 - Debug.\n");
    printf("3 - Lista de jogadores.\n");
    printf("4 - Sair.\n");
    printf("Insira a opcao do menu que deseja:\n");
    scanf("%d", &op);
    if (op >= 1 && op <= 4) {
      bool = 1;
    } else {
      printf("==================\n");
      printf("Opcao invalida!!!\n");
      printf("==================\n");
      sleep(2);
      system("cls");
    }
  } while (bool != 1);
  return (op);
}
int menuJogar() {
  int op, bool;
  do {
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
  } while (bool != 1);

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
int moverAgente(Square mat[][8], int *debug, int *movimentos) {
  int i, j, situacao = 0, ok = 0, bool;
  char move;
  *movimentos += 1;
  do {
    bool = 1;
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
      bool = 0;
      system("cls");
      printMatriz(mat, *debug);
      break;
    }
  } while (bool != 1);
  sleep(1);
  return situacao;
}
int moverMonstro(Square mat[][8]) {
  int i, j, move, situacao = 0, ok = 0, bool;
  do {
    bool = 1;
    move = rand() % 4 + 1;
    switch (move) {
    case 1:
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          if (mat[i][j].entidade == 'W' && ok == 0) {
            if (i - 1 != -1 && mat[i - 1][j].entidade != 'P' &&
                mat[i - 1][j].entidade != 'O') { // Testa a borda do mapa
              if (mat[i - 1][j].entidade == 'F') {
                printf("O Wumpus destroiu uma flecha!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i - 1][j].entidade = 'W';
                ok = 1;
                break;
              } else if (mat[i - 1][j].entidade == 'A') {
                printf("O Wumpus matou o agente!\n");
                situacao = 1;
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i - 1][j].entidade = 'W';
                ok = 1;
              } else {
                printf("O Wumpus se moveu!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i - 1][j].entidade = 'W';
                ok = 1;
                break;
              }
            } else {
              bool = 0;
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
            if (j - 1 != -1 && mat[i][j - 1].entidade != 'P' &&
                mat[i][j - 1].entidade != 'O') { // Testa a borda do mapa
              if (mat[i][j - 1].entidade == 'F') {
                printf("O Wumpus destroiu uma flecha!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j - 1].entidade = 'W';
                ok = 1;
                break;
              } else if (mat[i][j - 1].entidade == 'A') {
                printf("O Wumpus matou o agente!\n");
                situacao = 1;
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j - 1].entidade = 'W';
                ok = 1;
              } else {
                printf("O Wumpus se moveu!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j - 1].entidade = 'W';
                ok = 1;
                break;
              }
            } else {
              bool = 0;
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
            if (i + 1 != 8 && mat[i + 1][j].entidade != 'P' &&
                mat[i + 1][j].entidade != 'O') { // Testa a borda do mapa
              if (mat[i + 1][j].entidade == 'F') {
                printf("O Wumpus destroiu uma flecha!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i + 1][j].entidade = 'W';
                ok = 1;
                break;
              } else if (mat[i + 1][j].entidade == 'A') {
                printf("O Wumpus matou o agente!\n");
                situacao = 1;
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i + 1][j].entidade = 'W';
                ok = 1;
              } else {
                printf("O Wumpus se moveu!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i + 1][j].entidade = 'W';
                ok = 1;
                break;
              }
            } else {
              bool = 0;
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
            if (j + 1 != 8 && mat[i][j + 1].entidade != 'P' &&
                mat[i][j + 1].entidade != 'O') { // Testa a borda do mapa
              if (mat[i][j + 1].entidade == 'F') {
                printf("O Wumpus destroiu uma flecha!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j + 1].entidade = 'W';
                ok = 1;
                break;
              } else if (mat[i][j + 1].entidade == 'A') {
                printf("O Wumpus matou o agente!\n");
                situacao = 1;
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j + 1].entidade = 'W';
                ok = 1;
              } else {
                printf("O Wumpus se moveu!\n");
                mat[i][j].entidade = 'X';
                mat[i][j].display = 'X';
                mat[i][j + 1].entidade = 'W';
                ok = 1;
                break;
              }
            } else {
              bool = 0;
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
int atirarFlecha(Square mat[][8], int *flecha, int *debug) {
  int i, j, ok, morte_monstro = 0;
  char direcao;
  if ((*flecha) > 0) {
    do {
      ok = 1;
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
                if (mat[i - 1][j].entidade == 'W') {
                  mat[i - 1][j].entidade = 'X';
                  mat[i - 1][j].display = 'X';
                  printf("O Wumpus morreu!\n");
                  morte_monstro++;
                } else {
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
                if (mat[i][j - 1].entidade == 'W') {
                  mat[i][j - 1].entidade = 'X';
                  mat[i][j - 1].display = 'X';
                  printf("O Wumpus morreu!\n");
                  morte_monstro++;
                } else {
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
                if (mat[i + 1][j].entidade == 'W') {
                  mat[i + 1][j].entidade = 'X';
                  mat[i + 1][j].display = 'X';
                  printf("O Wumpus morreu!\n");
                  morte_monstro++;
                } else {
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
                if (mat[i][j + 1].entidade == 'W') {
                  mat[i][j + 1].entidade = 'X';
                  mat[i][j + 1].display = 'X';
                  printf("O Wumpus morreu!\n");
                  morte_monstro++;
                } else {
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
        ok = 0;
        system("cls");
        printMatriz(mat, *debug);
        break;
      }
    } while (ok != 1);
  } else {
    printf("Voce nao tem mais flechas!!!\n");
    sleep(2);
  }
  sleep(1);
  return morte_monstro;
}
void testa_dica(Square mat[][8], int *debug) {
  int i, j, bool = 1, verificador = 0;
  char direcao;
  do {
    bool = 1;
    printf("Qual direcao voce deseja saber?\n");
    printf("w - cima\n");
    printf("a - esquerda\n");
    printf("s - baixo\n");
    printf("d - direita\n");
    scanf("%c", &direcao);
    switch (direcao) {
    case 'w':
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          if ((mat[i][j].entidade == 'A') && (mat[i - 1][j].entidade == 'W')) {
            verificador = 1;
          }
        }
      }
      break;
    case 's':
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          if ((mat[i][j].entidade == 'A') && (mat[i + 1][j].entidade == 'W')) {
            verificador = 1;
          }
        }
      }
      break;
    case 'a':
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          if ((mat[i][j].entidade == 'A') && (mat[i][j - 1].entidade == 'W')) {
            verificador = 1;
          }
        }
      }
      break;
    case 'd':
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          if ((mat[i][j].entidade == 'A') && (mat[i][j + 1].entidade == 'W')) {
            verificador = 1;
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
      printMatriz(mat, *debug);
      bool = 0;
      break;
    }
  } while (bool != 1);
  if (verificador == 1) {
    printf("O monstro esta nesta direcao\n");
  } else {
    printf("O montro nao esta nesta direcao\n");
  }
  sleep(2);
}
void copiar_matriz(Square mat[][8], Square matcopy[][8]) {
  int i, j;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      matcopy[i][j] = mat[i][j];
    }
  }
}
void recopiar_matriz(Square mat[][8], Square matcopy[][8]) {
  int i, j;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      mat[i][j] = matcopy[i][j];
    }
  }
}
void Salvar_Jogo(char nome_jogador[], int pontos) {
  FILE *Lista_Jogadores;
  Lista_Jogadores = fopen("Lista_Jogadores.txt", "a");
  if (Lista_Jogadores == NULL) {
    printf("Arquivo nao encontrado\n");
    printf("Crie um arquivo chamado: Lista_Jogadores.txt");
    exit(0);
  }
  fprintf(Lista_Jogadores, "Apelido: %s // Pontuacao: %d \n", nome_jogador,
          pontos);
  fclose(Lista_Jogadores);
}
void testarSentido(Square mat[][8]) {
  int i, j, brisa = 0, fedor = 0;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (mat[i][j].entidade == 'A') {
        if (i - 1 != -1) { // Testa a borda do mapa{
          if (mat[i - 1][j].entidade == 'P') {
            brisa = 1;
          } else if (mat[i - 1][j].entidade == 'W') {
            fedor = 1;
          }
        }
        if (j - 1 != -1) { // Testa a borda do mapa{
          if (mat[i][j - 1].entidade == 'P') {
            brisa = 1;
          } else if (mat[i][j - 1].entidade == 'W') {
            fedor = 1;
          }
        }
        if (i + 1 != 8) { // Testa a borda do mapa{
          if (mat[i + 1][j].entidade == 'P') {
            brisa = 1;
          } else if (mat[i + 1][j].entidade == 'W') {
            fedor = 1;
          }
        }
        if (j + 1 != 8) { // Testa a borda do mapa{
          if (mat[i][j + 1].entidade == 'P') {
            brisa = 1;
          } else if (mat[i][j + 1].entidade == 'W') {
            fedor = 1;
          }
        }
      }
    }
  }
  if (brisa == 1) {
    printf("O agente sentiu uma brisa.\n");
  }
  if (fedor == 1) {
    printf("O agente sentiu um fedor.\n");
  }
  printf("\n");
}