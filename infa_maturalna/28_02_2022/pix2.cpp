#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int x, y, a, b;
    cin >> x >> y;
    int counter = 0;
    for(int i = 0; i < x; i++){
        vector<int> tab(y), tab2;
        for(int j = 0; j < y; j++) cin >> tab[j];
        tab2 = tab;
        reverse(tab2.begin(), tab2.end());
        for(int j = 0; j < y; j++){
            if(tab[j] != tab2[j]){
                counter++;
                break;
            }
        }
    }
    cout << counter << endl;
}