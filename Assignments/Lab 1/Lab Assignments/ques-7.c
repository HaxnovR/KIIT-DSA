// Let  A  be  nXn  square dynamic matrix.  WAP  by  using  appropriate
// user defined functions for the following:
// a) Find the number of nonzero elements in A
// b) Find the sum of the elements above the leading diagonal.
// c) Display the elements below the minor diagonal.
// d) Find the product of the diagonal elements.

#include<stdio.h>
#include<stdlib.h>

int nonZero(int **arr, int s){
    int count = 0;
    for (int i = 0; i < s; i++){
        for (int j = 0; j < s; j++){
            if(arr[i][j] == 0)count++;
            // count++;
        }
    }
    return (s*s)-count;
}

int aboveLeadingDiagonal(int **arr, int s){
    int count = 0;
    for (int i = 0; i < s; i++){
        for (int j = i+1; j < s; j++){
            count += arr[i][j];
        }
    }
    return count;
}

void belowMinorDiagona(int **arr, int s){
    for (int i = 1; i < s; i++){
        for (int j = s-i; j < s; j++){
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
}

int diagonalProduct(int **arr, int s){
    int count = 1;
    for (int i = 0; i < s; i++){
        count = count * arr[i][i];
        count = count * arr[i][s-1-i];
    }
    if(s%2 == 1)count = count / arr[s/2][s/2];
    return count;
}

int main(){
    srand(time(NULL));
    int size, **arr;
    printf("Enter the size of square matrix: ");
    scanf("%d", &size);
    arr = (int **)malloc(size*sizeof(int));
    for (int i = 0; i < size; i++){
        arr[i] = (int *)malloc(size*sizeof(int));
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            arr[i][j] = rand() % 10 - 1;
        }
    }
    
    printf("\nGenerated 2-D Array:\n");
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
    printf("The number of non-Zero elements in A = %d", nonZero(arr, size));
    printf("\nThe sum of elements above leading diagonal = %d", aboveLeadingDiagonal(arr, size));
    printf("\nThe elements below the minor diagonal :\n"); belowMinorDiagonal(arr, size);;
    printf("\nThe product of the diagonals = %d", diagonalProduct(arr, size));

    return 0;
}