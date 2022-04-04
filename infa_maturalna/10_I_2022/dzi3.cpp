#include <bits/stdc++.h>

using namespace std;

int check(vector<vector<char>>& m1){
    int side;
    for(side = 1; side <= 30; ++side){
        bool found = false;
        for(int i = 0; i < side; ++i)
            if(m1[side - 1][i] == 'X')
                found = true;
        for(int i = 0; i < side; ++i)
            if(m1[i][side - 1] == 'X')
                found = true;
        if(found)
            break;
    }
    return side - 1;
}

int main(){
    int n;
    cin >> n;
    int max_size = 0;
    vector<int> bests;
    for(int i = 1; i <= n; ++i){
        int now_counter = 0; 
        vector<vector<char>> m(30, vector<char>(30, '.'));
        for(int i = 0; i < 30; ++i)
            for(int j = 0; j < 30; ++j)
                cin >> m[i][j];
        
        int now = check(m);
        if(now > max_size){
            max_size = check(m);
            bests.clear();
        } 
        if(now == max_size)
            bests.push_back(i);
    }
    cout << max_size << endl;
    for(auto& i: bests)
        cout << i << endl;
}