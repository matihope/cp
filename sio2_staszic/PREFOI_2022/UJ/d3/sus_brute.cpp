#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int z;
    cin >> z;
    while(z--){
        int n, q;
        cin >> n >> q;
        vector<int> tab(n);
        for(int i = 0; i < n; ++i)
            cin >> tab[i];
        
        int query, aj;
        while(q--){
            cin >> query >> aj;
            if(query == 1){
                tab[aj - 1]++;
            } else if(query == 2){
                tab[aj - 1]--;
            } else {
                long long sum = 0;
                for(int i = 1; i <= n; ++i){
                    sum += tab[i - 1] / aj;
                    if(tab[i - 1] % aj) sum++;
                }
                cout << sum << endl;
            }
        }
    }
}