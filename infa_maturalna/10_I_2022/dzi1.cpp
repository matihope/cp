#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, counter = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int now_counter = 0; 
        vector<vector<char>> m(30, vector<char>(30, '.'));
        for(int i = 0; i < 30; ++i){
            for(int j = 0; j < 30; ++j){
                cin >> m[i][j];
                if(m[i][j] == '*')
                    now_counter++;
            }
        }
        if(now_counter >= 630)
            counter++;
    }
    cout << counter << endl;
}