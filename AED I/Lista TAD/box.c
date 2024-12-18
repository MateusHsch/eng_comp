#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct box{
    float l,h,w;
};
typedef struct box Box;
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