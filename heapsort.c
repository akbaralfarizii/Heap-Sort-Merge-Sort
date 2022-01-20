#include "header.h"

void HeapSortMin (int data[], int panjangArray)
{
	int i;
//	printf ("Perubahan Array:\n");
	BuildMaxHeapify (data, panjangArray);
	
	// Sorting Process
	for (i = panjangArray - 1; i > 0; i--)
	{
		Swap (data, 0, i);
	//	Array__Display (data, panjangArray);
		MaxHeapify (data, i, 0, panjangArray);
	}
}

void HeapSortMax (int data[], int panjangArray)
{
	int i;
//	printf ("Perubahan Array:\n");
	BuildMinHeapify (data, panjangArray);
	
	// Sorting Process
	for (i = panjangArray - 1; i > 0; i--)
	{
		Swap (data, 0, i);
	//	Array__Display (data, panjangArray);
		MinHeapify (data, i, 0, panjangArray);
	}
}
void BuildMinHeapify (int data[], int panjangArray)
{
	int startIndex = getParentIndex (panjangArray - 1);
	int heapSize = panjangArray;
	int i;
	
	for (i = startIndex; i >= 0; i--)
	{
		MinHeapify (data, heapSize, i, panjangArray);
	}
}

void BuildMaxHeapify (int data[], int panjangArray)
{
	int startIndex = getParentIndex (panjangArray - 1);
	int heapSize = panjangArray;
	int i;
	
	for (i = startIndex; i >= 0; i--)
	{
		MaxHeapify (data, heapSize, i, panjangArray);
	}
}

void MinHeapify (int data[], int heapSize, int index, int panjangArray)
{
	int smallest = index;
	int leftChild = getChildLeftIndex (index);
	int rightChild = getChildRightIndex (index);

	if (leftChild < heapSize && data[leftChild] < data[smallest])
	{
		smallest = leftChild;
	}
	
	if (rightChild < heapSize && data[rightChild] < data[smallest])
	{
		smallest = rightChild;
	}
	
	if (smallest != index)
	{
		Swap (data, index, smallest);
	//	Array__Display (data, panjangArray);
		MinHeapify (data, heapSize, smallest, panjangArray);
	}
}

void MaxHeapify (int data[], int heapSize, int index, int panjangArray)
{
	int largest = index;
	int leftChild = getChildLeftIndex (index);
	int rightChild = getChildRightIndex (index);

	if (leftChild < heapSize && data[leftChild] > data[largest])
	{
		largest = leftChild;
	}
	
	if (rightChild < heapSize && data[rightChild] > data[largest])
	{
		largest = rightChild;
	}
	
	if (largest != index)
	{
		Swap (data, index, largest);
	//	Array__Display (data, panjangArray);
		MaxHeapify (data, heapSize, largest, panjangArray);
	}
}

int getParentIndex (int curr)
{
	return (curr - 1) / 2;
}

int getChildLeftIndex (int curr)
{
	return 2*curr + 1;
}

int getChildRightIndex (int curr)
{
	return 2*curr + 2;
}

void Swap (int data[], int i, int j)
{
	int temp;
	temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

