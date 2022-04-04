#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> PII;
bool see(long long& R, PII& a, PII& b){
    if(a.first == b.first)
        return abs(a.first) > R;
    
    if(a.second == b.second)
        return abs(a.second) > R;


    long long A = a.second - b.second;
    long long B = a.first - b.first;
    long long C = a.second * B - a.first * A;
    // cout << abs(C) << endl;
    // cout << R * sqrt(A * A + B * B) << endl;
    return abs(C) >= R * (long long)sqrt(A * A + B * B);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, r;
    cin >> n >> r;
    vector<PII> tab(n);
    for(int i = 0; i < n; ++i){
        cin >> tab[i].first >> tab[i].second;
    }
    long long counter = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i == j) continue;
            if(see(r, tab[i], tab[j])){
                counter++;
            }
        }
    }
    cout << counter / 2 << endl;
}