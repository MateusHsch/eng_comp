typedef struct point Point;
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