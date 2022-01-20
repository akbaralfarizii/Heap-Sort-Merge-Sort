#ifndef array_H
#define array_H


int *create_Array (int panjangArray);

int *Array__CreateFile (int panjangArray);

int *duplicate_Array (int data[], int panjangArray);

void Array__Display (int data[], int panjangArray);

int getpanjangArrayFile();

void WriteHeapFileMin (int data[], int panjangArray);

void WriteHeapFileMax (int data[], int panjangArray);

void WriteMergeFileMin (int data[], int panjangArray);

void WriteMergeFileMax (int data[], int panjangArray);

bool isFileEmpty();

void DataManual();

void SortingFile();

#endif
