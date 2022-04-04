#include <iostream>

using namespace std;

long long quick_pow(long long a, int p){
    long long ans = 1;
    while(p){
        if(p & 1)
            ans = a * ans;
        a = a * a;
        p /= 2;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;
    long long fives = 0;
    for(int i = 1; i <= n; ++i){
        fives += n / quick_pow(5, i);
        if(quick_pow(5, i) > n)
            break;
    }
    cout << fives << endl;
}