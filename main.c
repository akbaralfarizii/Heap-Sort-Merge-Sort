#include "header.h"


int main()
{
	while (1)
	{
		int pilih;
		printf("\t    program Metode Sorting Heap & Merge\n");
		printf ("===========================================================\n");
		printf ("\t1. Masukan Data Manual\n");
		printf ("\t2. Gunakan Data yang Tersedia \n");
		printf ("\t3. Exit\n");
		printf ("===========================================================\n");
		printf ("   Pilihan Menu: ");
		while (scanf ("%d", &pilih) == 0)
		{
			system ("cls");
			printf("\t\tProgram Metode Sorting Heap & Merge\n");
			printf ("===========================================================\n");
			printf ("\t1. Masukan Data Manual\n");
			printf ("\t2. Gunakan Data yang Tersedia \n");
			printf ("\t3. Exit\n");
			printf ("===========================================================\n");
			printf ("   Inputan Tidak Kami Pahami\n\n");
			printf ("   Pilihan Menu: ");
			fflush(stdin);
		}

		system ("cls");
		
		switch (pilih)
		{
			case 1:
			{
				DataManual();
				break;
			}
			
			case 2:
			{
				SortingFile();
				break;
			}
			
			case 3:
			{
				exit(0);	
			}
			
			default:
			{
				printf ("===========================================================\n");
				printf ("   Inputan Tidak Kami Pahami\n");
				printf ("===========================================================\n");
				break;
			}
		}
		
		printf ("Press any key to Main Menu ....");
		getch();
		system ("cls");
	}
	
	return 0;
}

