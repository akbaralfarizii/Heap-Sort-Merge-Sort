#ifndef heapsort_H
#define heapsort_H


void HeapSortMin (int data[], int panjangArray);

void HeapSortMax (int data[], int panjangArray);

void BuildMinHeapify (int data[], int panjangArray);

void BuildMaxHeapify (int data[], int panjangArray);

void MinHeapify (int data[], int heapSize, int index, int panjangArray);

void MaxHeapify (int data[], int heapSize, int index, int panjangArray);

int getParentIndex (int curr);

int getChildLeftIndex (int curr);

int getChildRightIndex (int curr);

void Swap (int data[], int i, int j);

#endif
