#include <bits/stdc++.h>

using namespace std;

long long to_dec(string s){
    long long ans = 0;
    int base = s.back() - '0';
    s.pop_back();
    reverse(s.begin(), s.end());
    int p = 0;
    for(auto& c: s){
        ans += (c - '0') * pow(base, p++);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    string s_min, s_max;
    long long ans_min = 100000000000000, ans_max = 0;
    for(int i = 0; i < 999; ++i){
        cin >> s;
        if(to_dec(s) > ans_max){
            ans_max = to_dec(s);
            s_max = s;
        }
        if(to_dec(s) < ans_min){
            ans_min = to_dec(s);
            s_min = s;
        }

    }
    cout << s_min << endl;
    cout << s_max << endl;
    cout << ans_min << endl;
    cout << ans_max << endl;
}