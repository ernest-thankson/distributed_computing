#include <stdio.h>
#include <stdlib.h>
#include <time.h>



	
	/*
	 * PARAMETERS USED IN FUNCTIONS
	 *array - pointer to multidimensional array passed to function
	 *size - number of elements in "array"
	 *dimensions - array of dimensions of the array
	 *numdimensions - number of dimensions of array
	 */

	/*Function that initializes all elements of an array to 0's*/
	void initialize(int *array, int size){
		int i;
		for (i=0; i<size; i++){
			*(array + i) = 0;
		}	
	}

	/*Function that sets 10% of array elements uniformly to 1's*/
	void setones(int *array, int size){
		srand((unsigned int) time(0));
		int var, i, lim;
		lim = 0.1 * size;
		for (i = 0; i<lim; i++){
			var = rand() % size;
			*(array + var) = 1;
		}
	}
	/*Function that chooses 5% of the elements and prints their "coordinate indices" and "values"*/
	void printer(int *array, int size, int numdimensions){
		int i, j, k, indices[numdimensions], res, rem, lim, var;
		srand((unsigned int) time(0));
		lim = 0.05 * size;
	
		for (i=0; i<lim; i++){
			var = rand() % size;
			res = 0;
			rem = 0;
		
			for (j=0; j<numdimensions; i++){
				res = (int) var/numdimensions;
				rem = var%numdimensions;
				indices[j] = rem;	
			}
			printf("Value %d at index ", *(array+var));
			for (k=numdimensions-1; k>=0; i++){
				printf("[%d]", indices[k]);
			
			}
			printf("\n");
			
		}
	}

int main(void){
	printf("hello\n");
	/*Dynamically generate the 4 arrays */
	int *a1, *a2, *a3, *a4;
	a1 = (int *) malloc(1 * 10 * sizeof(int));
/*	a2 = (int *) malloc(100 * 100 * 100 * sizeof(int));
	a3 = (int *) malloc(50 * 50 * 50 * 50 * sizeof(int));
	a4 = (int *) malloc(20 * 20 * 20 * 20 * 20 * sizeof(int));*/
	printf("hello.");
	initialize(a1, 100*100);
	setones(a1, 100*100);
	printer(a1,100*100, 2);
	free(a1);
	
}
