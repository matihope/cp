#include "zgalib.hpp"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int z = init();
    while(z--){
        int n = ile_liczb();
        vector<int> tab(n);
        if(n <= 30){
            for(int i = 0; i < n; i++){
                tab[i] = jedna(i + 1);
            }
            odp(tab);
        }
    }
}