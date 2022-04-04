#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> board;
vector<vector<int>> neighbours;
int size_x, size_y;

void tick_cell(int n, int m){
    if(board[n][m] == '.')
        return;

    for(int i = n - 1; i <= n + 1; ++i){
        for(int j = m - 1; j <= m + 1; ++j){
            if(i == n && j == m) continue;
            neighbours[(i + size_y) % size_y][(j + size_x) % size_x]++;
        }
    }
}

void tick(){
    neighbours.assign(size_y, vector<int>(size_x, 0));
    for(int i = 0; i < size_y; i++)
        for(int j = 0; j < size_x; j++)
            tick_cell(i, j);

    for(int i = 0; i < size_y; i++){
        for(int j = 0; j < size_x; j++){
            if((board[i][j] == '.' && neighbours[i][j] == 3) || (board[i][j] == 'X' && (neighbours[i][j] == 2 || neighbours[i][j] == 3)))
                board[i][j] = 'X';
            else
                board[i][j] = '.';
            // neighbours[i][j] = 0;
            
        }
    }
}

void init(int n, int m){
    size_x = n;
    size_y = m;
    board.assign(m, vector<char>(n, '.'));
    neighbours.assign(m, vector<int>(n, 0));
}

int main(){
    int x = 20, y = 12;
    init(x, y);
    for(int i = 0; i < y; i++)
        for(int j = 0; j < x; ++j)
            cin >> board[i][j];

    for(int t = 0; t < 37; ++t){
        tick();
        // for(int i = 0; i < y; i++){
        //     for(int j = 0; j < x; j++){
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }

    cout << neighbours[1][18] << endl;
}