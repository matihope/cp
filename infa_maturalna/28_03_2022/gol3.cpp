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

int count(){
    int cnt = 0;
    for(auto& v: board)
        for(auto& c: v)
            if(c == 'X') cnt++;
    return cnt;
}

int main(){
    size_x = 20;
    size_y = 12;
    board.assign(size_y, vector<char>(size_x, '.'));
    neighbours.assign(size_y, vector<int>(size_x, 0));
    for(int i = 0; i < size_y; i++)
        for(int j = 0; j < size_x; ++j)
            cin >> board[i][j];

    int counter_prev = count();
    for(int t = 1; t <= 101; ++t){
        tick();
        int counter_now = count();
        if(counter_now == counter_prev){
            cout << t << endl;
            // cout << counter_now << endl;
            break;
        }
        counter_prev = counter_now;

        // for(int i = 0; i < size_y; i++){
        //     for(int j = 0; j < size_x; j++)
        //         cout << board[i][j] << " ";
        //     cout << endl;
        // }
        // cout << endl;
    }

}