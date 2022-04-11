#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> tab(n);
        for(int i = 0; i < n; ++i)
            cin >> tab[i];
        sort(tab.begin(), tab.end());
        int most = tab[0];
        long long times = 1;
        int curr = 1;
        int curr_el = tab[0];
        for(int i = 1; i < n; ++i){
            if(tab[i] == curr_el){
                curr++;
                if(curr > times){
                    most = tab[i];
                    times = curr;
                }
            } else {
                curr = 1;
                curr_el = tab[i];
            }
        }
        long long els = times;
        long long ops = 0;
        while(els < n){
            ops++;
            if(els + times < n){
                els += times;
                ops += times;
            }
            else {
                els += (n - times);
                ops += (n - times);
            }
            times *= 2;
        }
        cout << ops << endl;
        
    }
}