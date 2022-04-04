#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

struct el{
    int left, right, index, ans = 0;
};

struct el2{
    int val, ile = 0;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, a, b;
    cin >> n >> t;
    vector<long long> tab(n);
    for(int i = 0; i < n; ++i) cin >> tab[i];

    vector<el> qs;
    for(int i = 0; i < t; ++i){
        cin >> a >> b;
        qs.push_back({a - 1, b - 1, i});
    }
    int B = ceil(sqrt(n));
    auto cmp = [&](const el a, const el b){
        if(a.left / B == b.left / B){
            return a.right < b.right;
        }
        return a.left / B < b.left / B;
    };
    sort(qs.begin(), qs.end(), cmp);
    vector<long long> count(1'000'001, 0);
    long long l = 0, r = 0;
    count[tab[0]] = 1;
    long long ans = tab[0];
    for(auto& q: qs){
        while(r < q.right){
            r++;
            ans -= count[tab[r]] * count[tab[r]] * tab[r];
            count[tab[r]]++;
            ans += count[tab[r]] * count[tab[r]] * tab[r];
        }
        while(r > q.right){
            ans -= count[tab[r]] * count[tab[r]] * tab[r];
            count[tab[r]]--;
            ans += count[tab[r]] * count[tab[r]] * tab[r];
            r--;
        }
        while(l < q.left){
            ans -= count[tab[l]] * count[tab[l]] * tab[l];
            count[tab[l]]--;
            ans += count[tab[l]] * count[tab[l]] * tab[l];
            l++;
        }
        while(l > q.left){
            l--;
            ans -= count[tab[l]] * count[tab[l]] * tab[l];
            count[tab[l]]++;
            ans += count[tab[l]] * count[tab[l]] * tab[l];
        }
        q.ans = ans;
    }
    sort(qs.begin(), qs.end(), [&](const el a, const el b) { return a.index < b.index; });
    for(auto& q : qs)
        cout << q.ans << endl;
}