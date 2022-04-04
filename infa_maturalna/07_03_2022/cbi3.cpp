#include <bits/stdc++.h>

using namespace std;

long long bin2dec(string bin){
    long long ans = 0;
    for(auto c: bin){
        ans *= 2;
        ans += c - '0';
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string greatest = "0";
    for(int i = 0; i < n; ++i){
        string a;
        cin >> a;
        long long dec = bin2dec(a);
        if(dec <= 65535){
            if(bin2dec(greatest) < dec){
                greatest = a;
            }
        }
    }
    cout << greatest << endl << bin2dec(greatest) << endl;
}