#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define INF_I 1000000001
#define INF_LL 1000000000000000001

LL count_digits_before(LL n){
    LL n_cpy = n;
    int tens = 0;
    while(n_cpy >= 10){
        tens++;
        n_cpy /= 10;
    }

    LL digits = 0;
    LL ten = 9;
    for(int i = 1; i <= tens; ++i){
        digits += ten * i;
        ten *= 10;
    }
    LL t = 1;
    for(int i = 0; i < tens; ++i) t *= 10;
    digits += (n - t) * (tens + 1);
    return digits;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        LL n;
        cin >> n;
        LL l = 1, r = INF_LL;
        while(l < r){
            LL m = (l + r) / 2;
            if(count_digits_before(m) < n)
                l = m + 1;
            else
                r = m;
        }
        int toGo = n - count_digits_before(l - 1);
        string liczba = to_string(l - 1);
        cout << liczba[toGo - 1] << endl;
    }
}
