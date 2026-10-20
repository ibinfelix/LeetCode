#include <vector>
#include <iostream>
#include <string>
using namespace std;

const char EMPTY = '.', QUEEN = 'Q';

bool isSafe(int row, int col, const vector<string>& board, int n) {
    // Check upper-left diagonal
    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == QUEEN) return false;
        i--;
        j--;
    }

    // Check lower-left diagonal
    i = row + 1;
    j = col - 1;
    while (i < n && j >= 0) {
        if (board[i][j] == QUEEN) return false;
        i++;
        j--;
    }

    // Check same row to the left
    for (int k = 0; k < col; k++) {
        if (board[row][k] == QUEEN) return false;
    }

    return true;
}

void solve(int col, vector<string>& board, vector<vector<string>>& result, int n) {
    if(col == n) {
        result.push_back(board);
        return;
    }
    for(int row = 0; row < n; row++) {
        if(isSafe(row, col, board, n)) {
            board[row][col] = QUEEN;
            solve(col + 1, board, result, n);
            board[row][col] = EMPTY;
        }
    }
}

void showChessboard(vector<string> board){
    int n = board.size();
    for (int i=0; i<n+2;i++) cout <<"_ ";
    cout << endl;
    for (int i=0; i<n; i++){
        cout << "| ";
        for (int j=0; j<n; j++) cout << board[i][j] << " ";
        cout << "|" << endl;
    }
    for (int i=0; i<n+2;i++) cout <<"- ";
    cout << endl;
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result = {};
    vector<int> occupiedCols(n);
    vector<int> occupiedDiag1(n << 1);
    vector<int> occupiedDiag2(n << 1);
    vector<string> board(n, string(n, EMPTY));
    solve(0, board, result, n);
    if(result.size()==0){
        cout << "No possible solutions for " << n << " Queens." << endl << endl;
        return {};
    }
    cout << "Results for " << n << " Queens" << endl;
    for (int i=0; i<result.size(); i++){
        cout << i+1 << ".-" << endl;
        showChessboard(result[i]);
    }
    cout << endl;
    return result;
}

int main(){
    while (true){
        cout << "Choose a size for chessboard (whole number): ";
        int n;
        cin >> n;
        cout << endl;
        solveNQueens(n); 
    }
    return 0;
}