#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    char op;
    long long height = 0;
    long long topper = -1'000'000'000;
    for(long long i = 1; i <= n; ++i){
        cin >> op;
        if(op == 'G'){
            height++;
            long long x = height * n;
            if(height < 0){
                x *= -1;
                if(x % i != 0){
                    x /= i;
                    x -= 1;
                } else {
                    x /= i;
                }
                x *= -1;
            } else {
                x /= i;
            }
            if(i != n){
                if(x + 1 > topper)
                    topper = x + 1;
            }
            else{
                if(height * n % i == 0){
                    if(x > topper){
                        topper = x;
                    }
                } else {
                    if(x + 1 > topper){
                        topper = x + 1;
                    }
                }
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