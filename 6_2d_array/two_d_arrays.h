/*
        
        void printCenterOfMass();
        int printIsSumPossible();
    
        are taken from the following presentation:
        http://webcourse.cs.technion.ac.il/234114/Winter2014-2015/ho/WCFiles/Tutorial5.pdf
    
    
*/

#ifndef TWO_D_ARRAYS_H
#define TWO_D_ARRAYS_H

const int N = 10;
const int ARR_COLS = 4;

void centerOfMass(double points[N][3], double centerOfMass[3]);
bool isSumPossible(int a[],int,int,int);
int sumSecDiagonal(int arr[][ARR_COLS]);
void printArr(int arr[][ARR_COLS],size_t,size_t);
void printArr(int ** arr, size_t rows, size_t cols);
bool isMatSymmetric(int arr[][ARR_COLS],size_t,size_t);
void transposeMat(int ** arr,size_t,size_t);
void transposeMat(int arr[][ARR_COLS],size_t,size_t);
void swap(int&,int&);

#endif