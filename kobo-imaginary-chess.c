#include <stdio.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    // Initialize the chessBoard array with initial value 0
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            *(chessBoard + x * size + y) = 0;
        }
    }

    // Check each possible knight move
    int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                       {2, 1},   {1, 2},   {-1, 2}, {-2, 1}};

    for (int k = 0; k < 8; k++) {
        int new_i = i + moves[k][0];
        int new_j = j + moves[k][1];
        if (new_i >= 0 && new_i < size && new_j >= 0 && new_j < size) {
            // Update the chessBoard value at positions reachable by the knight
            *(chessBoard + new_i * size + new_j) = 1;
        }
    }

    // Display the result array chessBoard
    printf("Result array %d x %d:\n", size, size);
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            printf("%d ", *(chessBoard + x * size + y));
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    printf("Enter the knight's position (i j): ");
    scanf("%d %d", &i, &j);

    // Declare a 2D array for the chessboard
    int size = 8;
    int chessBoard[8][8];

    // Call the koboImaginaryChess function
    koboImaginaryChess(i, j, size, (int *)chessBoard);

    return 0;
}
