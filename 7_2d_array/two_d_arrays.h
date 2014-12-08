#ifndef TWO_D_ARRAYS_H
#define TWO_D_ARRAYS_H

int ** initMatrix(size_t,size_t);
void deleteMatrix(int**,size_t,size_t);

int sumFlowers(int ** a,size_t,size_t);
int isFlower( int ** a,size_t,size_t);

void multiplyMatrix(int ** ,int ** ,int **,size_t);

void printArr(int ** arr, size_t rows, size_t cols);

#endif