#include <stdio.h>
#define ROWS 4
#define COLS 5
#define MAXT 21   /* up to 20 non-zero elements + 1 header row */
 
int main() {
    int a[ROWS][COLS] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    int sparse[MAXT][3];
    int k = 1;
 
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (a[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = a[i][j];
                k++;
            }
 
    sparse[0][0] = ROWS;      /* header: rows, columns, non-zero count */
    sparse[0][1] = COLS;
    sparse[0][2] = k - 1;
 
    printf("Original matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
 
    printf("\nSparse representation (triplet form):\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < k; i++)
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    return 0;
}
