typedef struct box Box;
/* Aloca e retorna uma caixa com lados (l,h,w) */
Box* box_create(float l,float h,float w);
/* Libera a memória de uma caixa previamente criada */
void box_destroy(Box* b);
/* Retorna os valores dos lados da caixa */
void box_get(Box* b,float* l,float* h,float* w);
/* Atribui novos valores aos lados da caixa */
void box_set(Box* b,float l,float h,float w);
/* Retorna a área da caixa */
float box_area(Box* b);
/* Retorna o volume da caixa */
float box_volume(Box* b);
/* Pega as informações dacaixa e imprime na tela */
void box_printinfo(Box* b);