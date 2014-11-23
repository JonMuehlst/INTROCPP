#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#define MAX_ARR_SIZE 10

size_t getArrayFromInput(int*,size_t);
void printArr(int*,size_t,size_t);
size_t findSmallestIndex(int*,size_t,size_t);
void swap(int*,size_t,size_t);
void sort(int*,size_t);

#endif