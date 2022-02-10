#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    char op;
    int height = 0;
    long long topper = -1'000'000'000;
    for(int i = 1; i <= n; ++i){
        cin >> op;
        if(op == 'G'){
            height++;
            long double x = (long double)height * n / i;
            if(x == ceill(x) && i != n){
                if(ceill(x) + 1 > topper)
                    topper = ceill(x) + 1;
            } else {
                if(ceill(x) > topper)
                    topper = ceill(x);
            }
        }
        else{
            height--;
        }
    }

    if(topper == -1'000'000'000){
        cout << 1 << endl;
    } else {
        cout << abs(topper - height) << endl;
    }
}