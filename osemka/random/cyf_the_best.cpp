#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    LL n = 0;
    while(t--){
        cin >> n;

        if(n <= 9){
            cout << n << endl;
            continue;
        }

        LL upper = 9, lower = 0;
        int tens = 2;
        LL tens_p = 10;
        while(upper < n){
            lower = upper;
            upper += 9 * tens * tens_p;
            tens++;
            tens_p *= 10;
        }
        LL num = ceill((n - lower) / (long double)(tens - 1LL)) + (tens_p / 10LL) - 1LL;
        string num_str = to_string(num);
        cout << num_str[(n - lower - 1) % (tens - 1)] << endl;
    }
}
