#include <iostream>
#include <vector>
using namespace std;

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int n, const vector<vector<bool>>& board, int row, int col) {
    // Check column
    for(int i = 0; i < row; ++i) {
        if(board[i][col])
            return false;
    }

    // Check upper diagonal on left side
    for(int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if(board[i][j])
            return false;
    }

    // Check upper diagonal on right side
    for(int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if(board[i][j])
            return false;
    }

    return true;
}

// Function to solve N-Queens problem and count solutions
int nqueens(int n, vector<vector<bool>>& board, int row) {
    if(row >= n) {
        return 1; // Found a solution
    }

    int count = 0;
    for(int col = 0; col < n; ++col) {
        if(!board[row][col] && isSafe(n, board, row, col)) {
            board[row][col] = true;
            count += nqueens(n, board, row + 1);
            board[row][col] = false; // Backtrack
        }
    }

    return count;
}

int main() {
    int n;
    cout << "Enter the number of queens (n): ";
    cin >> n;

    vector<vector<bool>> board(n, vector<bool>(n, false)); // Initialize board with false values

    int solutions = nqueens(n, board, 0);
    cout << "Total solutions: " << solutions << endl;

    return 0;
}
