#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

LL count_digits_before(const LL& num) {
    LL before = 0;
    LL start = 1;
    int pow = 1;
    while(num > start * 10) {
        before += start * 9 * pow;
        start *= 10;
        pow++;
    }
    return before + (num - start) * pow;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        LL n;
        cin >> n;

        LL l = 1, r = 68800000000000000, m;
        while(l < r){
            m = (l + r) / 2;
            if(count_digits_before(m + 1) >= n)
                r = m;
            else
                l = m + 1;
        }
        int to_go = n - count_digits_before(l) - 1;
        string number = to_string(l);
        cout << number[to_go] << endl;

    }
}
