#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "bib.h"

int main() {
  srand(time(NULL));
  int i,j,debug = 0, situacao,op,ouro=0,flecha=1,dica_utilizada=0,escolha=2,morte_monstro=0,movimentos=0,pontos=100;
  char nome_jogador[10],leitor[1000];
  Square mat[8][8], matcopy[8][8];
  FILE *Lista_Jogadores;
  do {
    movimentos=0;
    flecha=1;
    dica_utilizada=0;
    ouro=0;
    morte_monstro=0;
    pontos=100;
    op = menuInicial(); // Menu inicial do jogo
    switch (op) {
    case 1: // Jogar
      if(escolha==1){
        recopiar_matriz(mat,matcopy);
      }else{
        if(escolha==2){
          gerarMatriz(mat);
          copiar_matriz(mat,matcopy);
        }
      }
      do {
        situacao=0;
        system("cls");
        printMatriz(mat, debug);
        printf("Voce possui %d flechas\n",flecha);
        printf("Voce possui %d ouros\n",ouro);
        testarSentido(mat);
        op = menuJogar(); // Menu dentro do jogo
        switch (op){
        case 1: // Mover agente
          system("cls");
          printMatriz(mat, debug);
          situacao = moverAgente(mat,&debug,&movimentos);
          if (situacao == 0){
            situacao = moverMonstro(mat);
          }
          break;
        case 2: // Atirar flecha
          system("cls");
          printMatriz(mat, debug);
          morte_monstro=atirarFlecha(mat,&flecha,&debug);
          situacao = moverMonstro(mat);
          break;
        case 3: // Usar dica
          if(dica_utilizada==0){
            testa_dica(mat,&debug);
            dica_utilizada++;
          }else{
            printf("Voce ja utilizou a dica");
            sleep (1);
          }        
          break;
        case 4: // sair
          if(morte_monstro==1){
            pontos=pontos-movimentos+50-20;
            printf("Voce comecou com 100 pontos\n");
            printf("Voce perdeu 1 ponto por movimento, perdendo %d pontos\n",movimentos);
            printf("Voce ganhou 50 pontos por matar o monstro\n");
            printf("Voce perdeu 20 pontos por parar de jogar\n");
            printf("Sua pontuacao: %d\n",pontos);
          }else{
            pontos=pontos-movimentos-50-20;
            printf("Voce comecou com 100 pontos\n");
            printf("Voce perdeu 1 ponto por movimento, perdendo %d pontos\n",movimentos);
            printf("Voce perdeu 50 pontos por nao matar o monstro\n");
            printf("Voce perdeu 20 pontos por parar de jogar\n");
            printf("Sua pontuacao: %d\n",pontos);
          }
          printf("Digite o seu apelido ");
          scanf("%s",nome_jogador);
          Salvar_Jogo(nome_jogador,pontos);
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
        if (situacao == 3){
          flecha++;
        }else if (situacao == 2){
          ouro++;
        }
        // aqui
        if ((mat[7][0].entidade == 'A') && (ouro == 1)){
          situacao = 4;
        }
      } while ((situacao != 1) && (situacao != 4));
      break;
    case 2: // Debug
      if(debug == 0){
        debug = 1;
      } else if (debug == 1){
        debug = 0;
      }
      break;
    case 3: // Lista de Jogadores
      Lista_Jogadores=fopen("Lista_Jogadores.txt","r");
      while(fgets(leitor,1000,Lista_Jogadores)!= NULL){
        printf("%s",leitor);
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
    if (situacao == 4){
      system("cls");
      printMatriz(mat,debug);
      printf("=====================\n");
      printf("Voce ganhou o jogo!!!\n");
      printf("=====================\n\n");
      printf("Placar:\n");
      printf("Voce comecou com 100 pontos\n");
      printf("Voce perdeu 1 ponto por movimento, perdendo um total de %d pontos\n",movimentos);
      if(morte_monstro==1){
        printf("Voce ganhou 10 pontos por matar o monstro\n");
        pontos=pontos-movimentos+10;
        printf("Pontuacao: %d\n",pontos);
      }else{
        printf("Voce perdeu 10 pontos por nao matar o monstro\n");
        pontos=pontos-movimentos-10;
        printf("Pontuacao: %d\n",pontos);
      }
      printf("Digite o seu apelido ");
      scanf("%s",nome_jogador);
      Salvar_Jogo(nome_jogador,pontos);
      do{
        printf("Digite 1 para reiniciar a fase\n");
        printf("Digite 2 para jogar um novo jogo\n");
        printf("Digite 3 para encerrar\n");
        scanf("%d",&escolha);
      }while((escolha<1)||(escolha>3));
      
    }else if (situacao == 1){
      system("cls");
      for (i=0;i<8;i++){
        for (j=0;j<8;j++){
          if (mat[i][j].entidade == 'A'){
            mat[i][j].entidade ='X';
          }
        }
      }
      printMatriz(mat,debug);
      printf("===============\n");
      printf("Voce morreu!!!\n");
      printf("===============\n");
      printf("Placar:\n");
      printf("Voce comecou com 100 pontos\n");
      printf("Voce perdeu 1 ponto por movimento, perdendo um total de %d pontos\n",movimentos);
      printf("Voce perdeu 50 pontos por morrer\n");
      if(morte_monstro==1){
        printf("Voce ganhou 10 pontos por matar o monstro\n");
        pontos=pontos-movimentos+10-50;
        printf("Pontuacao: %d\n",pontos);
      }else{
        printf("Voce perdeu 10 pontos por nao matar o monstro\n");
        pontos=pontos-movimentos-10-50;
        printf("Pontuacao: %d\n",pontos);
      }
      printf("Digite o seu apelido ");
      scanf("%s",nome_jogador);
      Salvar_Jogo(nome_jogador,pontos);
      do{
        printf("Digite 1 para reiniciar a fase\n");
        printf("Digite 2 para jogar um novo jogo\n");
        printf("Digite 3 para encerrar\n");
        scanf("%d",&escolha);
        getchar();
      }while((escolha<1)||(escolha>3));
    }
  } while (escolha!=3);
  return 0;
}