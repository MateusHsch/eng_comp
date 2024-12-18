/*
Desenvolva um TAD que represente um cilindro. Inclua as funções de inicializações necessárias e as
operações que retornem a sua altura e o raio, a sua área e o seu volume.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* ----------< struct ponto >---------- */
struct point{
    int x,y,z;
};
typedef struct point Point;
/* ----------< struct cilindro >----------- */
struct cylinder{
    float radius,height;
};
typedef struct cylinder Cylinder;
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
/* ----------< cylinder.h >------------ */
/* Aloca e retorna um cilindro com raio e altura (r,h) */
Cylinder* cylinder_create(float r,float h);
/* Libera a memória de um cilindro previamente criado */
void cylinder_destroy(Cylinder* c);
/* Retorna os valores do raio e altura do cilindro */
void cylinder_get(Cylinder* c, float* r, float* h);
/* Atribui novos valores ao raio e altura do cilindro */
void cylinder_set(Cylinder* c, float r, float h);
/* Retorna a área do cilindro */
float cylinder_area(Cylinder* c);
/* Retorna o volume do cilindro */
float cylinder_volume(Cylinder* c);
/* ----------< main.c >----------- */
int main(){
    Point* p1 = point_create(0,0,0);
    Point* p2 = point_create(2,0,0);
    Point* p3 = point_create(0,0,5);
    Cylinder* c = cylinder_create(0,0);
    float r = point_distance(p1,p2);
    float h = point_distance(p1,p3);
    cylinder_set(c,r,h);
    float area = cylinder_area(c);
    float volume = cylinder_volume(c);
    printf("raio do cilindro: %.2f\n",c->radius);
    printf("altura do cilindro: %.2f\n\n",c->height);
    printf("area do cilindro: %.2f\n",area);
    printf("volume do cilindro: %.2f\n",volume);
    point_destroy(p1);
    point_destroy(p2);
    point_destroy(p3);
    cylinder_destroy(c);
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
/* ----------< cylinder.c >------------ */
Cylinder* cylinder_create(float r,float h){
    Cylinder* c = (Cylinder*) malloc(sizeof(Cylinder));
    c->radius = r;
    c->height = h;
    return c;
}
void cylinder_destroy(Cylinder* c){
    free(c);
}
void cylinder_get(Cylinder* c, float* r, float* h){
    *r = c->radius;
    *h = c->height;
}
void cylinder_set(Cylinder* c, float r, float h){
    c->radius = r;
    c->height = h;
}
float cylinder_area(Cylinder* c){
    float area = (2*(3.1415*pow(c->radius,2)) + c->height*(2*3.1415*c->radius));
    return area;
}
float cylinder_volume(Cylinder* c){
    float volume = ((3.1415*pow(c->radius,2)) * c->height);
    return volume;
}
/* ------------------------------- */