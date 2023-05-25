// The program adds to matrices and writes their sum on the screen. It takes n 
// as the dimensions of two matrices and then asks for values to fill them up.
// Then we will be able to see a visual representation of both matrices and their 
// sum on the screen.

#include <stdio.h>
#define max 20
int main() {

	//Variables:
	int n;			//matrices dimensions
	int i, j;		//iterative variables
	int a[max][max], b[max][max], suma[max][max];	//matrices

	//Dialog
	printf("The program adds two matrices of size n\n\n");
	printf("Enter the size of matrices: ");

	//Inserting data - size n
	while (scanf_s("%d", &n) != 1 || getchar() != '\n') {
		printf("The data was incorrect. Try again: ");
		while (getchar() != '\n')
			;
	}

	//Inserting data - elements of matrix a
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			printf("Enter element a[%d][%d]: ", i, j);
			while (scanf_s("%d", &a[i][j]) != 1 || getchar() != '\n') {
				printf("The data was incorrect. Try again: ");
				while (getchar() != '\n')
					;
			}
		}
	}

	//Inserting data - elements of matrix b
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			printf("Enter element b[%d][%d]: ", i, j);
			while (scanf_s("%d", &b[i][j]) != 1 || getchar() != '\n') {
				printf("The data was incorrect. Try again: ");
				while (getchar() != '\n')
					;
			}
		}
	}
	printf("\n");

	//Printing matrix a
	printf("Matrix a:\n");
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			printf("%.2d ", a[i][j]);

		}
		printf("\n");
	}
	printf("\n");

	//Printing matrix b
	printf("Matrix b:\n");
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			printf("%.2d ", b[i][j]);

		}
		printf("\n");
	}

	//Adding elements of matrix a to matrix b
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			suma[i][j] = a[i][j] + b[i][j];
		}
	}

	//Printing sum of matrices
	printf("\nSum of matrices: \n");
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			printf("%.2d ", suma[i][j]);

		}
		printf("\n");
	}


	return 0;
}