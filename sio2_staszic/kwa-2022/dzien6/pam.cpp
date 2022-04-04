#include <bits/stdc++.h>

using namespace std;

void zfunc(const string& s, vector<int>& z){
    int n = s.size();
    for(int i = 1, l = 0, r = 0; i < n; ++i){
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[z[i] + i])
            z[i]++;
        if(i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    // normal
    string connected = s1 + '$' + s2;
    vector<int> z_values_normal(connected.size(), 0);
    zfunc(connected, z_values_normal);

    // reversed
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    connected = s1 + '$' + s2;
    vector<int> z_values_inverted(connected.size(), 0);
    zfunc(connected, z_values_inverted);

    // find solution
    int best = 0;
    int s1_s = s1.size();
    for(int i = s1.size() + 1, j = z_values_inverted.size() - s1.size(); i <= connected.size() - s1.size(); i++, j--)
        best = max(best, min(s1_s, z_values_normal[i] + z_values_inverted[j]));
    cout << s1_s - best << endl;
}