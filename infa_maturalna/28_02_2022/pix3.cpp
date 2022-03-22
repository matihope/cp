#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int x, y, counter = 0;
    cin >> x >> y;
    vector<vector<int>> tab(x, vector<int>(y));
    vector<vector<bool>> vis(x, vector<bool>(y, 0));
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            cin >> tab[i][j];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(i + 1 < x){
                if(abs(tab[i + 1][j] - tab[i][j]) > 128){
                    if(!vis[i + 1][j]) counter++;
                    if(!vis[i][j]) counter++;
                    vis[i + 1][j] = vis[i][j] = true;
                }
            }
            if(j + 1 < y){
                if(abs(tab[i][j + 1] - tab[i][j]) > 128){
                    if(!vis[i][j + 1]) counter++;
                    if(!vis[i][j]) counter++;
                    vis[i][j + 1] = vis[i][j] = true;
                }
            }
        }
    }
    cout << counter << endl;
}