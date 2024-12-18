#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct point{
    int x,y,z;
};
typedef struct point Point;
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
