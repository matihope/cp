#include <bits/stdc++.h>

using namespace std;

void kmp(const string& s, vector<int>& ps){
    ps[0] = -1;
    int l = 0;
    for(int i = 2; i < s.size(); i++){
        l = ps[i - 1];
        while(l >= 0 && s[i] != s[l + 1])
            l = ps[l];
        ps[i] = ++l;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    string s3 = '$' + s1 + '$' + s2;
    vector<int> ps(s3.size(), 0);
    kmp(s3, ps);
    for(int i = n; i < s3.size(); ++i)
        if(ps[i] == n)
            cout << i - n * 2 << endl;
}