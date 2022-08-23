// ROLL: 21052080

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct coordinates{
    int x, y;
};

struct smallest{
    int sml, p1, p2;
};

int calculateDistance(int x1, int y1, int x2, int  y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

void euclideanDistanceMatrix(struct coordinates *cords, int **matrix){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matrix[i][j] = calculateDistance(cords[i].x, cords[i].y, cords[j].x, cords[j].y);
        }
    }
}

int checkSymmetry(int **matrix){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if(matrix[i][j] != matrix[j][i])return 0;
        }
    }
    return 1;
}
struct smallest findSmallest(int **matrix){
    struct smallest s;
    s.sml = matrix[0][1];
    for (int i = 0; i < 10; i++){
        for (int j = i+1; j < 10; j++){
            if(matrix[i][j] < s.sml){
                s.sml = matrix[i][j];
                s.p1 = i; s.p2 = j;
            }
        }
    }
    return s;
}

void main(){
    srand(time(NULL));

    // initializing struct cords
    struct coordinates *cords = (struct coordinates *)malloc(10 * sizeof(struct coordinates));

    // initializing matrix
    int **matrix = (int**)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)matrix[i] = (int*)malloc(10 * sizeof(int));
    
    // generating random values for cords
    for (int i = 0; i < 10; i++){
        cords[i].x = abs(rand() % 100 - 1);
        cords[i].y = abs(rand() % 100 - 1);
    }
    // printing original cords
    printf("Generated Coordinates:\n");
    for (int i = 0; i < 10; i++){
        printf("%d | %d\n", cords[i].x, cords[i].y);
    }

    // Calculating Euclidian Distance via Function
    euclideanDistanceMatrix(cords, matrix);

    // Printing Calculated Matrix
    printf("Generated Matrix:\n");
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    //Checking Symmetry
    if(checkSymmetry(matrix))printf("\nMatrix is Symmetrical :)");
    else printf("\nMatrix is NOT Symmetric :(");

    // Printing Final Answer
    struct smallest final = findSmallest(matrix);
    printf("\nSmallest distance is %d between point [%d] and [%d]", final.sml, final.p1, final.p2);
}