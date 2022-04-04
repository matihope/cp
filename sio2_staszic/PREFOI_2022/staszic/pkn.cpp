#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> PLL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, a;
    cin >> n >> k;
    auto cmp = [&](const PLL a, const PLL b){
        if(a.second == 0)
            return false;
        if(b.second == 0)
            return true;
        return (a.first / float(a.second)) < (b.first / float(b.second)); 
    };
    priority_queue<PLL, vector<PLL>, decltype(cmp)> as(cmp);
    for(int i = 0; i < n; ++i){
        cin >> a;
        as.push({a, 0});
    }
    for(long long i = 0; i < k; ++i){
        PLL t = as.top();
        as.pop();
        t.second++;
        as.push(t);
    }
    long double sum = 0;
    while(!as.empty()){
        PLL t = as.top();
        as.pop();
        sum += t.first / double(t.second);
    }
    cout << round(sum) << endl;
}