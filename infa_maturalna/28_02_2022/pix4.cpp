#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int x, y, max_len = 0;
    cin >> x >> y;
    vector<vector<int>> tab(x, vector<int>(y));
    vector<vector<bool>> vis(x, vector<bool>(y, 0));
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            cin >> tab[i][j];
    for(int j = 0; j < y; ++j){
        int curr = 1;
        for(int i = 1; i < x; i++){
            if(tab[i - 1][j] == tab[i][j]) max_len = max(++curr, max_len);
            else curr = 1;
        }
    }
    cout << max_len << endl;
}