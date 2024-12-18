/*
Desenvolva um TAD que represente um cubo. Inclua as funções de inicializações necessárias e as
operações que retornem os tamanhos de cada lado, a sua área e o seu volume.
(Porém feito para uma caixa genérica e usando o TAD de ponto)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* ----------< struct point.c >---------- */
struct point{
    int x,y,z;
};
typedef struct point Point;
/* ----------< struct box.c >----------- */
struct box{
    float l,h,w;
};
typedef struct box Box;
/* ----------< point.h >---------- */
/* Aloca e retorna um ponto com coordenadas (x,y) */
Point* point_create(float x, float y, float z);
/* Libera a memória de um ponto previamente criado */
void point_destroy(Point* p);
/* Retorna os valores das coordenadas de um ponto */
void point_get(Point* p, float* x, float* y, float* z);
/* Atribui novos valores às coordenadas de um ponto */
void point_set(Point* p, float x, float y, float z);
/* Retorna a distância entre dois pontos */
float point_distance(Point* p1, Point* p2);
/* ----------< box.h >------------ */
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
/* ----------< main.c >----------- */
int main(){
    Point* p1 = point_create(0,0,0);
    Point* p2 = point_create(3,0,0);
    Point* p3 = point_create(0,3,0);
    Point* p4 = point_create(0,0,3);
    float l = point_distance(p1,p2);
    float h = point_distance(p1,p3);
    float w = point_distance(p1,p4);
    Box* b = box_create(l,h,w);
    box_printinfo(b);
    point_destroy(p1);
    point_destroy(p2);
    point_destroy(p3);
    point_destroy(p4);
    box_destroy(b);
    return 0;
}
/* ----------< point.c >---------- */
Point* point_create(float x,float y,float z){
    Point* p = (Point*) malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    p->z = z;
    return p;
}
void point_destroy(Point* p){
    free(p);
}
void point_get(Point* p,float* x,float* y, float* z){
    *x = p->x;
    *y = p->y;
    *z = p->z;
}
void point_set(Point* p,float x,float y, float z){
    p->x = x;
    p->y = y;
    p->z = z;
}
float point_distance(Point* p1, Point* p2){
    float distance = sqrt(pow(p2->x - p1->x,2)+pow(p2->y - p1->y,2)+pow(p2->z - p1->z,2));
    return distance;
}
/* ----------< box.c >------------ */
Box* box_create(float l,float h,float w){
    Box* b = (Box*) malloc(sizeof(Box));
    b->l = l;
    b->h = h;
    b->w = w;
    return b;
}
void box_destroy(Box* b){
    free(b);
}
void box_get(Box* b,float* l,float* h,float* w){
    *l = b->l;
    *h = b->h;
    *w = b->w;
}
void box_set(Box* b,float l,float h,float w){
    b->l = l;
    b->h = h;
    b->w = w;
}
float box_area(Box* b){
    float area = 2*(b->l*b->h) + 2*(b->h*b->w) + 2*(b->w*b->l);
    return area;
}
float box_volume(Box* b){
    float volume = b->l*b->h*b->w;
    return volume;
}
void box_printinfo(Box* b){
    float area,volume;
    area = box_area(b);
    volume = box_volume(b);
    printf("lados da caixa.\n");
    printf("comprimento: %.2f\n",b->l);
    printf("altura: %.2f\n",b->h);
    printf("largura: %.2f\n\n",b->w);
    printf("area da caixa: %.2f\n",area);
    printf("volume da caixa: %.2f\n",volume);
}
/* ------------------------------- */