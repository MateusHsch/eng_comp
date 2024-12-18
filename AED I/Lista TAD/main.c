#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "box.h"
int main(){
    Point* p1 = point_create(0,0,0);
    Point* p2 = point_create(3,0,0);
    Point* p3 = point_create(0,3,0);
    Point* p4 = point_create(0,0,3);
    float l = point_distance(p1,p2);
    float h = point_distance(p1,p3);
    float w = point_distance(p1,p4);
    float area, volume;
    Box* b = box_create(l,h,w);
    box_printinfo(b);
    point_destroy(p1);
    point_destroy(p2);
    point_destroy(p3);
    point_destroy(p4);
    box_destroy(b);
    getchar();
    return 0;
}