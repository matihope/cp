#include <bits/stdc++.h>

using namespace std;

vector<int> minis(1001, 1000000001);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    struct el{ int val, cost; };

    minis[1] = 0;
    for(int i = 1; i <= 1000; ++i)
        for(int j = 1; j <= i; ++j)
            if(i + i / j <= 1000)
                minis[i + i / j] = min(minis[i + i / j], minis[i] + 1);

    int t;
    cin >> t;
    while(t--){
        int n, k, gained = 0;
        cin >> n >> k;
        vector<el> tab(n);
        for(auto& e: tab) cin >> e.val;
        for(auto& e: tab) cin >> e.cost;
        
        if(k >= n * 12){
            for(auto& e: tab) gained += e.cost;
        } else {
            vector<int> dp(k + 1, 0);
            for(auto& e: tab)
                for(int i = k; i >= minis[e.val]; i--)
                    dp[i] = max(dp[i], dp[i - minis[e.val]] + e.cost);
            gained = dp[k];
        }
        cout << gained << endl;
    }
}