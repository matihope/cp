#include <bits/stdc++.h>

using namespace std;

int silnia(int n){
    if(n == 0) return 1;
    return n * silnia(n - 1);
}

int main(){
    int n, a;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a;
        int counter = 0;
        for(auto c: to_string(a))
            counter += silnia(c - '0');
        if(counter == a)
            cout << a << endl;
    }
}