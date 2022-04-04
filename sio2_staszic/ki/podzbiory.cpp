#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < (1<<n); ++i){
        for(int j = n - 1; j >= 0; --j){
            if((1<<j)&i) cout << 1;
            else cout << 0;
        }
        cout << '\n';
    }
}
