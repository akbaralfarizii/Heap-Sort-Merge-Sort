#include "header.h"

int *create_Array (int panjangArray)
{
	int i;
	int *data = (int*) malloc (panjangArray * sizeof(int));
	
	for (i = 0; i < panjangArray; i++)
	{
		fflush(stdin);
		printf ("Input No. %d: ", i + 1);
		while (scanf ("%d", &data[i]) == 0)
		{
			printf ("Inputan Tidak Kami Pahami\n\n");
			printf ("Input No. %d: ", i + 1);
			fflush(stdin);
		}
	}
	
	system ("cls");
	return data;
}

int *Array__CreateFile (int panjangArray)
{
	FILE *fPointer;
	fPointer = fopen ("Assets/Data.txt", "r");
	
	if (fPointer == NULL)
	{
		perror ("Error opening file!");
		exit (1);
	}
	
	int i;
	int *data = (int*) malloc (panjangArray * sizeof(int));
	
	for (i = 0; i < panjangArray; i++)
	{
		fscanf (fPointer, "%d", &data[i]);
	}

	fclose (fPointer);
	return data;
}

int *duplicate_Array (int data[], int panjangArray)
{
	int i;
	int *newData = (int*) malloc (panjangArray * sizeof(int));
	
	for (i = 0; i < panjangArray; i++)
	{
		newData[i] = data[i];
	}
	
	return newData;
}

void Array__Display (int data[], int panjangArray)
{
	int i; 
	for (i = 0; i < panjangArray; i++)
	{
		printf("%d ", data[i]);
	}
	printf ("\n");
}

int getpanjangArrayFile()
{
	FILE *fPointer;
	fPointer = fopen ("Assets/Data.txt", "r");
	
	if (fPointer == NULL)
	{
		perror ("Error opening file!");
		exit (1);
	}
	
	int panjangArray = 0;
	int tempData;

	while (!feof(fPointer))
	{
		fscanf(fPointer, "%d", &tempData);
		panjangArray++;
		if ((fscanf(fPointer, "%d", &tempData)) == 0)
		{
			printf ("===========================================================\n");
			printf ("  Terdapat data yang tidak sesuai pada file!\n");
			printf ("  Data yang diinputkan harus berupa integer!\n");
			printf ("===========================================================");
			exit(0);
		}
		else 
		{
			panjangArray++;
		}
	}
	
	fclose (fPointer);
	return panjangArray;
}

void WriteHeapFileMin (int data[], int panjangArray)
{
	FILE *fPointer;
	fPointer = fopen ("Assets/HeapSort/AscendingHeap.txt", "w");
	
	if (fPointer == NULL)
	{
		perror ("Error opening file!");
		exit (1);
	}
	
	int i;
	for (i = 0; i < panjangArray; i++)
	{
		fprintf (fPointer, "%d ", data[i]);
	}
	
	fclose (fPointer);
}

void WriteHeapFileMax (int data[], int panjangArray)
{
	FILE *fPointer;
	fPointer = fopen ("Assets/HeapSort/DescendingHeap.txt", "w");
	
	if (fPointer == NULL)
	{
		perror ("Error opening file!");
		exit (1);
	}
	
	int i;
	for (i = 0; i < panjangArray; i++)
	{
		fprintf (fPointer, "%d ", data[i]);
	}
	
	fclose (fPointer);
}

void WriteMergeFileMin (int data[], int panjangArray)
{
	FILE *fPointer;
	fPointer = fopen ("Assets/MergeSort/AscendingMerge.txt", "w");
	
	if (fPointer == NULL)
	{
		perror ("Error opening file!");
		exit (1);
	}
	
	int i;
	for (i = 0; i < panjangArray; i++)
	{
		fprintf (fPointer, "%d ", data[i]);
	}
	
	fclose (fPointer);
}

void WriteMergeFileMax (int data[], int panjangArray)
{
	FILE *fPointer;
	fPointer = fopen ("Assets/MergeSort/DescendingMerge.txt", "w");
	
	if (fPointer == NULL)
	{
		perror ("Error opening file!");
		exit (1);
	}
	
	int i;
	for (i = 0; i < panjangArray; i++)
	{
		fprintf (fPointer, "%d ", data[i]);
	}
	
	fclose (fPointer);
}

bool isFileEmpty()
{
	FILE *fPointer;
	fPointer = fopen ("Assets/Data.txt", "r");
		
	if (fPointer == NULL)
	{
		perror ("Error opening file!");
		exit (1);
	}
	
	fseek(fPointer, 0, SEEK_END);
	if (ftell(fPointer) == 0)
	{
		fclose (fPointer);
		return true;
	}
	
	fclose (fPointer);
	return false;
}

