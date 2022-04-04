#include <iostream>

using namespace std;

int quick_pow(long long a, int p, int mod){
    int ans = 1;
    while(p){
        if(p & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        p /= 2;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << quick_pow(2, n, 1e9 + 7) << endl;
}
