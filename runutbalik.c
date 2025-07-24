#include <stdio.h>
#include <stdbool.h>

#define N 4

int board[N][N];

// Fungsi untuk mencetak solusi
void printBoard() {
	int i,j;
    for (i = 0; i < N; i++) {
        for ( j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Cek apakah aman menempatkan ratu di board[row][col]
bool isSafe(int row, int col) {
    int i, j;

    // Cek kolom di atas
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Cek diagonal kiri atas
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Cek diagonal kanan atas
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Fungsi rekursif untuk menyelesaikan N-Queens
bool solveNQueens(int row) {
    if (row == N) {
        printBoard();  // cetak solusi ketika semua ratu sudah ditempatkan
        return true;
    }

    bool foundSolution = false;
    int col;
    for ( col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;  // tempatkan ratu
            foundSolution |= solveNQueens(row + 1);  // lanjutkan ke baris berikutnya
            board[row][col] = 0;  // backtrack
        }
    }

    return foundSolution;
}

int main() {
    if (!solveNQueens(0)) {
        printf("Tidak ada solusi.\n");
    }
    return 0;
}
