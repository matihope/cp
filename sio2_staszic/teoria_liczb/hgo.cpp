#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0)
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a;
    cin >> n;
    while(n--){
        cin >> a;
        int p1 = a / 2, p2 = a / 2;
        p2 += a % 2;
        while(1){
            if(is_prime(p1) && is_prime(p2)){
                cout << p1 << " " << p2 << endl;
                break;
            }
            p1--;
            p2++;
        }
    }
}