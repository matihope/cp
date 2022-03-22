#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        int nw = gcd(a, b);
        if(nw == 1){
            cout << a << endl;
        } else {
            if(nw == a)
                cout << 1 << endl;
            else
                cout << a / nw << endl;
        }
    }
}