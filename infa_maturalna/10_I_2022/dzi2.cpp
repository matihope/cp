#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<char>>& m1, vector<vector<char>>& m2){
    for(int i = 0, ii = 29; i < 30; ++i, --ii){
        for(int j = 0, jj = 29; j < 30; ++j, --jj){
            if(m1[i][j] != m2[ii][jj])
                return false;
        }
    }
    return true;
}

int main(){
    int n, counter = 0;
    cin >> n;
    vector<vector<vector<char>>> maps;
    for(int i = 1; i <= n; ++i){
        int now_counter = 0; 
        vector<vector<char>> m(30, vector<char>(30, '.'));
        for(int i = 0; i < 30; ++i){
            for(int j = 0; j < 30; ++j){
                cin >> m[i][j];
            }
        }
        for(int j = 1; j < i; ++j){
            if(check(maps[j - 1], m)){
                cout << j << " " << i << endl;
                break;
            }
        }
        maps.push_back(m);
    }
}