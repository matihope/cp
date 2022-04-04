#include <bits/stdc++.h>

using namespace std;

int to_dec(string s){
    long long ans = 0;
    s.pop_back();
    reverse(s.begin(), s.end());
    int p = 0;
    for(auto& c: s){
        ans += (c - '0') * pow(8, p++);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    long long counter = 0;
    for(int i = 0; i < 999; ++i){
        cin >> s;
        if(s.back() == '8')
            counter += to_dec(s);
    }
    cout << counter << endl;
}