void DataManual()
{
	int panjangArray;
	printf ("Panjang Data: ");
	while (scanf ("%d", &panjangArray) == 0)
	{
		system ("cls");
		printf ("Inputan Tidak Kami Pahami\n");
		printf ("Panjang Data: ");
		fflush(stdin);
	}
	
	if (panjangArray == 0)
	{
		printf ("Input sama dengan 0, tidak ada data yang di-inputkan\n");
		return;
	}

	system ("cls");
	
	int *dataMin = create_Array (panjangArray);
	int *dataMax = duplicate_Array (dataMin, panjangArray);
	int StartIndex = 0;
	
	int pil;
	backtooption:
	printf ("===========================================================\n");
	printf ("Pilihan Metode Sorting:\n");
	printf ("\t1. Heap Sort\n");
	printf ("\t2. Merge Sort\n");
	printf ("===========================================================\n");
	printf ("pilihan metode sorting:");
	while (scanf ("%d", &pil) == 0)
		{
			system ("cls");
			printf ("===========================================================\n");
			printf ("Pilihan Metode Sorting:\n");
			printf ("1. Heap Sort\n");
			printf ("2. Merge Sort\n");
			printf ("===========================================================\n");
			printf ("   Inputan Tidak Kami Pahami\n\n");
			printf ("   pilihan metode sorting: ");
			fflush(stdin);
		}
		
	system ("cls");
	switch (pil){
		case 1:
		{
			printf ("			Heap Sort\n");
			printf ("===========================================================\n");
	
			printf("Data:\n");
			Array__Display (dataMin, panjangArray);
			printf ("\n");
			
			HeapSortMin (dataMin, panjangArray);
			printf("\nSorted Data (Ascending):\n");
			Array__Display (dataMin, panjangArray);
			
			HeapSortMax (dataMax, panjangArray);
			printf("\nSorted Data (Descending):\n");
			Array__Display (dataMax, panjangArray);
		
			printf ("===========================================================\n");
			break;
		}
		case 2:
		{
			printf ("			Merge Sort\n");
			printf ("===========================================================\n");
	
			printf("Data:\n");
			Array__Display (dataMin, panjangArray);
			printf ("\n");
			
			MergeSortMin(dataMin, StartIndex, panjangArray-1);
			printf("\nSorted Data (Ascending):\n");
			Array__Display (dataMin, panjangArray);
			
			MergeSortMax(dataMax, StartIndex, panjangArray-1);
			printf("\nSorted Data (Descending):\n");
			Array__Display (dataMax, panjangArray);
	
			printf ("===========================================================\n");	
			break;
		}
		default:
		printf ("===========================================================\n");
		printf ("  Inputan Tidak Kami Pahami\n");
		printf ("===========================================================\n");
		goto backtooption;
		break;	
	}
	

}

void SortingFile()
{
	if (isFileEmpty())
	{
		printf ("===========================================================\n");
		printf ("  File Tidak Ditemukan!\n");
		printf ("  Silahkan masukan data dalam file terlebih dahulu!\n");
		printf ("===========================================================\n");
		return;
	}
	
	int panjangArray = getpanjangArrayFile();
	int *dataMin = Array__CreateFile (panjangArray);
	int *dataMax = duplicate_Array (dataMin, panjangArray);
	int StartIndex = 0;
	
	int pil;
	backtooption:
	printf ("===========================================================\n");
	printf ("Pilihan Metode Sorting:\n");
	printf ("\t1. Heap Sort\n");
	printf ("\t2. Merge Sort\n");
	printf ("===========================================================\n");
	printf ("pilihan metode sorting:");
	while (scanf ("%d", &pil) == 0)
		{
			system ("cls");
			printf ("===========================================================\n");
			printf ("Pilihan Metode Sorting:\n");
			printf ("1. Heap Sort\n");
			printf ("2. Merge Sort\n");
			printf ("===========================================================\n");
			printf ("   Inputan Tidak Kami Pahami\n\n");
			printf ("   pilihan metode sorting: ");
			fflush(stdin);
		}
		
	system ("cls");
	switch (pil){
		case 1:
		{
			printf ("			Heap Sort\n");
			printf ("===========================================================\n");
	
			printf("Data:\n");
			Array__Display (dataMin, panjangArray);
			printf ("\n");
			
			HeapSortMin (dataMin, panjangArray);
			printf("\nSorted Data (Ascending):\n");
			Array__Display (dataMin, panjangArray);
			WriteHeapFileMin (dataMin, panjangArray);
	
			HeapSortMax (dataMax, panjangArray);
			printf("\nSorted Data (Descending):\n");
			Array__Display (dataMax, panjangArray);
			WriteHeapFileMax (dataMax, panjangArray);
		
			printf ("===========================================================\n");
			break;
		}
		case 2:
		{
			printf ("			Merge Sort\n");
			printf ("===========================================================\n");
	
			printf("Data:\n");
			Array__Display (dataMin, panjangArray);
			printf ("\n");
			
			MergeSortMin(dataMin, StartIndex, panjangArray-1);
			printf("\nSorted Data (Ascending):\n");
			Array__Display (dataMin, panjangArray);
			WriteMergeFileMin (dataMin, panjangArray);
	
			MergeSortMax(dataMax, StartIndex, panjangArray-1);
			printf("\nSorted Data (Descending):\n");
			Array__Display (dataMax, panjangArray);
			WriteMergeFileMax (dataMax, panjangArray);
	
			printf ("===========================================================\n");	
			break;
		}
		default:
		printf ("===========================================================\n");
		printf ("  Inputan Tidak Kami Pahami\n");
		printf ("===========================================================\n");
		goto backtooption;
		break;	
	}
}
